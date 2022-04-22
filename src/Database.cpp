#include "Database.hpp"

void Database::addPlane(Plane *plane)
{
    _Planes.push_back(plane);
}

unsigned Database::getPlaneCount() const
{
    return _Planes.size();
}

Plane *Database::getPlane(const unsigned index) const
{
    if (index < _Planes.size())
        return _Planes[index];
    else
        return nullptr;
}

void Database::clear()
{
    for (size_t i = 0; i < _Planes.size(); i++)
    {
        delete _Planes[i];
    }
}

void Database::printInfo() const
{
    printf("Database contains %ld planes: \n", _Planes.size());
    for (size_t i = 0; i < _Planes.size(); i++)
    {
        printf("Plane %ld: \n", i);
        _Planes[i]->printInfo();
        printf("\n");
    }
}

bool Database::contains(const Plane &plane) const
{
    for (size_t i = 0; i < _Planes.size(); i++)
    {
        if (_Planes[i] == &plane)
            return true;
    }
    return false;
}

bool Database::fill(const bool reloadFile)
{
    // Gets the lastest information from the web API
    if (reloadFile)
        system("curl -s https://opensky-network.org/api/states/all | python3 -m json.tool > file.json");
    
    FILE *fp = fopen("file.json", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return false;
    }

    char line[128];

    // Extract the timestamp from the file
    if (fgets(line, sizeof(line), fp) != NULL)
    {
        fgets(line, sizeof(line), fp);
    }
    else
    {
        cout << "Error reading file" << endl;
        return false;
    }

    // Splits the line
    char *token = strtok(line, " ");        //extracts the word "time"
    token = strtok(NULL, " ");       //extracts the time
    token[strlen(token) - 2] = '\0';      //removes the last two characters
    printf("Current timestamp : %s \n\n", token);

    // Skips the first [
    unsigned nbPlanes = 0;
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        printf("error \n");
        return false;
    }

    do
    {
        // Extracts the plane's data
        char data[18][128];

        fgets(line, sizeof(line), fp); // Skips the first [
        for (int i = 0; i < 18; i++)
        {
            fgets(line, sizeof(line), fp);
            strncpy(data[i], line, sizeof(line));
        }

        fgets(line, sizeof(line), fp); // Skips the last ]

        // Affects the data to the plane
        Plane *plane = new Plane();
        //FIXME: Remove the '\n' at the end of the string
        plane->setID(strtok(data[0], " "));
        plane->setCallSign(strtok(data[1], " ")); 
        plane->setOriginCountry(strtok(data[2], " ")); //FIXME: Country with two words (e.g. "United States") is not handled
        plane->setLastUpdate(strncmp(data[3], "null", sizeof("null")) == 0 ? 999 : atoi(data[3]));
        plane->setLastContact(atoi(data[4]));
        plane->setLongitude(strncmp(data[5], "null", sizeof("null")) == 0 ? 999 : atof(data[5]));
        plane->setLatitude(strncmp(data[6], "null", sizeof("null")) == 0 ? 999 : atof(data[6]));
        plane->setBaroAltitude(strncmp(data[7], "null", sizeof("null")) == 0 ? -1 : atof(data[7]));
        plane->setIsGrounded(strncmp(data[8], "true", sizeof("true")) == 0 ? true : false);
        plane->setGroundVelocity(strncmp(data[9], "null", sizeof("null")) == 0 ? -1 : atof(data[9]));
        plane->setAngle(strncmp(data[10], "null", sizeof("null")) == 0 ? 999 : atof(data[10]));
        plane->setVerticalVelocity(strncmp(data[11], "null", sizeof("null")) == 0 ? 999 : atof(data[11]));
        plane->setGeoAltitude(strncmp(data[13], "null", sizeof("null")) == 0 ? -1 : atof(data[12]));
        plane->setSquawk(strtok(data[14], " "));
        plane->setIsSPI(strncmp(data[15], "true", sizeof("true")) == 0 ? true : false);
        plane->setSource((source)atoi(data[16]));

        //FIXME: make sure the plane is not already in the database, and if it is, update it instead of adding a new one
        // Adds the plane to the database
        _Planes.push_back(plane);

    } while (strncmp(line, "        ]\n", strlen("        ]\n")) != 0); //make sure we are at the end of the file
    
    printf("Read %u planes\n", _Planes.size());
    fclose(fp);
    return true;
}

Database::~Database()
{
    clear();
}
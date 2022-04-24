#include "Database.hpp"

Database::Database()
{
}

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

unsigned Database::getTimeStamp() const
{
    return _TimeStamp;
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
    if (fp == nullptr)
    {
        cout << "Error opening file" << endl;
        return false;
    }

    char line[128];

    // Extract the timestamp from the file
    if (fgets(line, sizeof(line), fp) != nullptr)
    {
        fgets(line, sizeof(line), fp);
    }
    else
    {
        cout << "Error reading file" << endl;
        return false;
    }

    // Splits the line
    line[strlen(line) - 2] = '\0';      //removes the last two characters
    _TimeStamp = atoi(line + 12);       //extracts the timestamp

    // Skips the first [
    if (fgets(line, sizeof(line), fp) == nullptr)
    {
        printf("error \n");
        return false;
    }

    do
    {
        // Extracts the plane's data
        char data[18][64];
        fgets(line, sizeof(line), fp); // Skips the first [
        for (int i = 0; i < 18; i++)
        {
            fgets(line, sizeof(line), fp);
            strncpy(data[i], line, sizeof(line));
        }
        fgets(line, sizeof(line), fp); // Skips the last ]

        // Creates the plane
        Plane *plane = new Plane();

        // Affects the ID
        data[0][strlen(data[0]) - 3] = '\0';
        plane->setID(data[0] + 13);

        // Affects the Callsign
        data[1][strlen(data[1]) - 3] = '\0';
        plane->setCallSign(data[1] + 13);
        
        // Affects the origin country
        data[2][strlen(data[2]) - 3] = '\0';
        plane->setOriginCountry(data[2] + 13);

        // Affects last update
        plane->setLastUpdate(strncmp(data[3], "null", sizeof("null")) == 0 ? 999 : atoi(data[3]));

        // Affects last contact
        plane->setLastContact(atoi(data[4]));

        // Affects the longitude
        plane->setLongitude(strncmp(data[5], "null", sizeof("null")) == 0 ? 999 : atof(data[5]));

        // Affects the latitude
        plane->setLatitude(strncmp(data[6], "null", sizeof("null")) == 0 ? 999 : atof(data[6]));

        // Affects the barometric altitude
        plane->setBaroAltitude(strncmp(data[7], "null", sizeof("null")) == 0 ? -1 : atof(data[7]));

        // Affects the on-ground flag
        plane->setIsGrounded(strncmp(data[8], "true,\n", sizeof("true,\n")) == 0 ? true : false);

        // Affects the ground velocity
        plane->setGroundVelocity(strncmp(data[9], "null", sizeof("null")) == 0 ? -1 : atof(data[9]));

        // Affects the true track i.e. the direction the plane is heading
        plane->setAngle(strncmp(data[10], "null", sizeof("null")) == 0 ? 999 : atof(data[10]));

        // Affects the vertical rate
        plane->setVerticalVelocity(strncmp(data[11], "null", sizeof("null")) == 0 ? 999 : atof(data[11]));

        // Affects the geo altitude
        plane->setGeoAltitude(strncmp(data[13], "null", sizeof("null")) == 0 ? -1 : atof(data[12]));

        // Affects the squawk
        data[14][strlen(data[14]) - 3] = '\0';
        plane->setSquawk(data[14] + 13);

        // Affects the Spi flag
        plane->setIsSPI(strncmp(data[15], "true", sizeof("true")) == 0 ? true : false);

        // Affects the source of the data
        plane->setSource((source)atoi(data[16]));

        //FIXME: make sure the plane is not already in the database, and if it is, update it instead of adding a new one
        // Adds the plane to the database
        _Planes.push_back(plane);

    } while (strncmp(line, "        ]\n", sizeof("        ]\n")) != 0); //make sure we are at the end of the file
    
    fclose(fp);
    printf("End of file. Read %lu planes from file.\n", _Planes.size());
    return true;
}

Database::~Database()
{
    clear();
}
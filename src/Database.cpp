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
        Plane plane;

        fgets(line, sizeof(line), fp); // Skips the first [
        for (int i = 0; i < 18; i++)
        {
            fgets(line, sizeof(line), fp);
            printf("%s", line);
            strncpy(data[i], line, sizeof(line));
        }

        fgets(line, sizeof(line), fp); // Skips the last ]
        printf("\n");
        _Planes.push_back(&plane);
    } while (strncmp(line, "        ]\n", strlen("        ]\n")) != 0); //make sure we are at the end of the file
    
    printf("Read %u planes\n", _Planes.size());
    fclose(fp);
    return true;
}
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

bool Database::fill(const string &file, const unsigned nbLine)
{
    FILE *fp = fopen("database/database.csv", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return false;
    }

    char line[256];
    unsigned line_number = 0;

    while ((fgets(line, sizeof(line), fp) != nullptr) && (line_number < nbLine))
    {
        line_number++;
        int nb_token = 0;
        char *token = strtok(line, ",");
        char token_array[16][256];
        while(token)
        {
            strcpy(token_array[nb_token++], token);
            token = strtok(NULL, ",");
        }
        if (nb_token != 16)
        {
            cout << "Error in line " << line_number << endl;
        }

        //TODO: extract the data from the line and create a plane

        printf("\n\n");
    }
    fclose(fp);
    return true;
}
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
    printf("Database contains %d planes: \n", _Planes.size());
    for (size_t i = 0; i < _Planes.size(); i++)
    {
        printf("Plane %d: \n", i);
        _Planes[i]->printInfo();
        printf("\n");
    }
}
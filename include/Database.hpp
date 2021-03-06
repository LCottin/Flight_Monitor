/**************************
 *     DATABASE CLASS     *
 **************************/

#ifndef __DATABASE__
#define __DATABASE__

#include <cstring>
#include <vector>

#include "Plane.hpp"

using namespace std;

class Database 
{
    private:
        vector<Plane*> _Planes;
        unsigned _TimeStamp;

    public:
        Database();
        ~Database();

        // =================== //
        //       Setters       //
        // =================== //
        /**
         * @brief Adds a plane to the database
         * @param plane A pointer of plane to add
         */
        void addPlane(Plane *plane);

        // =================== //
        //       Getters       //
        // =================== //
        /**
         * @brief Returns the number of planes in the database
         */
        unsigned getPlaneCount() const;

        /**
         * @brief Returns a pointer of a plane
         * @param index The index of the plane
         * @return A pointer of a plane or nullptr if the index is out of range
         */
        Plane *getPlane(const unsigned index) const;

        /**
         * @brief Returns the timestamp of the database
         */
        unsigned getTimeStamp() const;

        // =================== //
        //        Others       //
        // =================== //
        /**
         * @brief Clears the database
         */
        void clear();

        /**
         * @brief Prints the database
         */
        void printInfo() const;

        /**
         * @brief Tells if a plane is in the database
         * @param plane The plane to check
         * @return True if the plane is in the database, false otherwise
         */
        bool contains(const Plane &plane) const;

        /**
         * @brief Fills the database with a file
         * @param maxPlanes The maximum number of planes to load, -1 for no limit
         * @param reloadFile If true (default), the file is reloaded
         * @return True if everything went well, false otherwise
         */
        bool fill(const int maxPlanes, const bool reloadFile = true);
};

#endif
/***************************
 *       DATABSE CLASS     *
 ***************************/

#ifndef __DATABASE__
#define __DATABASE__

#include <iostream>
#include <string>
#include <vector>
#include "Plane.hpp"

using namespace std;

class Database 
{
    private:
        vector<Plane*> _Planes;

    public:
        // =================== //
        //        Setters      //
        // =================== //
        /**
         * @brief Adds a plane to the database
         * @param plane A pointer of plane to add
         */
        void addPlane(Plane *plane);

        // =================== //
        //        Getters      //
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

        // =================== //
        //         Others      //
        // =================== //
        /**
         * @brief Clears the database
         */
        void clear();

        /**
         * @brief Prints the database
         */
        void printInfo() const;
};

#endif
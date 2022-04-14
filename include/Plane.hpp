#ifndef __PLANE__
#define __PLANE__

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Plane
{
    private:
        double _Latitude;
        double _Longitude;
        double _GroundVelocity;
        double _VerticalVelocity;
        double _GPSAltitude;
        double _BaroAltitude;
        double _Heading;
        double _LastPost;
        double _LastContact;

        string _ID;
        string _Squawk;
        string _CallSign;

        bool _IsGrounded;
        bool _IsAlerted;
        bool _IsSPI;

    public:
        Plane(const string &id);
        Plane(const char *id);

        // =================== //
        //        Setters      //   
        // =================== //
        /**
         * @brief Changes the latitude of the plane
         * @param latitude The new latitude
         */
        void setLatitude(const double latitude);

        /**
         * @brief Changes the longitude of the plane
         * @param longitude The new longitude
         */
        void setLongitude(const double longitude);

        /**
         * @brief Changes the position of the plane
         * @param latitude The new latitude
         * @param longitude The new longitude
         */ 
        void setPosition(const double latitude, const double longitude);

        /**
         * @brief Changes the ground velocity of the plane
         * @param groundVelocity The new ground velocity
         */
        void setGroundVelocity(const double groundVelocity);

        /**
         * @brief Changes the vertical velocity of the plane
         * @param verticalVelocity The new vertical velocity
         */
        void setVerticalVelocity(const double verticalVelocity);

        /**
         * @brief Changes the GPS altitude of the plane
         * @param gpsAltitude The new GPS altitude
         */
        void setGPSAltitude(const double gpsAltitude);

        /**
         * @brief Changes the barometric altitude of the plane
         * @param baroAltitude The new barometric altitude
         */
        void setBaroAltitude(const double baroAltitude);

        /**
         * @brief Changes the heading of the plane
         * @param heading The new heading
         */
        void setHeading(const double heading);

        /**
         * @brief Changes the last post of the plane
         * @param lastPost The new last post
         */
        void setLastPost(const double lastPost);

        /**
         * @brief Changes the last contact of the plane
         * @param lastContact The new last contact
         */
        void setLastContact(const double lastContact);

        /**
         * @brief Changes the ID of the plane
         * @param id The new ID
         */
        void setID(const string &id);
        void setID(const char *id);

        /**
         * @brief Changes the squawk of the plane
         * @param squawk The new squawk
         */
        void setSquawk(const string &squawk);
        void setSquawk(const char *squawk);

        /**
         * @brief Changes the callsign of the plane
         * @param callsign The new callsign
         */
        void setCallSign(const string &callsign);
        void setCallSign(const char *callsign);

        /**
         * @brief Changes the grounded status of the plane
         * @param isGrounded The new grounded status
         */
        void setIsGrounded(const bool isGrounded);

        /**
         * @brief Changes the alerted status of the plane
         * @param isAlerted The new alerted status
         */
        void setIsAlerted(const bool isAlerted);

        /**
         * @brief Changes the SPI status of the plane
         * @param isSPI The new SPI status
         */
        void setIsSPI(const bool isSPI);

        // =================== //
        //        Getters      //
        // =================== //
        /**
         * @brief Returns the latitude of the plane
         */
        double getLatitude() const;

        /**
         * @brief Returns the longitude of the plane
         */
        double getLongitude() const;

        /**
         * @brief Returns the ground velocity of the plane
         */
        double getGroundVelocity() const;

        /**
         * @brief Returns the vertical velocity of the plane
         */
        double getVerticalVelocity() const;

        /**
         * @brief Returns the GPS altitude of the plane
         */
        double getGPSAltitude() const;

        /**
         * @brief Returns the barometric altitude of the plane
         */
        double getBaroAltitude() const;

        /**
         * @brief Returns the heading of the plane
         */
        double getHeading() const;

        /**
         * @brief Returns the last post of the plane
         */
        double getLastPost() const;

        /**
         * @brief Returns the last contact of the plane
         */
        double getLastContact() const;

        /**
         * @brief Returns the ID of the plane
         */
        string getID() const;

        /**
         * @brief Returns the squawk of the plane
         */
        string getSquawk() const;

        /**
         * @brief Returns the callsign of the plane
         */
        string getCallSign() const;

        /**
         * @brief Returns the grounded status of the plane
         */
        bool getIsGrounded() const;

        /**
         * @brief Returns the alerted status of the plane
         */
        bool getIsAlerted() const;

        /**
         * @brief Returns the SPI status of the plane
         */
        bool getIsSPI() const;

        // =================== //
        //        Others       //
        // =================== // 
        /**
         * @brief Returns the distance between the plane and the given position
         * @param latitude The latitude of the position
         * @param longitude The longitude of the position
         * @return The distance 
         */
        double getDistanceFrom(const double latitude, const double longitude) const;

        /**
         * @brief Returns the distance between the plane and the other plane
         * @param plane The other plane
         * @return The distance
         */
        double getDistanceFrom(const Plane &plane) const;

        /**
         * @brief Prints info about the plane
         */
        void printInfo() const;
};

#endif
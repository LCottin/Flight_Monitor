/**************************
 *       PLANE CLASS      *
 **************************/

#ifndef __PLANE__
#define __PLANE__

#include <string>
#include <iostream>
#include <cmath>

#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

typedef enum
{
    ADS_B,
    ASTERIX,
    MLAT
} source;

class Plane
{
    private:
        string _ID;
        string _Squawk;
        string _CallSign;
        string _OriginCountry;

        source _Source;

        unsigned _LastUpdate;
        unsigned _LastContact;

        double _Angle;
        double _Latitude;
        double _Longitude;
        double _GeoAltitude;
        double _BaroAltitude;
        double _GroundVelocity;
        double _VerticalVelocity;

        bool _IsSPI;
        bool _IsGrounded;
        bool _IsSelected;

        Sprite _Sprite;
        Texture _Texture;

    public:
        Plane();
        bool operator==(const Plane &plane) const;

        // =================== //
        //       Setters       //
        // =================== //
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
         * @brief Changes the origin country of the plane
         * @param originCountry The new origin country
         */
        void setOriginCountry(const string &originCountry);
        void setOriginCountry(const char *originCountry);

        /**
         * @brief Changes the source of the plane
         * @param source The new source
         */ 
        void setSource(const source &source);

        /**
         * @brief Changes the last post of the plane
         * @param lastUpdate The new last update
         */
        void setLastUpdate(const unsigned lastUpdate);

        /**
         * @brief Changes the last contact of the plane
         * @param lastContact The new last contact
         */
        void setLastContact(const unsigned lastContact);

        /**
         * @brief Changes the angle of the plane
         * @param angle The new angle
         */
        void setAngle(const double angle);

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
         * @brief Changes the GPS altitude of the plane
         * @param gpsAltitude The new GPS altitude
         */
        void setGeoAltitude(const double geoAltitude);

        /**
         * @brief Changes the barometric altitude of the plane
         * @param baroAltitude The new barometric altitude
         */
        void setBaroAltitude(const double baroAltitude);

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
         * @brief Changes the SPI status of the plane
         * @param isSPI The new SPI status
         */
        void setIsSPI(const bool isSPI);

        /**
         * @brief Changes the grounded status of the plane
         * @param isGrounded The new grounded status
         */
        void setIsGrounded(const bool isGrounded);

        /**
         * @brief Selects the plane
         * @param isSelected The new selected status
         */
        void setIsSelected(const bool isSelected);

        // =================== //
        //       Getters       //
        // =================== //
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
         * @brief Returns the origin country of the plane
         */
        string getOriginCountry() const;

        /**
         * @brief Returns the source of the plane
         */
        source getSource() const;

        /**
         * @brief Returns the last post of the plane
         */
        unsigned getLastUpdate() const;

        /**
         * @brief Returns the last contact of the plane
         */
        unsigned getLastContact() const;

        /**
         * @brief Returns the angle of the plane
         */
        double getAngle() const;

        /**
         * @brief Returns the latitude of the plane
         */
        double getLatitude() const;

        /**
         * @brief Returns the longitude of the plane
         */
        double getLongitude() const;

        /**
         * @brief Returns the GPS altitude of the plane
         */
        double getGeoAltitude() const;

        /**
         * @brief Returns the barometric altitude of the plane
         */
        double getBaroAltitude() const;

        /**
         * @brief Returns the ground velocity of the plane
         */
        double getGroundVelocity() const;

        /**
         * @brief Returns the vertical velocity of the plane
         */
        double getVerticalVelocity() const;

        /**
         * @brief Returns the SPI status of the plane
         */
        bool isSPI() const;
        
        /**
         * @brief Returns the grounded status of the plane
         */
        bool isGrounded() const;

        /**
         * @brief Indicates if the plane is selected
         */
        bool isSelected() const;

        /**
         * @brief Returns the sprite of the plane
         */
        Sprite getSprite() const;

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
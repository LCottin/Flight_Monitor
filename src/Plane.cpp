#include "Plane.hpp"

Plane::Plane(const string &id)
{
    _ID = id;
}

Plane::Plane(const char *id)
{
    _ID = id;
}

void Plane::setLatitude(const double latitude)
{
    _Latitude = latitude;
}

void Plane::setLongitude(const double longitude)
{
    _Longitude = longitude;
}

void Plane::setPosition(const double latitude, const double longitude)
{
    _Latitude = latitude;
    _Longitude = longitude;
}

void Plane::setGroundVelocity(const double groundVelocity)
{
    _GroundVelocity = groundVelocity;
}

void Plane::setVerticalVelocity(const double verticalVelocity)
{
    _VerticalVelocity = verticalVelocity;
}

void Plane::setGPSAltitude(const double gpsAltitude)
{
    _GPSAltitude = gpsAltitude;
}

void Plane::setBaroAltitude(const double baroAltitude)
{
    _BaroAltitude = baroAltitude;
}

void Plane::setHeading(const double heading)
{
    _Heading = heading;
}

void Plane::setLastPost(const double lastPost)
{
    _LastPost = lastPost;
}

void Plane::setLastContact(const double lastContact)
{
    _LastContact = lastContact;
}

void Plane::setID(const string &id)
{
    _ID = id;
}

void Plane::setID(const char *id)
{
    _ID = string(id);
}

void Plane::setSquawk(const string &squawk)
{
    _Squawk = squawk;
}

void Plane::setSquawk(const char *squawk)
{
    _Squawk = string(squawk);
}

void Plane::setCallSign(const string &callsign)
{
    _CallSign = callsign;
}

void Plane::setCallSign(const char *callsign)
{
    _CallSign = string(callsign);
}

void Plane::setIsGrounded(const bool isGrounded)
{
    _IsGrounded = isGrounded;
}

void Plane::setIsAlerted(const bool isAlerted)
{
    _IsAlerted = isAlerted;
}

void Plane::setIsSPI(const bool isSPI)
{
    _IsSPI = isSPI;
}

double Plane::getLatitude() const
{
    return _Latitude;
}

double Plane::getLongitude() const
{
    return _Longitude;
}

double Plane::getGroundVelocity() const
{
    return _GroundVelocity;
}

double Plane::getVerticalVelocity() const
{
    return _VerticalVelocity;
}

double Plane::getGPSAltitude() const
{
    return _GPSAltitude;
}

double Plane::getBaroAltitude() const
{
    return _BaroAltitude;
}

double Plane::getHeading() const
{
    return _Heading;
}

double Plane::getLastPost() const
{
    return _LastPost;
}

double Plane::getLastContact() const
{
    return _LastContact;
}

string Plane::getID() const
{
    return _ID;
}

string Plane::getSquawk() const
{
    return _Squawk;
}

string Plane::getCallSign() const
{
    return _CallSign;
}

bool Plane::getIsGrounded() const
{
    return _IsGrounded;
}

bool Plane::getIsAlerted() const
{
    return _IsAlerted;
}

bool Plane::getIsSPI() const
{
    return _IsSPI;
}
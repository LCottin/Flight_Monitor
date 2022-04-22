#include "Plane.hpp"

Plane::Plane(const string &id, const string &squawk, const string &callSign)
{
    _ID         = id;
    _Squawk     = squawk;
    _CallSign   = callSign;
}

Plane::Plane(const char *id, const char *squawk, const char *callSign)
{
    _ID         = string(id);
    _Squawk     = string(squawk);
    _CallSign   = string(callSign);
}

bool Plane::operator==(const Plane &plane) const
{
    // ID, Squawk and CallSign are unique and define a plane
    return ((_ID == plane._ID) && (_Squawk == plane._Squawk) && (_CallSign == plane._CallSign));
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

void Plane::setGeoAltitude(const double gpsAltitude)
{
    _GeoAltitude = gpsAltitude;
}

void Plane::setBaroAltitude(const double baroAltitude)
{
    _BaroAltitude = baroAltitude;
}

void Plane::setLastUpdate(const double lastUpdate)
{
    _LastUpdate = lastUpdate;
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

void Plane::setIsSPI(const bool isSPI)
{
    _IsSPI = isSPI;
}

void Plane::setIsSelected(const bool isSelected)
{
    _IsSelected = isSelected;
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

double Plane::getGeoAltitude() const
{
    return _GeoAltitude;
}

double Plane::getBaroAltitude() const
{
    return _BaroAltitude;
}

double Plane::getLastUpdate() const
{
    return _LastUpdate;
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

bool Plane::isGrounded() const
{
    return _IsGrounded;
}

bool Plane::isSPI() const
{
    return _IsSPI;
}

double Plane::getDistanceFrom(const double latitude, const double longitude) const
{
    double dLat = latitude - _Latitude;
    double dLon = longitude - _Longitude;

    return sqrt(dLat * dLat + dLon * dLon);
}

double Plane::getDistanceFrom(const Plane &plane) const
{
    return getDistanceFrom(plane.getLatitude(), plane.getLongitude());
}

bool Plane::isSelected() const
{
    return _IsSelected;
}

void Plane::printInfo() const
{
    cout << "======================================" << endl;
    printf("ID:                 %s\n", _ID.c_str());
    printf("Is grounded:        %s\n", _IsGrounded ? "True":"False");
    printf("Latitude:           %lf\n", _Latitude);
    printf("Longitude:          %lf\n", _Longitude);
    printf("Ground velocity:    %lf\n", _GroundVelocity);
    printf("Vertical velocity:  %lf\n", _VerticalVelocity);
    printf("GPS altitude:       %lf\n", _GeoAltitude);
    printf("Baro altitude:      %lf\n", _BaroAltitude);
    printf("Last update:        %u\n", _LastUpdate);
    printf("Last contact:       %u\n", _LastContact);
    printf("Squawk:             %s\n", _Squawk.c_str());
    printf("Call sign:          %s\n", _CallSign.c_str());
    printf("Is SPI:             %s\n", _IsSPI ? "True":"False");
    printf("Is selected:        %s\n", _IsSelected ? "True":"False");
    cout << "======================================\n" << endl;
}
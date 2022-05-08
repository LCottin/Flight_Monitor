#include "Plane.hpp"

static double scaler(double value, double fromLow, double fromHigh, double toLow, double toHigh)
{
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

Plane::Plane()
{
    if (_Texture.loadFromFile(PLANE_TEXTURE) == false)
    {
        printf("Error: Could not load the plane image\n");
        return;
    }
    _Sprite.setTexture(_Texture);
    _Sprite.setScale(Vector2f(PLANE_SCALE, PLANE_SCALE));
}

bool Plane::operator==(const Plane &plane) const
{
    // ID, Squawk and CallSign are unique and define a plane
    return ((_ID == plane._ID) && (_Squawk == plane._Squawk) && 
            (_CallSign == plane._CallSign) && (_OriginCountry == plane._OriginCountry));
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

void Plane::setOriginCountry(const string &originCountry)
{
    _OriginCountry = originCountry;
}

void Plane::setOriginCountry(const char *originCountry)
{
    _OriginCountry = string(originCountry);
}

void Plane::setSource(const source &source)
{
    _Source = source;
}

void Plane::setLastUpdate(const unsigned lastUpdate)
{
    _LastUpdate = lastUpdate;
}

void Plane::setLastContact(const unsigned lastContact)
{
    _LastContact = lastContact;
}

void Plane::setAngle(const double angle)
{
    _Angle = angle;
}

void Plane::setLatitude(const double latitude)
{
    _Latitude   = latitude;
    _Sprite.setPosition(Vector2f(scaler(_Latitude, -90, 90, 0, IMG_WIDTH), _Sprite.getPosition().y));
}

void Plane::setLongitude(const double longitude)
{
    _Longitude = longitude;
    _Sprite.setPosition(Vector2f(_Sprite.getPosition().x, scaler(_Longitude, -180, 180, 0, IMG_HEIGHT)));
}

void Plane::setPosition(const double latitude, const double longitude)
{
    _Latitude  = latitude;
    _Longitude = longitude;
    _Sprite.setPosition(Vector2f(scaler(_Latitude, -90, 90, 0, IMG_WIDTH), scaler(_Longitude, -180, 180, 0, IMG_HEIGHT)));
}

void Plane::setGeoAltitude(const double geoAltitude)
{
    _GeoAltitude = geoAltitude;
}

void Plane::setBaroAltitude(const double baroAltitude)
{
    _BaroAltitude = baroAltitude;
}

void Plane::setGroundVelocity(const double groundVelocity)
{
    _GroundVelocity = groundVelocity;
}

void Plane::setVerticalVelocity(const double verticalVelocity)
{
    _VerticalVelocity = verticalVelocity;
}

void Plane::setIsSPI(const bool isSPI)
{
    _IsSPI = isSPI;
}

void Plane::setIsGrounded(const bool isGrounded)
{
    _IsGrounded = isGrounded;
}

void Plane::setIsSelected(const bool isSelected)
{
    _IsSelected = isSelected;
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

string Plane::getOriginCountry() const
{
    return _OriginCountry;
}

source Plane::getSource() const
{
    return _Source;
}

unsigned Plane::getLastUpdate() const
{
    return _LastUpdate;
}

unsigned Plane::getLastContact() const
{
    return _LastContact;
}

double Plane::getAngle() const
{
    return _Angle;
}

double Plane::getLatitude() const
{
    return _Latitude;
}

double Plane::getLongitude() const
{
    return _Longitude;
}

double Plane::getGeoAltitude() const
{
    return _GeoAltitude;
}

double Plane::getBaroAltitude() const
{
    return _BaroAltitude;
}

double Plane::getGroundVelocity() const
{
    return _GroundVelocity;
}

double Plane::getVerticalVelocity() const
{
    return _VerticalVelocity;
}

bool Plane::isSPI() const
{
    return _IsSPI;
}

bool Plane::isGrounded() const
{
    return _IsGrounded;
}

bool Plane::isSelected() const
{
    return _IsSelected;
}

Sprite Plane::getSprite() const
{
    return _Sprite;
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

void Plane::printInfo() const
{
    cout << "======================================" << endl;
    printf("ID:                 %s\n", _ID.c_str());
    printf("Squawk:             %s\n", _Squawk.c_str());
    printf("Call sign:          %s\n", _CallSign.c_str());
    printf("Origin country:     %s\n", _OriginCountry.c_str());
    printf("Source :            %s\n", _Source == 0 ? "ADS-B" : (_Source == 1 ? "ASTERIX" : "MLAT") );
    printf("Last update:        %u\n", _LastUpdate);
    printf("Last contact:       %u\n", _LastContact);
    printf("Angle:              %.2f\n", _Angle);
    printf("Latitude:           %lf\n", _Latitude);
    printf("Longitude:          %lf\n", _Longitude);
    printf("GPS altitude:       %lf\n", _GeoAltitude);
    printf("Baro altitude:      %lf\n", _BaroAltitude);
    printf("Ground velocity:    %lf\n", _GroundVelocity);
    printf("Vertical velocity:  %lf\n", _VerticalVelocity);
    printf("Is SPI:             %s\n", _IsSPI ? "True":"False");
    printf("Is grounded:        %s\n", _IsGrounded ? "True":"False");
    printf("Is selected:        %s\n", _IsSelected ? "True":"False");
    cout << "======================================\n" << endl;
}
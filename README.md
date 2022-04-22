# Flight_Monitor

The purpose of this personnal project is to create a interface to track plane like flyradar24.com or globe.adsbexchange.com.

Data come from the web site The OpenSky Network (https://opensky-network.org).
To get the data, I use the API and the command

```
curl -s "https://opensky-network.org/api/states/all" | python3 -m json.tool
```

Without an account, the data is only available every ten seconds. Information about a plane is organized in a JSON file as follows :

- **icao24** *(string)* : Unique ICAO 24-bit address of the transponder in hex string representation.

- **callsign** *(string)* : Callsign of the vehicle (8 chars). Can be null if no callsign has been received.

- **origin_country** *(string)* : Country name inferred from the ICAO 24-bit address.

- **time_position** *(int)* : Unix timestamp (seconds) for the last position update. Can be null if no position report was received by OpenSky within the past 15s.

- **last_contact** *(int)* : Unix timestamp (seconds) for the last update in general. This field is updated for any new, valid message received from the transponder.

- **longitude** *(float)* : WGS-84 longitude in decimal degrees. Can be null.

- **latitude** *(float)* : WGS-84 latitude in decimal degrees. Can be null.

- **baro_altitude** *(float)* : Barometric altitude in meters. Can be null.

- **on_ground** *(bool)* : Boolean value which indicates if the position was retrieved from a surface position report.

- **velocity** *(float)* : Velocity over ground in m/s. Can be null.

- **true_track** *(float)* : True track in decimal degrees clockwise from north (north=0°). Can be null.

- **vertical_rate** *(float)* : Vertical rate in m/s. A positive value indicates that the airplane is climbing, a negative value indicates that it descends. Can be null.

- **sensors** *(int [])* : IDs of the receivers which contributed to this state vector. Is null if no filtering for sensor was used in the request.

- **geo_altitude** *(float)* Geometric altitude in meters. Can be null.

- **squawk** *(string)* : The transponder code aka Squawk. Can be null.

- **spi** *(bool)* : Whether flight status indicates special purpose indicator.

- **position_source** *(int)* : Origin of this state’s position: 0 = ADS-B, 1 = ASTERIX, 2 = MLAT


#### References: 
Matthias Schäfer, Martin Strohmeier, Vincent Lenders, Ivan Martinovic and Matthias Wilhelm.
"Bringing Up OpenSky: A Large-scale ADS-B Sensor Network for Research".
In Proceedings of the 13th IEEE/ACM International Symposium on Information Processing in Sensor Networks (IPSN), pages 83-94, April 2014.
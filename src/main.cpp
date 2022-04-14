/*******************************
 *          MAIN FILE          *
 *******************************/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Plane.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

    /*
    FILE *fp = fopen("database/database.csv", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return -1;
    }

    char line[256];
    unsigned line_number = 0;
    unsigned time;
    char id[6], squawk[4];
    double lat, lon, velo, heading, velo_ver, baro_alt, gps_alt, last_post, last_contact; 
    char ground[10], alert[10], spi[10], callsign[10];

    while (fgets(line, sizeof(line), fp) != NULL && line_number < 40)
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
        else
        {
            time = atoi(token_array[0]);
            strcpy(id, token_array[1]);
            lat = atof(token_array[2]);
            lon = atof(token_array[3]);
            velo = atof(token_array[4]);
            heading = atof(token_array[5]);
            velo_ver = atof(token_array[6]);
            strcpy(callsign, token_array[7]);
            strcpy(ground, token_array[8]);
            strcpy(alert, token_array[9]);
            strcpy(spi, token_array[10]);
            strcpy(squawk, token_array[11]);
            baro_alt = atof(token_array[12]);
            gps_alt = atof(token_array[13]);
            last_post = atof(token_array[14]);
            last_contact = atof(token_array[15]);
            cout << "time: " << time << endl;
            cout << "id: " << id << endl;
            cout << "lat: " << lat << endl;
            cout << "lon: " << lon << endl;
            cout << "velo: " << velo << endl;
            cout << "heading: " << heading << endl;
            cout << "velo_ver: " << velo_ver << endl;
            cout << "callsign: " << callsign << endl;
            cout << "ground: " << ground << endl;
            cout << "alert: " << alert << endl;
            cout << "spi: " << spi << endl;
            cout << "squawk: " << squawk << endl;
            cout << "baro_alt: " << baro_alt << endl;
            cout << "gps_alt: " << gps_alt << endl;
            cout << "last_post: " << last_post << endl;
            cout << "last_contact: " << last_contact << endl;
            cout << endl;
        }

        printf("\n\n");
    }
    
    fclose(fp);
    */

    Plane plane("r");

    // using each of the setters
    plane.setGroundVelocity(1.0);
    plane.setVerticalVelocity(2.0);
    plane.setGPSAltitude(3.0);
    plane.setBaroAltitude(4.0);
    plane.setHeading(5.0);
    plane.setLastPost(6.0);
    plane.setLastContact(7.0);
    plane.setID("8");
    plane.setSquawk("9");
    plane.setCallSign("10");
    plane.setIsGrounded(true);
    plane.setIsAlerted(true);
    plane.setIsSPI(true);
    plane.setLatitude(11.0);
    plane.setLongitude(12.0);

    // using the getters
    cout << "Ground velocity: " << plane.getGroundVelocity() << endl;
    cout << "Vertical velocity: " << plane.getVerticalVelocity() << endl;
    cout << "GPS altitude: " << plane.getGPSAltitude() << endl;
    cout << "Baro altitude: " << plane.getBaroAltitude() << endl;
    cout << "Heading: " << plane.getHeading() << endl;
    cout << "Last post: " << plane.getLastPost() << endl;
    cout << "Last contact: " << plane.getLastContact() << endl;
    cout << "ID: " << plane.getID() << endl;
    cout << "Squawk: " << plane.getSquawk() << endl;
    cout << "Call sign: " << plane.getCallSign() << endl;
    cout << "Is grounded: " << plane.getIsGrounded() << endl;
    cout << "Is alerted: " << plane.getIsAlerted() << endl;
    cout << "Is SPI: " << plane.getIsSPI() << endl;
    cout << "Latitude: " << plane.getLatitude() << endl;
    cout << "Longitude: " << plane.getLongitude() << endl;

    printf("\n");
    //using the geters with printf
    printf("Ground velocity: %lf\n", plane.getGroundVelocity());
    printf("Vertical velocity: %lf\n", plane.getVerticalVelocity());
    printf("GPS altitude: %lf\n", plane.getGPSAltitude());
    printf("Baro altitude: %lf\n", plane.getBaroAltitude());
    printf("Heading: %lf\n", plane.getHeading());
    printf("Last post: %lf\n", plane.getLastPost());
    printf("Last contact: %lf\n", plane.getLastContact());
    printf("ID: %s\n", plane.getID().c_str());
    printf("Squawk: %s\n", plane.getSquawk().c_str());
    printf("Call sign: %s\n", plane.getCallSign().c_str());
    printf("Is grounded: %s\n", plane.getIsGrounded() ? "True":"False");
    printf("Is alerted: %s\n", plane.getIsAlerted() ? "True":"False");
    printf("Is SPI: %s\n", plane.getIsSPI() ? "True":"False");
    printf("Latitude: %lf\n", plane.getLatitude());
    printf("Longitude: %lf\n", plane.getLongitude());

    printf("\n");
    plane.printInfo();
    
    return 0;
}
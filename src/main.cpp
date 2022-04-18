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
    cout << "Is grounded: " << plane.isGrounded() << endl;
    cout << "Is alerted: " << plane.isAlerted() << endl;
    cout << "Is SPI: " << plane.isSPI() << endl;
    cout << "Latitude: " << plane.getLatitude() << endl;
    cout << "Longitude: " << plane.getLongitude() << endl;

    printf("\n");
    plane.printInfo();
    
    return 0;
}
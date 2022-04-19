/*******************************
 *          MAIN FILE          *
 *******************************/

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Plane.hpp"
#include "Database.hpp"

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

    Plane plane("p1", "F-001", "ABCD");
    Plane plane2("p2", "F-002", "EFGH");

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

    plane2.setID("8");
    plane2.setSquawk("9");
    plane2.setCallSign("10");

    printf("\n");
    plane.printInfo();
    
    Database db;
    db.addPlane(&plane);
    db.addPlane(&plane2);
    db.printInfo();
    db.contains(plane);

    printf("%d\n", plane == plane2);

    return 0;
}
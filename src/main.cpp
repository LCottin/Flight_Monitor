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
    system("clear");
    FILE *fp = fopen("file.json", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        return -1;
    }

    char line[128];
    unsigned i = 0;

    if (fgets(line, sizeof(line), fp) != NULL)
    {
        // gets the time
        fgets(line, sizeof(line), fp);
        printf("%s", line);

        // splits the line
        char *token = strtok(line, " ");        //extracts the word "time"
        char *token2 = strtok(NULL, " ");       //extracts the time
        token2[strlen(token2) - 2] = '\0';      //removes the last two characters

        printf("%s \n%s\n", token, token2);
    }

    // skip the first [
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        printf("error \n");
        return -1;
    }

    do
    {
        i++;
        fgets(line, sizeof(line), fp); // skip the first [
        for (int i = 0; i < 18; i++)
        {
            fgets(line, sizeof(line), fp);
            printf("%s", line);
        }
        fgets(line, sizeof(line), fp); // skip the last ]
        printf("\n");
    } while (strncmp(line, "        ]\n", strlen("        ]\n")) != 0); //make sure we are at the end of the file
    
    printf("Read %d lines\n", i);
    fclose(fp);
    
    /*
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

    */
    return 0;
}
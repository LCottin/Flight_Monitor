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
    return 0;
}
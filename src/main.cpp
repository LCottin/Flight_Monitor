/*******************************
 *          MAIN FILE          *
 *******************************/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("database/database.csv", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    char line[256];
    unsigned line_number = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line_number++;
    }
    cout << line << endl;
    cout << line_number << endl;

    return 0;
}
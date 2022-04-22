/*******************************
 *          MAIN FILE          *
 *******************************/

#include "Plane.hpp"
#include "Database.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    system("clear");
    Database database;
    database.fill(false);
    database.printInfo();
    return 0;
}
/*******************************
 *          MAIN FILE          *
 *******************************/

#include "Display.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    system("clear");
    Database database;
    database.fill(999, false);
    Display display(database);
    display.show();
    return 0;
}
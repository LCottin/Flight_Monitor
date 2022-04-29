/*******************************
 *          MAIN FILE          *
 *******************************/

#include "Display.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    system("clear");
    Database database;
    database.fill(0, false);
    Display display(database);
    //display.show();

    // Prints sizes of every obejcts in the project
    cout << "Database: " << sizeof(database) << endl;
    cout << "Plane: " << sizeof(Plane) << endl;
    cout << "Display: " << sizeof(Display) << endl;
    cout << "Vector: " << sizeof(vector<Plane*>) << endl;
    cout << "Vector<Plane*>: " << sizeof(vector<Plane*>) << endl;

    return 0;
}
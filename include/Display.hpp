/**************************
 *      DISPLAY CLASS     *
 **************************/

#ifndef __DISPLAY__
#define __DISPLAY__

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Database.hpp"

using namespace sf;

class Display
{
    private:
        Database *_Database;

        RenderWindow _Window;
        Texture      _Background;
        Sprite       _BackgroundSprite;

    public:
        Display(Database &database);
        ~Display();

        /**
         * @brief Shows the window
         */
        void show();
};

#endif
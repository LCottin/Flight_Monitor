#include "Display.hpp"

Display::Display(Database &database)
{
    _Database = &database;

    _Window.create(VideoMode(900, 600), "Monitoring");
    if (_Background.loadFromFile("imgs/map.jpg") == false)
    {
        printf("Error: Could not load the background image\n");
        return;
    }
    _BackgroundSprite.setTexture(_Background);
}

void Display::show()
{
    while (_Window.isOpen())
    {
        Event event;
        while (_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                _Window.close();
        }

        _Window.clear();
        _Window.draw(_BackgroundSprite);
        _Window.display();
    }
}

Display::~Display()
{
}
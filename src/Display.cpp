#include "Display.hpp"

Display::Display(Database &database)
{
    _Database = &database;

    _Window.create(VideoMode(IMG_WIDTH, IMG_HEIGHT), "Monitoring");
    if (_Background.loadFromFile(IMG_NAME) == false)
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
        for (size_t i = 0; i < _Database->getPlaneCount(); i++)
        {
            //TODO: Draw the plane at the correct position on the map
            _Window.draw(_Database->getPlane(i)->getSprite());
        }
        _Window.display();
    }
}

Display::~Display()
{
}
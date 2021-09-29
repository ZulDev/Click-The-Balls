#include "Mouse.h"

Mouse::Mouse()
{
    //ctor
}

Mouse::~Mouse()
{
    //dtor
}

sf::Vector2i Mouse::getMousePos(sf::RenderWindow &window) {
    sf::Mouse::getPosition(window);
}

#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Mouse
{
    public:
        Mouse();
        virtual ~Mouse();

        sf::Vector2i getMousePos(sf::RenderWindow &window);

    private:
        sf::Vector2i mousePos;
        bool isClicked;


};

#endif // MOUSE_H

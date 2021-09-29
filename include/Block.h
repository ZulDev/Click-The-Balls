#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <iostream>

class Block
{
    public:
        Block(float radius); /// Constructor
        virtual ~Block();    /// Destructor

        /// Public Attribute
        const int ID;

        /// Public method.
        static float GenNum(int);

        ///bool isGettingClicked(Block* blocks);

        void move(float& dt, float& speed);
        void draw(sf::RenderWindow *window);
        sf::CircleShape& getShape();

    private:
        /// Private attribute.
        static int ID_BLOCK;

        float m_radius;
        int m_width,m_height; /// Width and Height the block.

        sf::CircleShape shape;

        /// Private method.
        void init_block_component();

};

#endif // BLOCK_H

#ifndef ENGINE_H
#define ENGINE_H

#define MAX_BLOCK 100

#include "Block.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Block; /// Memberitahukan bahwa ada class Block
            /// Gua gk tau jua kenapa. jadi jngn di delete ini.

class Engine
{
    public:
        /// Constructor and destructor
        Engine();
        Engine(int& width, int& height, std::string& Title_Game);


        virtual ~Engine();

        /// Public Attribute

        /// Public Method
        void run();

    private:
        /// private attribute
        sf::RenderWindow* window;
        sf::Event event;

        std::string m_title_game;
        int m_width, m_height;
        ///static int MAX_BLOCKS;
        sf::Clock clock;
        float dt, speed; /// Delta time and speed

        bool isClicked;
        sf::Music music;


        /// Private method.
        void init_window();
        void update_event();
        void clear_window();
        void draw(auto&);
        void display();

        void update_delta_time();

        sf::View resizeWindow();

        /// Another class method to call.
        Block* block[MAX_BLOCK];
        ///Block* block;
        void init_blocks();

        /// Method and attribt for initialize collision for mouse
        sf::CircleShape mouseCircleDOT;
        void init_mouse_circle_dot();
        void isBlockGettingClicked();
};

#endif // ENGINE_H

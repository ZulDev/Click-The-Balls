#include "Engine.h"

///int Engine::MAX_BLOCKS = 0;

/** Constructor */
Engine::Engine() /// Default constructor
: m_title_game("Default"), m_width(500), m_height(500), speed(10.0f)
{
    this->init_window(); /// call initialize window method
    this->init_blocks(); /// call initialize block method
    this->init_mouse_circle_dot(); /// call initialize mouse circle dot method;
}

Engine::Engine(int& width, int& height, std::string &Title_Game)
: m_title_game(Title_Game), m_width(width), m_height(height), speed(10.0f)
{
    this->init_window(); /// call initialize window method
    this->init_blocks(); /// call initialize block method
    this->init_mouse_circle_dot(); /// call initialize mouse circle dot method;
}

/** Destructor */
Engine::~Engine() {
    /// Deleting process
    delete this->window;
    for(int i = 0; i < MAX_BLOCK; i++) delete this->block[i];

    /// Null process
    window = nullptr;
    for(int i = 0;i < MAX_BLOCK;i++) this->block[i] = nullptr;
    std::cout << "Deleted window and block 0 ~ " << MAX_BLOCK << std::endl;
}

/** Public Method ( For running the game / main method ) */
void Engine::run() {
    while(this->window->isOpen())
    {
        this->update_event();

        this->update_delta_time();

        this->clear_window();


        ///if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->isBlockGettingClicked();

        this->draw(this->mouseCircleDOT);

        for(int i = 0; i < MAX_BLOCK; i++) {
            /// Cuman melakukan tugas dibawah jika block masih ada / tidak kosong (nullptr)
            if(this->block[i] != nullptr)
            {
                this->block[i]->move(this->dt,this->speed);
                ///this->block[i]->isCollision(engine());
                this->block[i]->draw(this->window);
            }
        }

        this->display();
    }
}

/** Initialize the window (This function just creating a window)*/
void Engine::init_window() {
    this->window = new sf::RenderWindow(sf::VideoMode(this->m_width,this->m_height),"Game");
    this->window->setFramerateLimit(60);
    /// Load Music.
    if(!music.openFromFile("SFX/explode.wav")) std::cerr << "Error, Can't load sfx!\n";
}

/** Check SFML update */
void Engine::update_event() {
    /** While the window get an event, it run below code */
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if(this->isClicked) {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->isBlockGettingClicked();
                    this->isClicked = false;
                }
                break;
            case sf::Event::MouseButtonReleased:
                this->isClicked = true;
                break;
            case sf::Event::MouseMoved:
                mouseCircleDOT.setPosition((float)sf::Mouse::getPosition(*this->window).x,(float)sf::Mouse::getPosition(*this->window).y);
                break;
            case sf::Event::Resized:
                this->window->setView(this->resizeWindow());
                break;
            default:
                break;
        }
    }

}

/** Clear the window every frame */
void Engine::clear_window() {
    this->window->clear();
}

/** Draw Something in window */
void Engine::draw(auto& gambar) {
    this->window->draw(gambar);
}

/** Display it into window */
void Engine::display() {
    this->window->display();
}

/** Updating delta time */
void Engine::update_delta_time() {
    ///if(this->dt > 120.0f) {clock.restart().asSeconds(); std::cout<< "TRigger bigger than 120fps\n";}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) std::cout << "FPS: " <<(int)1 / dt << std::endl;
    ///std::cout << "FPS: " <<(int)1 / dt << std::endl;
    this->dt = clock.restart().asSeconds();

}

sf::View Engine::resizeWindow() {
    float width = this->window->getSize().x;
    float height = this->window->getSize().y;

    ///std::cout << "width  : " << width << std::endl;
    ///std::cout << "height : " << height << std::endl;

    sf::Vector2f center = sf::Vector2f(width/2,height/2);

    ///std::cout << "center x : " << center.x << std::endl;
    ///std::cout << "center y : " << center.y << std::endl;

    sf::View view(center,sf::Vector2f(width,height));


    return view;
}

/** Initialize and assigment value into it*/
void Engine::init_blocks() {
    ///block = new Block[MAX_BLOCK](5);

    for(int i = 0; i < MAX_BLOCK; i++)
    {
        block[i] = new Block(Block::GenNum(100));
    }
}

void Engine::init_mouse_circle_dot() {
    const float radius = 5.0f;
    this->mouseCircleDOT.setRadius(radius);
    ///this->mouseCircleDOT.setPointCount(30);
    this->mouseCircleDOT.setFillColor(sf::Color::Red);
    this->mouseCircleDOT.setOrigin(radius,radius);
}

void Engine::isBlockGettingClicked() {
    for(int i = 0; i < MAX_BLOCK; i++) {
        if(block[i] != nullptr)
        {
            if(mouseCircleDOT.getGlobalBounds().intersects(block[i]->getShape().getGlobalBounds())) {
                /// Play sfx
                if(music.getStatus() == sf::Music::Stopped) music.stop();
                music.play();
                /// End sfx
                ////std::cout << "\nBlock ID : " << block[i]->ID << " | Is get clicked!\n";
                ////std::cout << "Deleting it..\n";
                delete this->block[i];
                std::cout << std::endl;
                this->block[i] = nullptr;
                return;
            }
        }
    }
    ///std::cout << "No one get clicked yet \n";
}




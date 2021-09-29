#include "Block.h"

int Block::ID_BLOCK = 0;

/** Constructor */
Block::Block(float radius)
:  ID(ID_BLOCK++), m_radius(radius)
{
    init_block_component();

}

/** Destructor */
Block::~Block()
{
    std::cout << "Deleted class block\n";
}

/** Method dimana akan generate number dan return tipe float
    @param num ialah max random nya
*/
float Block::GenNum(int num) {
    return (float)(1 + (rand() % num));
}

/** Method dimana jika user telah mengklik bola ( Construction )

*/

/**
bool Block::isGettingClicked(Block* blocks) {
    ///for()
    ///if(c1.getCircle().getGlobalBounds().intersects(c2.getCircle().getGlobalBounds())) return true;
    return false;
}
*/

/** Method dimana menjalankan si bola
    @param dt = delta time
    @param speed = speed berjalan nya.
    //< tes
*/
void Block::move(float& dt, float& speed) {
    if((shape.getPosition().x < 600 && shape.getPosition().x > 0) &&
       (shape.getPosition().y < 600 && shape.getPosition().y > 0))
    {
        /// 0 = left, 1 = right, 2 = up, 3 = down, else left up
        if(this->ID % 10 == 0) /// to left
            shape.setPosition(shape.getPosition().x - 1.0f * dt * speed, shape.getPosition().y);
        else if(this->ID % 10 == 1)
            shape.setPosition(shape.getPosition().x + 1.0f * dt * speed, shape.getPosition().y);
        else if(this->ID % 10 == 2)
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1.0f * dt * speed);
        else if(this->ID % 10 == 3)
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1.0f * dt * speed);
        else
            shape.setPosition(shape.getPosition().x + 1.0f * dt * speed, shape.getPosition().y - 0.25f * dt * speed);
    } else {
        shape.setPosition((float)25 + (rand() % 250), (float)25 + (rand() % 250));
        ///std::cout << "Default location ID: " << this->ID << "\n";
    }

}

/** Method dimana si bola akan di draw
    @param *window = mengambil alamat si window;
*/
void Block::draw(sf::RenderWindow *window) {
	window->draw(this->shape);
}

sf::CircleShape& Block::getShape() {
    return shape;
}

/** Method diamana initialize semua nilai si bola */
void Block::init_block_component() {
	shape = sf::CircleShape(m_radius);
	shape.setFillColor(sf::Color(rand() % 255,rand() % 255,rand() % 255));
	shape.setPosition(Block::GenNum(500), Block::GenNum(500));
	///std::cout << "ID_BLOCK : " << this->ID << std::endl;
}






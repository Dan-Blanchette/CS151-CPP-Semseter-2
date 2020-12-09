#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, 
    float dir_X, float dir_Y, float movement_speed)

{
    m_shape.setTexture(*texture);
    m_shape.scale(0.02f,0.02f);
    m_shape.setPosition(pos_x, pos_y);
    m_direction.x = dir_X; 
    m_direction.y = dir_Y;
    m_movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
    return m_shape.getGlobalBounds();
}

void Bullet::update()
{
    //Movement
    m_shape.move(m_movementSpeed * m_direction);
}

void Bullet::render(sf::RenderTarget* target) 
{
    target->draw(m_shape);
}
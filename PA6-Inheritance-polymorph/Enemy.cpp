#include "Enemy.h"


Enemy::Enemy()
{
    m_initVariables();
    m_initShape();
}

Enemy::Enemy(float pos_x, float pos_y)
{
    m_initVariables();
    m_initShape();

    m_shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
    
}

/***********Accessors*****************/
const sf::FloatRect Enemy::getBounds() const
{
    return m_shape.getGlobalBounds();
}

void Enemy::update()
{
    //std::cout << "hello from Enemy class" << '\n'; // test code to check for Polymorphism 
    m_shape.move(0.f, m_speed);
}

void Enemy::render(sf::RenderTarget* target) 
{
    target->draw(m_shape);
}

const int& Enemy::getPoints() const
{
    return m_points;
}

const int& Enemy::getDamage() const
{
    return m_damage;
}

/*ENEMY PRIVATE FUNCTIONS*/
void Enemy::m_initVariables()
{
    //random value between 0 & 7 max(10) min value = 3  sets a range from 0 - 10 possible points
    m_pointCount = rand() % 8 + 3;  

    m_type = 0;
    m_speed = static_cast<float>(m_pointCount / 5);
    m_hp = m_hpMax;
    m_hpMax = static_cast<int>(m_pointCount);
    m_damage = m_pointCount;
    m_points = m_pointCount;
}

void Enemy::m_initShape()
{
    m_shape.setRadius(m_pointCount * 5);
    m_shape.setPointCount(m_pointCount);
    m_shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1,
    255));
}
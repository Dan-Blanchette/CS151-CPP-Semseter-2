#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
#include <SFML/Graphics.hpp>

// Derived class of Player
class Enemy : public Player
{
public:
    Enemy();
    Enemy(float pos_x, float pos_y);
    virtual ~Enemy();

    //Accessors
    const sf::FloatRect getBounds() const;
    //Polymorphic call to Enemy class update() function
    virtual void update();
    //Polymorphic with Bullet Class defintion
    virtual void render(sf::RenderTarget* target);
    const int& getPoints() const;
    const int& getDamage() const;

private:
    sf::CircleShape m_shape;

    unsigned m_pointCount;
    int m_type;
    int m_speed;
    int m_hp;
    int m_hpMax;
    int m_damage;
    int m_points;

    void m_initVariables();
    void m_initShape();
};

#endif
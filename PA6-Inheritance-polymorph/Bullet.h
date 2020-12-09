#ifndef BULLET_H
#define BULLET_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include <vector>

// Child Class of Enemy
class Bullet : public Enemy
{

public:
    // Default Constructor
    Bullet();
    // Bullet Sprite Default Constructor
    Bullet(sf::Texture* texture, float pos_x, float pos_y, 
        float dir_X, float dir_Y, float movement_speed);
    //Destructor
    virtual ~Bullet();

    //Accessor
    const sf::FloatRect getBounds() const; // gets position
    
    // Polymorphic function with same parameters as Enemy class (virtual)
    virtual void update();

    /* because of Inheritance this code (through polymorphism) will render 
     the Bullet class sprite instead of the Enemy class circle shape even though both
     class share identicle parameters and private member variable names. */
    virtual void render(sf::RenderTarget* target);

private:

    sf::Sprite m_shape;
    sf::Vector2f m_direction;
    float m_movementSpeed;
};





#endif
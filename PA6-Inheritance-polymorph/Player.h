#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

// Parent Class
class Player 
{
public:
    Player();
    virtual ~Player();

    //Accessors
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    const int getHp() const;
    const int getHpMax() const;

    //Modifiers
    void pSetPosition(const sf::Vector2f pos);
    void pSetPosition(const float x, const float y);
    void setHp(const int hp);
    void loseHp(const int value);

    //Functions
    void move(const float dirX, const float dirY);
    const bool canAttack();
    
    // Player game loop functions
    // call to Player class update() function
    virtual void update();
    void updateAttack();
    void render(sf::RenderTarget& target);


private:
    sf::Sprite m_playerSprite;
    sf::Texture m_texture;

    float m_attackCooldown;
    float m_attackCooldownMax;

    int m_hp;
    int m_hpMax;

    float m_movementSpeed;
    /***********INTIALIZERS**********/
    void m_initTexture();
    void m_initVariables();
    void m_initSprite();

};


#endif
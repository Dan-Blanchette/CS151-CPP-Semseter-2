#include "Player.h"

Player::Player()
{
    m_initVariables();
    m_initTexture();
    m_initSprite();
}


// Default Destructor
Player::~Player()
{

}

/************* Accessors ***************/
// passes a reference to the player's current postion
const sf::Vector2f& Player::getPos() const
{
    return m_playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return m_playerSprite.getGlobalBounds();
}

const int Player::getHp() const
{
    return m_hp;
}

const int Player::getHpMax() const
{
    return m_hpMax;
}

/****************MODIFIERS*************************/
void Player::pSetPosition(const sf::Vector2f pos)
{
    m_playerSprite.setPosition(pos);
}

void Player::pSetPosition(const float x, const float y)
{
    m_playerSprite.setPosition(x,y);
}

void Player::setHp(const int hp)
{
    m_hp = hp;
}

void Player::loseHp(const int value)
{
    m_hp -= value;
    if (m_hp < 0)
        m_hp = 0;

}

/**********************Functions*********************/
void Player::move(const float dirX, const float dirY)
{
    m_playerSprite.move(m_movementSpeed * dirX, m_movementSpeed * dirY);
}

const bool Player::canAttack()
{
    if(m_attackCooldown >= m_attackCooldownMax)
    {
        m_attackCooldown = 0.f;
        return true;
    }
    return false;
}

/********************* Player game loop functions *************/
void Player::update()
{
    //std::cout << "Hello from Player Class" << '\n'; // test code to check for Polymorphism 
    updateAttack();
}

// Checks for player cooldowns
void Player::updateAttack()
{
    if(m_attackCooldown < m_attackCooldownMax)
    {
        m_attackCooldown += 0.1f;
    }
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(m_playerSprite);
}

/**********PRIVATE FUNCTIONS **********/

/***********INTIALIZERS**********/

void Player::m_initTexture()
{
    // load a texture from file
    if(!m_texture.loadFromFile("Textures/survivor.png"))
    {
        std::cout << "Error in player.cpp | texture was not loaded" << '\n';
    }
}

void Player::m_initSprite()
{
    // set the texture to the sprite
    m_playerSprite.setTexture(m_texture);

    // set the player's position to the center of the lower half of the screen
    m_playerSprite.setPosition(sf::Vector2f(400.f,590.f));

    //Resize the sprite
    m_playerSprite.scale(0.4f, 0.4f);
}

void Player::m_initVariables()
{
    // how fast the player can move
    m_movementSpeed = 2.f;
    // max times a key can be registered per frame
    m_attackCooldownMax = 1.f;
    // sets the cool down to not exceed the max cooldown
    m_attackCooldown = m_attackCooldownMax;
    m_hpMax = 100;
    m_hp = m_hpMax;
}
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <sstream>
#include <string>
#include <map>

//Derived class 
class Game : public Player
{
public:
    Game(); // default constructor
    virtual ~Game(); // destructor

    // Functions
    void execute();
    // game loop functions

    void updatePollEvents();
    void updateInput();
    void updateBullets();
    void updateEnemies();
    void updateCombat();
    void updateGUI();
    void updateCollision();
    //Polymorphic call to run the Game class update() function 
    virtual void update();
    void renderGUI();
    void renderWorld();

    /* this function will override Player's Function 
    //virtual void render(sf::RenderTarget& target) 
    when called in game.cpp */
    virtual void render();

private:

    /***private intializer functions**/

    void m_initializeWindow();
    //initialize player variables/functions
    void m_initializePlayer();
    //initialize texture variables/functions
    void m_initializeTextures();
    //intialize enemies
    void m_initializeEnemies();
    //intialize GUI
    void m_intializeGUI();
    //intialize World
    void m_intializeWorld();
    //intialize Points systems
    void m_initializePointSys();

    /*VARIABLES ANE RESOURCES*/
    sf::RenderWindow* m_window;

    //Resources

    /* Mapping assosciates two different libraries
    into a single call. In this case textures can be assgined by
     a std::string object or a SFML texture object 
     NOTE: THIS METHOD WAS ser*/
    std::map <std::string, sf::Texture*> m_textures;

    /* Vector that will populate bullet sprites remove 
        them via dynamic memory*/
    std::vector<Bullet*> m_bullets;


    // Player's GUI
    sf::RectangleShape m_playerHpBar;
    sf::RectangleShape m_playerHpBarRestore;
    sf::Text m_Health;

    //GUI
    sf::Font m_font;
    sf::Text m_pointText;
    sf::Text m_gameOverMessage;
    
    //World Background
    sf::Texture m_zombieLandBG;
    sf::Sprite m_zombieLand;

    Player* m_player;

    //System
    unsigned m_killPoints;

    //Enemies
    float m_spawnTimer;
    float m_spawnTimerMax;
    std::vector<Enemy*> m_enemies;
};





#endif
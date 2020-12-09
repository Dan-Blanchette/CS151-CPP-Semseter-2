#include "Game.h"

Game::Game() // default constructor
{
    m_initializeWindow();
    m_initializePlayer();
    m_initializeTextures();
    m_intializeGUI();
    m_intializeWorld();
    m_initializeEnemies();
    m_initializePointSys();
}


Game::~Game()  // destructor
{
    delete m_window;
    delete m_player;

    // deletes all textures from std::map <std::string, sf::Texture*> textures;
    for (auto &i : m_textures)
    {
        delete i.second; // deletes the second part of the container
    }

    // Deletes the bullets
    for (auto &i : m_bullets)
    {
        delete i;
    }

    // Deletes the enemies
    for (auto &i : m_enemies)
    {
        delete i;
    }
}

void Game::execute()
{
    while (m_window->isOpen())
    {
        updatePollEvents();

        if (m_player->getHp() > 0)
        {
            update();
        }
        update();
        render();
    }
}

void Game::updatePollEvents()
{
    sf::Event ev;
    while (m_window->pollEvent(ev))
    {
        if (ev.Event::type == sf::Event::Closed)
            m_window->close();
        if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
            m_window->close();
    }
}

void Game::updateInput()
{
    //Move player
    //LEFT = A
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_player->move(-1.f, 0.f);
    //RIGHT = D
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_player->move(1.f, 0.f);
    //UP = W
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        m_player->move(0.f, -1.f);
    //DOWN =  S
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        m_player->move(0.f, 1.f);
    //SHOOT = SPACE
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_player->canAttack())
    {
        m_bullets.push_back(new Bullet(m_textures["BULLET"],
                                       m_player->getPos().x + m_player->getBounds().width / 2.f,
                                       m_player->getPos().y, 0.f, -1.f, 5.f));
    }
}

void Game::updateBullets()
{
    for (auto* bullet : m_bullets)
    {
        unsigned counter = 0;
        bullet->update();

        if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
        {
            delete m_bullets.at(counter);
            m_bullets.erase(m_bullets.begin() + counter);
            --counter;

            //std::cout << bullets.size();
        }
        ++counter;
    } // Check to delete bullets the go off the top of the screen
}
// Spawns enemies to the vector and limits the amount of enemies spawned
void Game::updateEnemies()
{
    m_spawnTimer += 0.5f;
    if (m_spawnTimer >= m_spawnTimerMax)
    {
        m_enemies.push_back(new Enemy(rand() % m_window->getSize().x - 20.f, -100.f));
        m_spawnTimer = 0.f;
    }
    //Update
    unsigned counter = 0;
    for (auto *enemy : m_enemies)
    {
        enemy->update();
        //
        if (enemy->getBounds().top > m_window->getSize().y)
        {
            // Delete enemy
            delete m_enemies.at(counter);
            // remove enemies from the dynamic memory
            m_enemies.erase(m_enemies.begin() + counter);
        }
        // Enemy and player to collide
        else if (enemy->getBounds().intersects(m_player->getBounds()))
        {
            m_player->loseHp(m_enemies.at(counter)->getDamage());
            delete m_enemies.at(counter);
            // remove enemies from the dynamic memory
            m_enemies.erase(m_enemies.begin() + counter);
        }

        ++counter;
    } // Check to delete bullets the go off the top of the screen
}

void Game::updateCombat()
{

    for (int i = 0; i < m_enemies.size(); ++i)
    {
        // check to see if enemy was removed
        bool enemyDeleted = false;
        //  if enemy was killed, break out of inner for loop return to the outer loop
        for (size_t k = 0; k < m_bullets.size() && enemyDeleted == false; k++) //  if enemy was killed,
        {
            /* if there is a collision, delete the enemy and the bullet from their
          respective vectors*/
            if (m_enemies[i]->getBounds().intersects(m_bullets[k]->getBounds()))
            {
                // points accumulator
                m_killPoints += m_enemies[i]->getPoints();

                // remove enemy screen
                delete m_enemies[i];
                m_enemies.erase(m_enemies.begin() + i);

                // remove bullet from screen
                delete m_bullets[k];
                m_bullets.erase(m_bullets.begin() + k);

                // if this part of the instruction is ran, returns a true value to inner loop.
                enemyDeleted = true;
            }
        }
    }
}
// Displays Player health bar and points total. 
void Game::updateGUI()
{
    std::stringstream ss;

    ss << "Health" << '\n';

    m_Health.setString(ss.str());
    //I added "health" to indicate what the bar was in the top left corner and an onscreen instruction set.
    ss << "Points: " << m_killPoints <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
       << "W = UP" << "\n" << "S = DOWN" << '\n' << "A = LEFT" << "\n"
       << "D = RIGHT" << "\n" << "Space Bar = Shoot " << "\n" << "Esc = Quit";

    m_pointText.setString(ss.str());

    float hpPercent = static_cast<float>(m_player->getHp()) / m_player->getHpMax();
                            m_playerHpBar.setSize(sf::Vector2f(300.f * hpPercent,
                            m_playerHpBar.getSize().y));
}

// limit the area in which the player or enemies can go
void Game::updateCollision()
{
    // stop the player from moving too far pastt the left of the screen
    if (m_player->getBounds().left < 0.f)
    {
        m_player->pSetPosition(0.f, m_player->getBounds().top);
    }

    // stop the player from moving too far past the top of screen
    else if (m_player->getBounds().top < 0.f)
    {
        m_player->pSetPosition(m_player->getBounds().left, 0.f);
    }

    // stop the player from moving too far past the right of screen
    else if (m_player->getBounds().left + m_player->getBounds().width >=
             m_window->getSize().x)
    {
        m_player->pSetPosition(m_window->getSize().x - 
                                   m_player->getBounds().width,
                                   m_player->getBounds().top);
    }

    // stop the player from moving too far past the bottom of screen
    else if (m_player->getBounds().top + m_player->getBounds().height >=
             m_window->getSize().y)
    {
        m_player->pSetPosition(m_player->getBounds().left, 
                                   m_window->getSize().y - 
                                   m_player->getBounds().height);
    }
}


void Game::update()
{
    // Game checks for player input
    updateInput();
    // Game updates player position in world
    m_player->update();
    // Game sets boundries for enemies and player
    updateCollision();
    // Game updates bullet sprites
    updateBullets();
    // Game looks intersection of character and bullet sprites with enemies
    updateCombat();
    // Enemy movement and enemy type
    updateEnemies();
    // updates points and health of the player
    updateGUI();
    // fucntion to updates world textures **not used and was removed** 
    //std::cout << "Hello From Game Class" << '\n'; // test code to check for Polymorphism 
}

void Game::renderGUI()
{
    m_window->draw(m_pointText);
    m_window->draw(m_playerHpBarRestore);
    m_window->draw(m_playerHpBar);
}

void Game::renderWorld()
{
    m_window->draw(m_zombieLand);
}

void Game::render()
{
    m_window->clear();

    //draw background
    renderWorld();

    //draws all the stuff
    m_player->render(*m_window);

    for (auto *bullet : m_bullets)
    {
        bullet->render(m_window);
    }

    for (auto *enemy : m_enemies)
    {
        enemy->render(m_window);
    }

    renderGUI();

    //GAME OVER SCREEN
    if(m_player->getHp() <= 0)
    {
        m_window->draw(m_gameOverMessage);
    }

    m_window->display();
}
//PRIVATE FUNCTIONS

/***************Initializers*******************/
void Game::m_initializeWindow()
{
    m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Zombies Go Here: An Apocolyptic Shape Shooter", 
                                    sf::Style::Titlebar | sf::Style::Close);
    m_window->setFramerateLimit(144);
    m_window->setVerticalSyncEnabled(false);
}

void Game::m_initializePlayer()
{
    m_player = new Player();
}

void Game::m_initializeTextures()
{
    m_textures["BULLET"] = new sf::Texture();
    m_textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::m_initializeEnemies()
{
    m_spawnTimerMax = 50.f;
    m_spawnTimer = m_spawnTimerMax;
}

void Game::m_intializeGUI()
{
    //Load Font
    if (!m_font.loadFromFile("Fonts/impact.ttf"))
        std::cout << "Error Game Failed to Load Font " << '\n';


    //Init point text
    m_pointText.setPosition(20.f, 50.f);
    m_pointText.setFont(m_font);
    m_pointText.setCharacterSize(20); // set text size for interface
    m_pointText.setFillColor(sf::Color(255,255,255,120));
    m_pointText.setString("Points");

    //GAME OVER
    m_gameOverMessage.setFont(m_font);
    m_gameOverMessage.setCharacterSize(60); // set text size for interface
    m_gameOverMessage.setFillColor(sf::Color::Red);
    m_gameOverMessage.setString("GAME OVER");
    m_gameOverMessage.setPosition(
        m_window->getSize().x / 2.f - m_gameOverMessage.getGlobalBounds().width / 2.f,
        m_window->getSize().y / 2.f - m_gameOverMessage.getGlobalBounds().height / 2.f);

    // init player Gui
    m_playerHpBar.setSize(sf::Vector2f(300.f, 25.f));

    m_playerHpBar.setFillColor(sf::Color::Green);
    m_playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

    m_playerHpBarRestore = m_playerHpBar;
    m_playerHpBarRestore.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::m_intializeWorld()
{
    if (!m_zombieLandBG.loadFromFile("Textures/zombieLand.png"))
    {
        std::cout << "Could not load background texture" << '\n';
    }
    m_zombieLand.setTexture(m_zombieLandBG);
}

void Game::m_initializePointSys()
{
    m_killPoints = 0;
}
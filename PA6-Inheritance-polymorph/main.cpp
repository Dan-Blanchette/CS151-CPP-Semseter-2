// Dan Blanchette
// PA6 Video Game: Inheritance and Polymorphism

// Due Date: May 14, 2020

/* Source Code Citation:
 YouTube.com  Sharma, Suraj: Simple 2D Games Tutorial Playlist :
 Episodes 20 - 35 ( His tutorials covered creating a space shooter with multiple 
 classes and explained the functionality/methods derived from SFML 
 to be used within a video game program ) */
/* https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up */

/*PROGRAMMER'S NOTE: Suraj's TUTORIAL DID NOT USE INHERITANCE 
OR POLYMORPHISM FOR HIS IMPLIMENTATION.

*********************************************************
* See ProjectReadMe.txt for project notes/documentation *
*********************************************************/

#include "Game.h"
#include <ctime>

int main()
{
    srand(time(static_cast<unsigned>(0)));
    // Class Object
    Game game;
    //Run the game
    game.execute();
    
    return 0;
}
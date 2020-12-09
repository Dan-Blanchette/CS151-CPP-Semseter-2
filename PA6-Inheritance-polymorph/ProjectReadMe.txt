 Source Code Citations:
 YouTube.com  Sharma, Suraj: Simple 2D Games Playlist :
 Episodes 20 - 35 ( His tutorials covered creating a space shooter with multiple 
 classes and explained the functionality/methods derived from SFML within a video game program ) 
 https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up

***************************************************************************
Source Code from Seraj Sharma's tutorial for this project include 
the following in relation to this project's SFML Code and methods:
***************************************************************************
application of textures & shapes
select variable names
creating a player health bar
assigning sprites
Collision detection of game objects
setting screen bounds
frame rate limitation
creating RNG enemies/shapes
mapping
using dynamic memory in the form of vectors for bullets and enemy spawning
*****************************************************************************

My Work:
*****************************************************************************
** optimizing readability of code (removed all inistances of "This->" and 
    changed all private class member variables to "m_" as per our course's formatting 
    requirements ).
*****************************************************************************
** Added Comments and annotation of functions and methods regarding how they work 
    and what they do at a deeper level.
*****************************************************************************
** Analyze and implimented Inheritance/Polymorphism for the 4 classes.
    Added lines test code to ensure Inherticance/Polymorphism was happening 
    when the executable was running.
*****************************************************************************
** Fine tuned the player's game experience to be "fair" by adjust movement speed 
    and enemy spawn rates.

    Added a character start position to remove the sprite from its default 0.f,0.f 
    location.

    Relocated the Points: display and adjusted color settings to make it more visable.
    Added "Health" and instruction set to the GUI of the game.
    
    I also chose free to use texture maps from gitHub and customized the game
    to fit something I was more interested in developing. As such, the game was 
    changed from a space ship shooter to a top down survivor vs zombies horde 
    program shell.

    in this version the RNG shapes will stand in for zombies sprites.  
*****************************************************************************
    Future endeavors include :

    Enemy sprites
    Different Enemy types
    An in game Restart option after game over
    screen transitioning etc.

    working on and understanding RPG game engines
    and their relationship with dynamic and stack memory.


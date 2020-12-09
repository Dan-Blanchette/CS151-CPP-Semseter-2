#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include "windows.h"

using namespace std;

// Link List Struct and Default Constructor
struct ListNode
{
  string value;
  ListNode* next;
  ListNode* prev;
  ListNode(string value1, ListNode* next1 = nullptr, ListNode* prev1 = nullptr)
  {
    value = value1;
    prev = prev1;
    next = next1;
  }
};

struct Record
 {
   string artist; // Artist (a string)
   string albumTitle; // Album title (a string)
   string songTitle; // Song title (a string)
   string genre; // Genre (a string)
   struct Duration
   {
       // Song length
       // (struct Duration type consisting of seconds and minutes)
       int minutes; 
       int seconds;
   };
   int playCount; // Number of times played (an integer)
   int Rating; // Rating (1 to 5) (an integer)
 };

// Classes
class MusicPlaylist
{
  public:
    //Default constructors to initialize
     MusicPlaylist(); // Default Constructor
     //MusicPlaylist(const vector<Record>& vec);
     ~MusicPlaylist(); // Destructor
    
    //Display the main menu
    void displayMenu();

    void readToVect(vector<Record> vec, int size, ifstream& fileHandler);

    // Get the user's choice
    int getChoice(int);
    // Adds an element to the beginning of the list
    // void addFront(Record data);

    // // Adds an element to the end of the list
    // void addEnd(Record data);

    // // Removes the first element of the list
    // void removeFront();

    // // Removes the last element of the list
    // void removeEnd();

    //     // Returns the number of elements
    // int size() const;

    // // Returns true if list is empty, otherwise false
    // bool empty() const;
    //  // Returns string of the values in the list separated by spaces
    // Record str() const;

    // // Returns a reference to the value of the first element in the list
    //  Record& front();

    // // Returns a reference to the value of the last element in the list
    //  Record& end();

    // // Returns a reference to the value of nth index in the list
    //  Record& getNth(int index) const;


    // // Returns the vector version of the list
    // vector<Record> toVector() const;

  private:
     ListNode* m_head;  // points to the head of the list
     ListNode* m_tail;  // points to the tail of the list
     int m_size; // List size

};




#endif
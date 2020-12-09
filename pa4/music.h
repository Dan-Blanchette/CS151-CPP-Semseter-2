#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "windows.h"

using namespace std;

// Link List Struct and Default Constructor
struct ListNode
{
  Record value;
  ListNode* next;
  ListNode* prev;
  ListNode(Record value1, ListNode* next1 = nullptr, ListNode* prev1 = nullptr)
  {
    value = value1;
    prev = prev1;
    next = next1;
  }
};

// List Node Data Structure
struct Record
 {
   string Artist; // Artist (a string)
   string AlbumTitle; // Album title (a string)
   string SongTitle; // Song title (a string)
   string Genre; // Genre (a string)
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
    MusicPlaylist(); // Default Constructor
    MusicPlaylist(vector<string>& vec);
    ~MusicPlaylist(); // Destructor

      // Adds an element to the beginning of the list
    void addFront(string data);

    // Adds an element to the end of the list
    void addEnd(string data);

    // Removes the first element of the list
    void removeFront();

    // Removes the last element of the list
    void removeEnd();

        // Returns the number of elements
    int size() const;

    // Returns true if list is empty, otherwise false
    bool empty() const;
     // Returns string of the values in the list separated by spaces
    Record str() const;

    // Returns string of the values in the list in reverse 
    // separated by spaces
    Record strReverse() const;

    // Returns a reference to the value of the first element in the list
     Record& front();

    // Returns a reference to the value of the last element in the list
     Record& end();

    // Returns a reference to the value of nth index in the list
     Record& getNth(int index) const;


    // Returns the vector version of the list
    vector<string> toVector() const;

  private:
     ListNode* m_head;  // points to the head of the list
     ListNode* m_tail;  // points to the tail of the list
     int m_size; // List size

};



// Functions
void displayMenu();
int getchoice(int);

#endif
#include "music.h"
#include <iostream>
using namespace std;

// FUNCTION DEFINITIONS


// Function that will display the user's menu
void MusicPlaylist::displayMenu()
{
    system("cls");
    cout << "**** Welcome to Anthem Music Manager ****\n";
    cout << "\nPlease make a selection from the menu\n";
    cout << left << setw(21) <<  "\n[  1 ] Load" <<  "[  7 ] Delete" << "\n";
    cout << left << setw(20) <<  "[  2 ] Store"  << "[  8 ] Insert" << "\n";
    cout << left << setw(20) <<  "[  3 ] Display"  << "[  9 ] Sort" << "\n";
    cout << left << setw(20) <<  "[  4 ] Edit"  << "[ 10 ] Reverse" << "\n";
    cout << left << setw(20) <<  "[  5 ] Rate"  << "[ 11 ] Shuffle" << "\n";
    cout << left << setw(20) <<  "[  6 ] Play"  << "[ 99 ] Exit" << "\n\n";
}
// Function to get user's choice for Linked list's switch statement
// cases possibly not needed.

int MusicPlaylist::getChoice(int uChoice)
{
    cout << "\nPlease enter a selction: ";
    cin >> uChoice;
    return uChoice;
}

// This function will read .csv file and add nodes to the doubly
// linked list at the end.
void MusicPlaylist::readCsv(ifstream& fileHandler)
{
    char delim1 = ',';
    char delim2 = ':';
    Record rec;
    while (!fileHandler.eof())
    {
        getline(fileHandler, rec.artist, delim1);
        getline(fileHandler, rec.albumTitle,delim1);
        getline(fileHandler, rec.songTitle, delim1);
        getline(fileHandler, rec.genre, delim1);
        fileHandler >> rec.time.minutes;
        fileHandler >> delim2 >> rec.time.seconds >> delim1;
        fileHandler >> rec.playCount >> delim1;
        fileHandler >> rec.Rating >> delim1;
    }
    // add data to a RECORD node and position it at the end of link list
    addEnd(rec); 
}   

// Default Constructor
MusicPlaylist::MusicPlaylist()
{
    m_head = nullptr; // intialize m_head to nullptr
    m_tail = nullptr; // initialize m_tail to nullptr
    m_size = 0;  // initialize m_size to 0
}

// MusicPlaylist::MusicPlaylist(const vector<Record>& vec)
// {
//     m_head = nullptr;
//     m_tail = nullptr;
//     m_size = 0;
//     for (int i = 0; i < vec.size(); i++)
//     {
//         addEnd(vec[i]);
//     }
// }


MusicPlaylist::~MusicPlaylist() // Default Destructor
{
    ListNode* ptr = m_head;
    while (ptr != nullptr)
    {
        ListNode* garbage = ptr;
        ptr = ptr->next;
        delete garbage;
    }
}

 //Adds an element to the beginning of the list
// void MusicPlaylist::addFront(Record data)
// {
//      if (m_head == nullptr) // if the list is empty
//     {
//         m_head = m_tail = new ListNode(data,nullptr,nullptr);
//     }
//     else // not empty
//     {
//        m_head = new ListNode(data, m_head, nullptr);
//        m_head->next->prev = m_head;
//     }
//     ++m_size;
// }

// // Adds an element to the end of the list
 void MusicPlaylist::addEnd(Record data)
{
    if (m_head == nullptr) // if the list is empty
    {
        m_head = m_tail = new ListNode(data,nullptr,nullptr);
    }
    else // not empty
    {
       m_tail = new ListNode(data, nullptr, m_tail);
       m_tail->prev->next = m_tail; 
    }
    ++m_size;
}

// // Removes the first element of the list
// void MusicPlaylist:: removeFront()
// {
//        if(m_head != nullptr)
//     {
//         ListNode* nodePtr = m_head; 
//         m_head = m_head->next; 
//         m_head->prev = nullptr; 
//         delete nodePtr; 
//     }
//     --m_size; 
// }
// // Removes the last element of the list
// void MusicPlaylist::removeEnd()
// {
//     if(m_tail != nullptr)
//     {
//         ListNode* nodePtr = m_tail; 
//         m_tail = m_tail->prev; 
//         m_tail->next = nullptr; 
//         delete nodePtr; 
//     }
//     --m_size; 
// }

// // Returns the number of elements
// int MusicPlaylist::size() const
// {
//     return m_size;
// }

// // Returns true if list is empty, otherwise false
// bool MusicPlaylist::empty() const
// {

// }

// void MusicPlaylist::displayAthem()
// {
//     printList(m_head);
// }

// void MusicPlaylist::printList(ListNode *nodePtr)
// {
//     if (nodePtr != nullptr)
//     {
//         cout << nodePtr->value.artist << " ";
//         printList(nodePtr->next);
//     };
// }

// // Returns a reference to the value of the first element in the list
// Record& MusicPlaylist::front()
// {
//     return m_head->value;
// }

// // Returns a reference to the value of the last element in the list
// Record& MusicPlaylist::end()
// {
//     return m_tail->value;
// }   

// // Returns a reference to the value of nth index in the list
// Record& MusicPlaylist::getNth(int index) const
// {
//     ListNode* nodePtr = m_head; 
//     for (int i = 0; i < index; i++)
//     {
//         nodePtr=nodePtr->next; 
//     }
//     return nodePtr->value; 
// }


// // Returns the vector version of the list
// vector<Record> MusicPlaylist::toVector() const
// {

// }

// What must Store do?
// The store command writes the current records, in the 
// dynamic doubly linked list, to the musicPlayList.csv file. 
// The store will completely overwrite the previous contents in the file.


// What must Display do?
// The display command prints record to the screen. 
// This command MUST support two methods, 
// one of which is selected by the user:
// Print all records.
// Print all records that match an artist.

void MusicPlaylist::displayAthem(ListNode *ptr)
{
    ptr = m_head;
    while (ptr != nullptr)
    {
        cout << ptr->value.artist;
    // Print all records.
    // Print all records that match an artist.
    ptr = ptr->next;
}

// What must Edit do?
// The edit command MUST allow the user to find a record in the list 
// by the artist. If there are multiple records with the same artist, 
// then your program must prompt the user which one to edit. 
// The user may modify all of the attributes in the record.


// What must Rate do?
// The rate command MUST allow the user to assign a value of 
// 1 to 5 to a song; 1 is the lowest rating and 5 is the highest rating. 
// The rating will replace the previous rating.


// What must Play do?
// The play command MUST allow the user to select a song and must start playing 
// each song in order from the current song. 
// Playing the song for this assignment means displaying the 
// contents of the record that represents the song for a short period of time, 
// clearing the screen and showing the next record in the list, etc. 
// This continues until all songs have been played.


// What must Delete do?
// The delete command MUST prompt the user for a song title, 
// and remove the matching record from the list. If the song title does not exist, then the list remains unchanged.


// What must Insert do?
// The insert command MUST prompt the user for the details of 
// a new record. The prompt must request the artist name, album title, song title, genre, song length, number of times played, 
// and rating. Then prompt the user where to insert the record, front or back of the list. Add the new record based on the user response.


// What must Shuffle do?
// The shuffle command MUST provide a random order in which the songs are played. This command MUST not modify the links in the list. 
// It must just specify the order in which songs are played, based on the position of the song in the list. For example,
// let’s say we have a list with 5 songs at positions 1 - 5 in the list, 
// shuffle must generate an order 1 -5 in which the songs are played. 
// An order 2, 5, 3, 1, 4 would require that the second song in the list is played first, 
// the fifth song in the list is played second, the third song in the list is played third, the first song in the list is played fourth, 
// and the fourth song in the list is played fifth. 
// The songs are accessed by traversing the list both forwards and backward to satisfy the order. Hence, the need for a doubly-linked list.


// What must Sort do? (EXTRA CREDIT: 25 points)
// The sort command MUST prompt the user for 4 different methods to sort the records in the list. These include:
// Sort based on artist (A-Z)
// Sort based on album title (A-Z)
// Sort based on rating (1-5)
// Sort based on times played (largest-smallest)


// Once a sort method is selected by the user, 
// the sort must be performed on the records in the list. 
// Use whatever sorting algorithm you want to use: bubble sort, insertion sort, selection sort, merge sort or quicksort.


// What must Exit do?
// The exit command saves the most recent list to the musicPlayLIst.csv file. 
// This command will completely overwrite the previous contents in the file.

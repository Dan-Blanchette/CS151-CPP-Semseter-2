#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

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

    void readCsvFile(Record vector<string>& vec, int size, ifstream& filestream);

int main()
{

    return 0;
}
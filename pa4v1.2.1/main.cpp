#include "music.h"



int main()
{
    MusicPlaylist anthem;
    Record rec;
    ListNode *nodePtr;
    ifstream inFile;
    int userChoice;
    //char yesOrNo;

   
    //  anthem.displayAthem();

        // cout << anthem

    // Display the Menu
     anthem.displayMenu();
     // Get the user's selection
     userChoice = anthem.getChoice(userChoice);

        switch (userChoice)
        {
            case 1:
            // Store function will run here
            inFile.open("musicPlayList.csv.txt");
            if (!inFile)
                cout << "Error File Not Found";
            else
            {
                anthem.readCsv(inFile);
                inFile.close();
            }
                return 0;
            break;

            case 2:
            anthem.displayAthem(nodePtr);// Display Function will run here
            break;

            case 3:
            // Edit function will run here
            break;

            case 4:
            // Edit function will run here
            break;

            case 5:
            // Edit function will run here
            break;

            case 6:
            // Edit function will run here
            break;

            case 7:
            // Edit function will run here
            break;

            case 8:
            // Edit function will run here
            break;

            case 9:
            // Edit function will run here
            break;

            case 10:
            // Edit function will run here
            break;

            case 11:
            // Edit function will run here
            break;
            // If an incorrect selection is made 
            // default will ensure the loop allows the user to make another choice.
            case 99:
                cout << "Thank you for using Anthem, the program will now close";
                return 0;
            default : 
                cout << "That is not a correct menu selection. \n" 
                     << "\nPlease re-enter your selection: ";
                anthem.displayMenu();
                anthem.getChoice(userChoice);
        }
     return 0;
}
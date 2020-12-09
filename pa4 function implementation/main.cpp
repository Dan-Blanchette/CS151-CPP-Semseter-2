#include "music.h"



int main()
{
    MusicPlaylist anthem;
    vector<Record> Record;
    ifstream inFile;
    int userChoice;
    char yesOrNo;

    inFile.open("musicPlayList.csv.txt");
    if (!inFile)
        cout << "Error File Not Found";
    else
    {
        anthem.readToVect(Record, Record.size(), inFile);
        inFile.close();
    }
    

    // Display the Menu
    anthem.displayMenu();
    // Get the user's selection
     userChoice = anthem.getChoice(userChoice);

        switch (userChoice)
        {
            case 1:
            // Store function will run here
            anthem.displayMenu();
            cout << "\nWould you like to return to the main menu? ";
            cout << "\nEnter 'y' for Yes or 'n' for No ";
            cout << "\nMake your selection here: ";
            cin >> yesOrNo;
            if (yesOrNo == 'y' | 'Y')
            {
                anthem.displayMenu();
                anthem.getChoice(userChoice);
            } 
            else 
                return 0;
            break;

            case 2:
            // Display Function will run here
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
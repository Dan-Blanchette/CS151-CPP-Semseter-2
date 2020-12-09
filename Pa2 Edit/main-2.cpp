// Dan Blanchette
// CS-151-102
// pa2
// This program will read in a .csv file with student data
// it will then sort this information and index it.
// the user will then request the information
// while arrays of pointers will indirectly bring the information
// to the console output.
// the user will also be able to search by specific strings for data.
#include "students.h"



int main()
{
/***variables, array definitions, and class/struct const***/
    int uChoice = 0;
    char cont;
    const int ROW_SIZE = 20;
    studentData studArr[ROW_SIZE]; // ORIGINAL ARRAY OF DATA DISORGANIZED
    studentData* indexingByLname[ROW_SIZE]; // INDEXED VERSION OF ARRAY BY LAST NAME
    studentData* indexingBySsn[ROW_SIZE]; // INDEXED VERSION OF ARRAY BY SSN
    studentData* indexingByFname[ROW_SIZE]; // INDEXED VERSION OF ARRAY BY FIRST NAME
    string binSearchVal;
    int results;// Holds the search results
    int* pos;
    string JimB = "JimB"; // Variable created for bounds check by first name Jim
    string JimD = "JimD"; // Variable created for bounds check by first name Jim
    string jimCheck;// Variable that will be used to pull up the correct record.

    //ifstream (input the .csv data)
    ifstream inFile;

    inFile.open("grades.csv");
    if (!inFile)
        cout << "There was an error opening the file";
    else
    {
        readCsvToArray(studArr, ROW_SIZE, inFile);
        inFile.close();
    }

    
    /******************************************************************************************/
    /**FUNCTIONS CALLS THAT INITIALIZES & "LINKS" studentData's ARRAY WITH THE POINTERS ARRAY**/
    /*****************************************************************************************/
    initializeIndexes(indexingByLname, studArr, ROW_SIZE);
    initializeIndexes(indexingBySsn, studArr, ROW_SIZE);
    initializeIndexes(indexingByFname, studArr, ROW_SIZE);

    /***********************************************/
    /**FUNCTIONS THAT SORT THE DATA FROM THE ARRAY**/    
    /***********************************************/
    sortLastName(indexingByLname, ROW_SIZE);
    sortBySsn(indexingBySsn, ROW_SIZE);
    sortByFirstName(indexingByFname, ROW_SIZE);

    /**********************************************************/
    /*FUNCTION THAT WILL DISPLAY & GET THE USER'S MENU OPTIONS*/
    /**********************************************************/
    do
    {
        displayMenu();
        uChoice = getChoice();
        //cout << uChoice; //test code to see if user input is being accepted.

        /*SWITCH STATEMENT TO CALL FUNCTION OPTIONS IN FOR THE USER*/
        switch (uChoice)
        {
            case 1:
                //will execute the function for menu option 1.
                printLName(indexingByLname, ROW_SIZE);
                cout << "\n\nWould you like to continue??"; 
                cout << "\nEnter 'y' to return to the menu or any key to quit";
                cout << "\n\nEnter your selection here: ";
                cin >> cont;
            break;
            //END CASE 1
            case 2:
            //will execute the function for menu option 2.
            printBySsn(indexingBySsn, ROW_SIZE);
             cout << "\n\nWould you like to continue??"; 
             cout << "\nEnter 'y' to return to the menu or any key to quit";
             cout << "\n\nEnter your selection here: ";
             cin >> cont;
            break;
            //END CASE 2
            case 3:
            //will execute the function for menu option 3.
            printByFirstName(indexingByFname, ROW_SIZE);
             cout << "\n\nWould you like to continue??"; 
             cout << "\nEnter 'y' to return to the menu or any key to quit";
             cout << "\n\nEnter your selection here: ";
             cin >> cont;
            break;
            //END CASE 3
            case 4: 
                //SEARCHES BY LAST NAME FOR DATA.
                cout << "\nEnter the student's last name (name entries are case sensitive) ";
                cout << "\nEnter your choice in this format: Doe ";
                cout << "\n\nEnter student name here: ";
                cin >> binSearchVal;
                //Call Function To Search By Last Name and Assign it to int results.
                results = binSearchByLName(indexingByLname, ROW_SIZE, binSearchVal, pos);
                // Compare the user's input to the flag to check to see if the entry exists.
                if (results == - 1)
                { cout << "\nNo results were found";
                    // If Results Are Found Print Out The Requested Data For The User.
                     cout << "\n\nWould you like to continue??"; 
                     cout << "\nEnter 'y' to return to the menu or any key to quit";
                     cout << "\n\nEnter your selection here: ";
                     cin >> cont;
                }
                else 
                {     
                    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                
                    
                        cout <<"\n" << left << setw(5) << pos->id;
                    
                     cout << "\n\nWould you like to continue??"; 
                     cout << "\nEnter 'y' to return to the menu or any key to quit";
                     cout << "\n\nEnter your selection here: ";
                     cin >> cont;
                }          
            break;
            //END CASE 4
            case 5:
                //SEARCHES BY SSN FOR DATA.
                cout << "\nEnter the student's social security number (in this format 867-53-0909): ";
                cin >> binSearchVal;
                //Call Function To Search By SSN and Assign it to int results.
                results = binSearchBySsn(indexingBySsn, ROW_SIZE, binSearchVal);
                // Compare the user's input to the flag to check to see if the entry exists.
                if (results == - 1)
                {   cout << "No results were found";
                    // If Results Are Found Print Out The Requested Data For The User.
                    cout << "\n\nWould you like to continue??"; 
                    cout << "\nEnter 'y' to return to the menu or any key to quit";
                    cout << "\n\nEnter your selection here: ";
                    cin >> cont;
                }
                else 
                {     
                    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                    for(int i = results; i <= results; ++i)
                    {
                        cout <<"\n" << left << setw(5) << indexingBySsn[i]->id << setw(12) << indexingBySsn[i]->lastName << setw(12) << indexingBySsn[i]->firstName
                             << setw(15) << indexingBySsn[i]->sSN << setw(8) << indexingBySsn[i]->test1 << setw(8) << indexingBySsn[i]->test2 << setw(8) 
                             << indexingBySsn[i]->test3 << setw(8) << indexingBySsn[i]->test4 << setw(8) << indexingBySsn[i]->final << setw(8) << indexingBySsn[i]->grade << "\n\n";
                    }
                        cout << "\n\nWould you like to continue??"; 
                        cout << "\nEnter 'y' to return to the menu or any key to quit";
                        cout << "\n\nEnter your selection here: ";
                         cin >> cont;
                }
            break;
            //END CASE 5
            case 6:
                //SEARCHES BY FIRST NAME FOR DATA.
                cout << "\nEnter the student's first Name (name entries are case sensitive)";
                cout << "\nEnter your choice in this format: James";
                cout << "\n\nEnter student name here: ";
                cin >> binSearchVal;
                //Call Function To Search By SSN and Assign it to int results.
                results = binSearchByFName(indexingByFname, ROW_SIZE, binSearchVal);
                // Compare the user's input to the flag to check to see if the entry exists.
            if (results == - 1)
            {   cout << "No results were found";
                // If Results Are Found Print Out The Requested Data For The User.
                 cout << "\n\nWould you like to continue??"; 
                 cout << "\nEnter 'y' to return to the menu or any key to quit";
                 cout << "\n\nEnter your selection here: ";
                 cin >> cont;
            }
            else if (results == 15)
            { 
                cout << "\n\nwhich Jim are you looking for?"; 
                cout << " Jim Backus or Jim Dandy?\n";
                cout << "\n\nIndicate your choice by entering JimB or JimD: ";
                cin >> jimCheck;
                //cout << jimCheck; This code tests for user entry
             
                if (jimCheck == JimB) //SUB CASE #1 IF Jim Backus
                {
                    results = 15;
                    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                        for(int i = results; i <= results; ++i)
                        {
                        cout <<"\n" << left << setw(5) << indexingByFname[i]->id << setw(12) << indexingByFname[i]->lastName << setw(12) << indexingByFname[i]->firstName
                             << setw(15) << indexingByFname[i]->sSN << setw(8) << indexingByFname[i]->test1 << setw(8) << indexingByFname[i]->test2 << setw(8) 
                             << indexingByFname[i]->test3 << setw(8) << indexingByFname[i]->test4 << setw(8) << indexingByFname[i]->final << setw(8) << indexingByFname[i]->grade << "\n\n";
                        }
                        cout << "\n\nWould you like to continue??"; 
                        cout << "\nEnter 'y' to return to the menu or any key to quit";
                        cout << "\n\nEnter your selection here: ";
                        cin >> cont;
                }    
            else if ( jimCheck == JimD) // SUB CASE #2 IF Jim Dandy
            {
                results = 16;
                cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                        for(int i = results; i <= results; ++i)
                        {
                            cout <<"\n" << left << setw(5) << indexingByFname[i]->id << setw(12) << indexingByFname[i]->lastName << setw(12) << indexingByFname[i]->firstName
                                 << setw(15) << indexingByFname[i]->sSN << setw(8) << indexingByFname[i]->test1 << setw(8) << indexingByFname[i]->test2 << setw(8) 
                                 << indexingByFname[i]->test3 << setw(8) << indexingByFname[i]->test4 << setw(8) << indexingByFname[i]->final << setw(8) << indexingByFname[i]->grade << "\n\n";
                        }
                             cout << "\n\nWould you like to continue??"; 
                             cout << "\nEnter 'y' to return to the menu or any key to quit";
                             cout << "\n\nEnter your selection here: ";
                             cin >> cont;
            }
            else if (jimCheck != JimB || jimCheck != JimD) // SUB CASE #3 IF YOU HAVE A BAD USER THAT TRIES ENTERING 
            //THE WRONG STRING FORMAT
            {
                cout << "\nPlease re-enter your selection as JimB or JimD ";
                cout << "\n\nRe-enter your selection: ";
                cin >> jimCheck;
                if ( jimCheck == JimD)//RECHECK #1
                {
                results = 16;
                cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                        for(int i = results; i <= results; ++i)
                        {
                            cout <<"\n" << left << setw(5) << indexingByFname[i]->id << setw(12) << indexingByFname[i]->lastName << setw(12) << indexingByFname[i]->firstName
                                 << setw(15) << indexingByFname[i]->sSN << setw(8) << indexingByFname[i]->test1 << setw(8) << indexingByFname[i]->test2 << setw(8) 
                                 << indexingByFname[i]->test3 << setw(8) << indexingByFname[i]->test4 << setw(8) << indexingByFname[i]->final << setw(8) << indexingByFname[i]->grade << "\n\n";
                        }
                             cout << "\n\nWould you like to continue??"; 
                             cout << "\nEnter 'y' to return to the menu or any key to quit";
                             cout << "\n\nEnter your selection here: ";
                             cin >> cont;
                }
                else if (jimCheck == JimB) //RECHECK #2
                {
                    results = 15;
                    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                        for(int i = results; i <= results; ++i)
                        {
                        cout <<"\n" << left << setw(5) << indexingByFname[i]->id << setw(12) << indexingByFname[i]->lastName << setw(12) << indexingByFname[i]->firstName
                             << setw(15) << indexingByFname[i]->sSN << setw(8) << indexingByFname[i]->test1 << setw(8) << indexingByFname[i]->test2 << setw(8) 
                             << indexingByFname[i]->test3 << setw(8) << indexingByFname[i]->test4 << setw(8) << indexingByFname[i]->final << setw(8) << indexingByFname[i]->grade << "\n\n";
                        }
                         cout << "\n\nWould you like to continue??"; 
                         cout << "\nEnter 'y' to return to the menu or any key to quit";
                         cout << "\n\nEnter your selection here: ";
                         cin >> cont;
                }    
            }
        }
            else 
            {     
                cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
                     << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
                     << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
                for(int i = results; i <= results; ++i)
                {
                    cout <<"\n" << left << setw(5) << indexingByFname[i]->id << setw(12) << indexingByFname[i]->lastName << setw(12) << indexingByFname[i]->firstName
                         << setw(15) << indexingByFname[i]->sSN << setw(8) << indexingByFname[i]->test1 << setw(8) << indexingByFname[i]->test2 << setw(8) 
                         << indexingByFname[i]->test3 << setw(8) << indexingByFname[i]->test4 << setw(8) << indexingByFname[i]->final << setw(8) << indexingByFname[i]->grade << "\n\n";
                }
                    cout << "\n\nWould you like to continue??"; 
                    cout << "\nEnter 'y' to return to the menu or any key to quit";
                    cout << "\n\nEnter your selection here: ";
                    cin >> cont;
            }
    break;
    //END CASE 6
    case 7:
        //ALLOW USER TO EXIT
         return 0;        
    break;
    }
    //WHILE CONDITION
    }while (cont == 'y' || cont == 'Y');
    return 0;
}
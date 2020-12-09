#include "students.h"
using namespace std;

/**********************/
/*FUNCTION DEFINITIONS*/
/**********************/

/**************************************************************************/
//       FUNCTION THAT READS GRADE.CSV INTO AN ARRAY OF STRUCTS 
     // 1st Parameter studentData array[] is an array of structs
     // 2nd Parameter int size is the array size which directly corresponds
     // to the number of lines to be read in without the header [20]
     // 3rd paramter ifstream& filestream points to the memory address of 
     // the structs ifstream value in the stack.                          
/**************************************************************************/
void readCsvToArray(studentData array[], int size, ifstream& filestream)
{
    //exclude the header column in grades file
    string dummystring;
    getline(filestream, dummystring);
    //Ignore commas from the .csv file
    char delim = ',';
    int index = 0;
    //while loop condition states that: 
    //while not at the end of the file and the index is 
    //less than the array's size....
    while (!filestream.eof() && index < size)
    {
        // Increment and bring in each piece of data
        // in the following order by "."" notation to store into the 
        // data into the struct's array elements 0-19.
        // delim = ignore ',' while reading in this data
        filestream >> array[index].id >> delim;
        getline(filestream, array[index].lastName, delim);
        getline(filestream, array[index].firstName, delim);
        getline(filestream, array[index].sSN, delim);
        filestream >> array[index].test1 >> delim;
        filestream >> array[index].test2 >> delim;
        filestream >> array[index].test3 >> delim;
        filestream >> array[index].test4 >> delim;
        filestream >> array[index].final >> delim;
        getline(filestream, array[index].grade);
    
        ++index;
    }
    // This function returns nothing to main directly
    //  as it is meant to store data
    //  into the array of structures

    // TEST LOOP and cout statement
    // to ensure the file is reading in correctly
    // for (int i = 0; i < size; ++i)
    // cout <<"\n" << array[i].id << ' '<< array[i].lastName << ' ' << array[i].sSN << ' ';
}

/*********************************************************************************/
 // FUNCTION THAT INITIALIZES "LINKS" studentData's ARRAY WITH THE POINTERS ARRAY
 // studentData* indexes is going to store the addresses of StudentData array[] 
 // Struct. The '*' associates the data to be indexed indirectly in this function.
 // In future functions the data can now be accessed by dereferencing the specific 
 // struct members.                                                               
/*********************************************************************************/
void initializeIndexes(studentData* indexes[], studentData array[], int size)
{
    for ( int i = 0;  i < size; ++i)
    {
        // points to the studentsData array's memory address
        // and ties the two arrays by using pointers as to indirectly index studentData array[]
        // into an new array of pointers studentData* indexes[]
        indexes[i] = &array[i]; 
    }

}

/****************************************************/
/*FUNCTION THAT WILL DISPLAY THE USER'S MENU OPTIONS*/
/****************************************************/
void displayMenu()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 10;
    SetConsoleTextAttribute(screen, color);
    cout << "Welcome to The Computer Science Student Database";
    cout << "\nPlease make a selection [ 1 - 6 ] from the options below";
    cout << "\n\n" << setw(2) << "1. Print data in ascending order by last name";
    cout << "\n" << setw(2) << "2. Print data in ascending order by SSN";
    cout << "\n" << setw(2) << "3. Print data in ascending order by first name";
    cout << "\n" << setw(2) << "4. Search by last name";
    cout << "\n" << setw(2) << "5. Search by SSN";
    cout << "\n" << setw(2) << "6. Search by first name";
    cout << "\n" << setw(2) << "7. Exit";
    cout << "\nPlease Enter your choice here: ";
}

/*THIS FUNCTION WILL GET THE USER'S CHOICE
  AND BOUNDS CHECK USER INPUT FOR INCORRECT CHOICES 
  IT WILL RETURN THE CHOICE TO THE FUNCTION CALL THROUGH
  THE returnVal variable. */
int getChoice()
{
    int returnVal;
    cin >> returnVal;
    while ( returnVal < 1 || returnVal > 7 )
    {   
        HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
        int color1 = 12, color2 = 10;
        SetConsoleTextAttribute(screen, color1);
        //notify user of bad choice
        cout << "\nYOU HAVE MADE AN INCORRECT SELECTION.\n";
        SetConsoleTextAttribute(screen, color2);
        cout << "\n";
        cout << "\nPlease make a selection [ 1 - 6 ] from the options below";
        cout << "\n\n" << setw(2) << "1. Print data in ascending order by last name";
        cout << "\n" << setw(2) << "2. Print data in ascending order by SSN";
        cout << "\n" << setw(2) << "3. Print data in ascending order by first name";
        cout << "\n" << setw(2) << "4. Search by last name";
        cout << "\n" << setw(2) << "5. Search by SSN";
        cout << "\n" << setw(2) << "6. Search by first name";
        cout << "\n" << setw(2) << "7. Exit";
        SetConsoleTextAttribute(screen, color1);
        cout << "\n\nPlease re-enter your selection: ";  
        cin >> returnVal;
        SetConsoleTextAttribute(screen, color2);
    }
return returnVal;   
}

/**************************************************************************/
// FUNCTION THAT WILL USE SELECTION SORT TO ORGANIZE THE DATA BY LAST NAME*/
// SELECTION SORT WILL BE USED FOR ALL SORT LISTS*/
// SELECTION SORT HAS ACCESS TO THE CONTENTS OF *array[] BY DEREFERENCING POINTER NOTATION "->"
// INDEXED THE POINT OF THIS FUNCTION IS TO SORT THE INDEXED ARRAY AND NOT THE ORIGINAL DATA
// THEN DISPLAY THE RESULTS WHEN CALLED FOR THE DATA IN STRUCT MEMBER LAST NAME 
/**************************************************************************/
  void sortLastName(studentData* array[], int size)
{
    int startScan, minIndex;
    //ensure that student data is being pointed to IE [StudentData*]
    //unlike an unindexed sort of an array, this one utilizes
    //pointers for the minValue to point to the beginning element the data
    // is stored in the array of structs to access those values.
    studentData* minValue;

    for(startScan = 0; startScan < (size-1); ++startScan)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; ++index)
        {
            //insead of using the '.' to access the struct's data
            //in each array element, pointer indexs use '->'
            //to "unbox" specific struct contents.
            if(array[index]->lastName < minValue->lastName)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    
}
/**************************************************************************/
/*    FUNCTION THAT WILL PRINT THE DATA BY LAST NAME                      */
/**************************************************************************/
void printLName(studentData *array[], int size)
{
    //Sorted Last Names
    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
    for(int i = 0; i < size; ++i)
    {
        cout <<"\n" << left << setw(5) << array[i]->id << setw(12) << array[i]->lastName << setw(12) << array[i]->firstName
             << setw(15) << array[i]->sSN << setw(8) << array[i]->test1 << setw(8) << array[i]->test2 << setw(8) << array[i]->test3
             << setw(8) << array[i]->test4 << setw(8) << array[i]->final << setw(8) <<array[i]->grade;
    }
}



/************************************************************************/
/*  FUNCTION THAT WILL USE SELECTION SORT TO ORGANIZE THE DATA BY SSN */ 
// THIS FUNCTION BEHAVES THE SAME AS SORT LAST NAME BUT WITH THE SSN STRUCT
// MEMBER THIS TIME.
/************************************************************************/
void sortBySsn(studentData* array[], int size)
{ 
  int startScan, minIndex;
    studentData* minValue;

    for(startScan = 0; startScan < (size-1); ++startScan)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; ++index)
        {
            //insead of using the '.' to access the struct's data
            //in each array element, pointer indexs use '->'
            //to "unbox" specific struct contents.
            if(array[index]->sSN < minValue->sSN)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    
}

/**************************************************************************/
/*    FUNCTION THAT WILL PRINT BY SSN                                     */
/**************************************************************************/
void printBySsn(studentData* array[], int size)
{
    //Sort by SSN
    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
    for(int i = 0; i < size; ++i)
    {
        cout <<"\n" << left << setw(5) << array[i]->id << setw(12) << array[i]->lastName << setw(12) << array[i]->firstName
             << setw(15) << array[i]->sSN << setw(8) << array[i]->test1 << setw(8) << array[i]->test2 << setw(8) << array[i]->test3
             << setw(8) << array[i]->test4 << setw(8) << array[i]->final << setw(8) <<array[i]->grade;
    }
}

/**************************************************************************/
/*FUNCTION THAT WILL USE SELECTION SORT TO ORGANIZE THE DATA BY FIRST NAME*/
// THIS FUNCTION BEHAVES THE SAME AS SORT LAST NAME BUT WITH THE FIRST NAME 
// STRUCT MEMBER THIS TIME.
/**************************************************************************/
void sortByFirstName(studentData* array[], int size)
{ 
  int startScan, minIndex;
    studentData* minValue;

    for(startScan = 0; startScan < (size-1); ++startScan)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; ++index)
        {
            if(array[index]->firstName < minValue->firstName)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

/**************************************************************************/
/*FUNCTION THAT WILL PRINT BY FIRST NAME                                  */
/**************************************************************************/
void printByFirstName(studentData* array[], int size)
{
      //Sort by First Name
    cout << "\n\n"<< left << setw(4) << "ID" << setw(13) << "Last Name" << setw(15) << "First Name" << setw(10) 
         << "SSN" << setw(8) << "Test 1" << setw(8) << "Test 2" << setw(8) 
         << "Test 3" << setw(8) << "Test 4" << setw(8) << "Final" << setw(8) << "Grade" << endl;
    for(int i = 0; i < size; ++i)
    
        cout <<"\n" << left << setw(5) << array[i]->id << setw(12) << array[i]->lastName << setw(12) << array[i]->firstName
             << setw(15) << array[i]->sSN << setw(8) << array[i]->test1 << setw(8) << array[i]->test2 << setw(8) << array[i]->test3
             << setw(8) << array[i]->test4 << setw(8) << array[i]->final << setw(8) <<array[i]->grade;
    
    
}

/*******************************************************************/
/* FUNCTION THAT USES POINTERS FOR A BINARY SEARCH OF LAST NAMES  */
/*****************************************************************/

int binSearchByLName(studentData* array[], int size, string value, int* position)
{
    int first = 0, //first array element
        last = size - 1, //last array element
        middle; //midpoint of search
        *position = -1; //position of search value
    bool found = false; // flag
   
 //BINARY SEARCH
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // find the midpoint
        if ( array[middle]->lastName == value ) // if struct's string value is found at array middle
        {
            found = true;
            *position = middle;
        }
        else if ( array[middle]->lastName > value )// If the struct's string value is in the lower half
            last = middle - 1;
        else
            first = middle + 1;// If the struct's string value is in the upper half
    }
    return *position;
}//END SEARCH

/***********************************************************************/
/* FUNCTION THAT USES POINTERS FOR A BINARY SEARCH OF SOCIAL SEC NUMS  */
/**********************************************************************/

int binSearchBySsn(studentData* array[], int size, string value)
{
    int first = 0, //first array element
        last = size - 1, //last array element
        middle, //midpoint of search
        position = -1; //position of search value
    bool found = false; // flag
   
 //BINARY SEARCH
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // find the midpoint
        if ( array[middle]->sSN == value ) // if struct's string value is found at array middle
        {
            found = true;
            position = middle;
        }
        else if ( array[middle]->sSN > value )//If the struct's string value is in the lower half
            last = middle - 1;
        else
            first = middle + 1;//If the struct's string value is in the upper half
    }
    return position;
}//END SEARCH

/*******************************************************************/
/* FUNCTION THAT USES POINTERS FOR A BINARY SEARCH OF FIRST NAMES */
/*****************************************************************/

int binSearchByFName(studentData* array[], int size, string value)
{
    int first = 0, //first array element
        last = size - 1, //last array element
        middle, //midpoint of search
        position = -1; //position of search value
    bool found = false; // flag
   
 //BINARY SEARCH
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // find the midpoint
        if ( array[middle]->firstName == value ) // if struct's string value is found at array middle
        {
            found = true;
            position = middle;
        }
        else if ( array[middle]->firstName > value )//If struct's string the value is in the lower half
            last = middle - 1;
        else
            first = middle + 1;//If struct's string the value is in the upper half
    }
    return position;
}//END SEARCH

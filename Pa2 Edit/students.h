#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//STRUCT TO HOLD GRADES.CSV'S DATA
struct studentData
{
    int id;
    string lastName;
    string firstName;
    string sSN;
    int test1;
    int test2;
    int test3;
    int test4;
    int final;
    string grade;
};
/*FUNCTION DECLARATIONS & PROTOTYPES*/
void readCsvToArray(studentData *array[], int size, ifstream &file);
void initializeIndexes(studentData *indexes[], studentData array[], int size);
void sortLastName(studentData *array[], int size);
void printLName(studentData *array[], int size);
void sortByFirstName(studentData *array[], int size);
void printByFirstName(studentData* array[], int size);
void sortBySsn(studentData *array[], int size);
void printBySsn(studentData *array[], int size);
int binSearchByLName(studentData *array[], int size, string value, int* position);
int binSearchBySsn(studentData* array[], int size, string value);
int binSearchByFName(studentData* array[], int size, string value);

void displayMenu();
int getChoice();
#endif
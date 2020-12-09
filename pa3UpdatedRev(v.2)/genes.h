#ifndef GENES_H
#define GENES_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip> 
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;



//Function Calls
//Sorts
//Searches
//Menu/Prompt
void displayMenu();
string formatThis(string original); 
double count(string , char, char); 
int findCodons(vector<int>& codons, string geneSeq, string codonString);
string revGene( string originalGenome, string revGenome);
void selectGeneSort( vector<int>& stopCodones);





#endif

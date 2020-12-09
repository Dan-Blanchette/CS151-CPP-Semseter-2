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




// Insert a comma function prototype
string formatThis(string original); 
// Counting function prototype
double count(string , char, char); 
//  Search Function prototype
int findCodons(vector<int>& codons, string geneSeq, string codonString);
// Reverse Function prototype
string revGene( string originalGenome, string revGenome);
// Sortiong Function For Vector Elements Based on stopCodones
void selectGeneSort( vector<int>& stopCodones);





#endif

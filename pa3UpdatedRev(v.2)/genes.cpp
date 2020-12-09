#include "genes.h"


/*************************************
*           formatThis               *
*    This function takes a copy of   *
* original string sent in,assigns to *         
* formatted, inserts commas, and then* 
*      returns formatted to main     *
**************************************/
string formatThis(string original)
{
    string formatted = original; //copies original sting to new formatted string
    int null = formatted.length(); //assigns null to the length of the string
    int pos = null; //then we assign position to null
    while(pos > 3) //while the pos is greater than 3, it will keep formatting the string
    { 
        pos = pos - 3;
        formatted.insert(pos, ","); //insterts comma after 3 spaces
    }
    return formatted; //returns formatted string
} 


/*************************************
*              count                 *
*    This function takes a string    *
* and counts how many G&C characters *         
* there are in the sequence, then    * 
*calculates the GC percentage content*
* returns percentage content to main *
**************************************/
double count(string s, char c, char g)
{
    double count_C = 0; //assigns two count variables to 0, one for G and one for C
    double count_G = 0; 
    for(string::size_type i = 0; i < s.length(); i++)
    {   if (s[i] == c) //if the element == C character, count_C increases
        {
            count_C++;
        }
        else if (s[i] == g) //if the element == G character, count_G increases
        {
            count_G++;
        }
    }
    //cout << count_G << "  " << count_C << "\n"; 
    cout << fixed << showpoint << setprecision(3); 
    double GC_Content = count_C + count_G; //assigns the sum of the two character contents  to a total content
    //cout << GC_Content << "\n"; 
    double Percent_GC = (GC_Content / s.length())*100; //gets the percentage of GC content in the whole genome sequence
    return Percent_GC; 
}

/***********************************************
 * FUNCTION REVERSE GENOME                     *
 * THIS FUNCTION REVERSES THE ORDER IN WHICH   *
 * THE VECTOR (originalGenome) ELEMENTS ARE    *
 * READ BY DECREMENTING                        *        
 * THE FOR LOOP.                               *
 * *********************************************/
string revGene( string originalGenome, string revGenome)
{
      for ( int i = originalGenome.length()-1; i >= 0; --i)
    {
        revGenome += originalGenome[i];
    }
    return revGenome;
}

/*************************************
*           FIND FUNCTIONS           *
*    This function takes a copy of   *
* original string sent in,assigns to *         
* formatted, inserts commas, and then* 
*      returns formatted to main     *
**************************************/
//FINDS all CONDONS
int findCodons(vector<int>& codons, string geneSeq, string codonString)
{
    int index = 0; 
    int count = 0;
    while(true)
    {
        index = geneSeq.find(codonString,index);
        if (index == -1 )
        {
            break; 
        }
        
        codons.push_back(index); 
        ++count;
        index++;
        
        }

    return count;
}

/*************************************
*          SORT FUNCTION             *
*    This function sorts the vector's*
*    elements in ascending order     *
*    pertaining to stop codones*     *     
**************************************/

void selectGeneSort( vector<int>& stopCodones)
{
    int startScan, minIndex, minValue;
    int condonSize = stopCodones.size();

    for (startScan = 0; startScan < condonSize -1; ++startScan)
    {
        minIndex = startScan;
        minValue = stopCodones[startScan];

        for (int index = startScan + 1; index < condonSize; ++index)
        {
            if (stopCodones[index] < minValue)
            {
                minValue = stopCodones[index];
                minIndex = index;
            }
        }
        stopCodones[minIndex] = stopCodones[startScan];
        stopCodones[startScan] = minValue;
    }   
}
// Dan Blanchette and Taylor Martin
// Group: Kung Flu Coding
// CS-151
//
// This program will read fasta files with virus genomes
// and evaluate forward and backward for potential genes.
// Then it will output the gene length, GC content, and potential genes found
// based on specific start and stop codones. 
// This will all be formatted into a results fasta file for the biologist
// to compare with known virus strains.

#include "genes.h"
 
int main() 
{
    // VARIABLE DECLARATIONS
    string fileName; 
    string extension = ".fna"; 
    string nameGenome, genomeSequence = " ";
    string revGenomeSeq =" ", spinMeRightRound; 
    char C = 'C'; 
    char G = 'G'; 
    vector <int> startCodone; 
    vector <int> stopCodone;
   
    // GET FILE INPUT FROM THE USER AS A STRING
    cout << "\nPlease enter the File Name of a Genome:  "; 
    getline(cin,fileName); 
    // CREATE FSTREAM OBJECT THAT APPENDS .FNA TO THE USER'S ENTRY
    // AND READ IN THE FILE'S DATA
    fstream fileHandler(fileName + extension, ios::in);
    // ERROR STATEMENT SHOULD FILE BE ENTERED INCORRECTLY
    // OR NOT BE FOUND. 
    if (fileHandler.fail())
    {
        cout << "Error opening the file! \n"; 
        exit(1); 
    } 
    
    cout << "Reading " << fileName << " .... \n\n"; 
    // SET THE POSTION OF THE READ TO 1L IGNORING THE '>' SYMBOL
    fileHandler.seekg(1L);
    // READ THE HEADING AND OUT PUT IT TO CONSOLE
    getline(fileHandler, nameGenome); 
    cout << nameGenome << '\n';
    // WHILE NOT END OF FILE, READ ALL THE FILE'S CONTENTS INTO A TEMP STRING
    // THEN ADD THE TEMPORARY STRING TO THE EMPTY STRING GENOMESEQUENCE.
    while (!fileHandler.eof())
    {
        string temp;
        getline(fileHandler,temp);
        genomeSequence = genomeSequence + temp;
    }

    fileHandler.close(); 
    
    int Genome1_Size = genomeSequence.length(); 
    string Size1 = to_string(Genome1_Size); 
    // ASSIGN AND COPY THE ORIGINAL STRING THEN STORE ITS SIZE INTO
    // SIZE1 STRING
    string formatted1 = formatThis(Size1); 
    // USE FORMATTED1 AND COUNT FUNCTION AS OUTPUT TO THE USER
    cout << "The Genome Sequence has a length of  "<< formatted1 <<  " and has a GC percent content of: " << count(genomeSequence, G, C) << "% \n\n";  
    
    // CALLS FIND FUNCTION FOR EACH TYPE OF CODONES 
    findCodons(startCodone, genomeSequence, "ATG");
    findCodons(stopCodone, genomeSequence, "TGA");
    findCodons(stopCodone, genomeSequence, "TAA"); 
    findCodons(stopCodone, genomeSequence, "TAG"); 
    // SORTS THE ELEMENTS THAT THE CODONES ARE STORED IN TO MAKE THE SEARCH
    // OF STARTS AND STOPS MORE EFFICIENT.
    selectGeneSort(stopCodone); 
    
    int start = startCodone.size(); 
    int stop = stopCodone.size(); 
    // EXPORT THE FILE USING THE USER'S FILENAME INPUT APPENDED WITH A NEW
    // TAG TO DISTINGUISH IT AS THE RESULTS .FNA FILE.
    fileHandler.open( fileName + "_genes.fna", ios::out); 
    int numPotentialGenes = 0; 
    // LOOP THROUGH THE START CODONES
    for(int i = 0; i < start; ++i)
    {
        int startIndex = startCodone[i]; 
        // LOOP THROUGH THE STOP CODONES +2 TO ENSURE THAT 2 ELEMENTS PAST
        // EACH 'T' IS PRINTED
        for(int j = 0; j < stop; ++j)
        {   
            int stopIndex = stopCodone[j]+2; 
            if(startIndex < stopIndex)
            {
                // STOPCODONE - STARTCONDE - 1 TO GET THE SIZE OF THE GENE
                int geneLength = stopIndex - (startIndex - 1); 
                // THAT SIZE IS THEN CHECKED BY THIS IF STATEMENT FOR SIZE AND
                // DIVISIBILITY BY 3.
                if (geneLength > 6 && geneLength%3==0)
                {   
                    // genomeSequence.substr uses startIndex(position) and geneLength(size)
                    // to output the genelength. 
                    string potentialGenes = genomeSequence.substr(startIndex, geneLength); 
                    fileHandler << ">Gene # " << numPotentialGenes + 1; 
                    fileHandler << " Start: " << startIndex << " Stop: " << stopIndex; 
                    fileHandler << " Gene Length: " << geneLength << "\n";
                    int length = potentialGenes.length(); 
                    int startPos = 0; 
                    // the length of potentialGenes.length() is then used as a comparison  
                    // variable for the while loop.
                    while(length > 72)
                    {   
                        // while true this will use the position and size of 72
                        // to ensure that there is a newline added before the break statement
                        fileHandler << potentialGenes.substr(startPos, 72) << "\n"; 
                        length = length - 72; 
                        startPos +=72; 
                        
                    }
                    // if the length is larger than 72 or less than 72
                    // continue reading without recording the data to the file 
                    if (length != 0)
                    {
                        fileHandler << potentialGenes.substr(startPos, length) << "\n";
                    }
                    fileHandler << "\n"; 
                    numPotentialGenes++; 
                    break;
                    
                }  
            }
        }
    } 
    cout << "\n\nFinding potential genes.... \n"; 
    cout << "Found " << numPotentialGenes << " potential genes, gene sequences are writing into "<< fileName + "_genes.fna " << "\n";
    // CLOSE THE FILE
    fileHandler.close();

    // CLEAR ALL VECTOR ELEMENTS FOR REUSE
    startCodone.clear(); 
    stopCodone.clear(); 
    // OPEN A FILE FOR THE RESULTS OF THE REVGENE READ
    fileHandler.open(fileName + "_rev_genes.fna", ios::out);

    // REVERSING THE ORDER OF VECTOR
    revGene(genomeSequence, revGenomeSeq);
    // ASSIGNING REVERSED VECTOR ELEMENTS TO SPINMERIGHTROUND 
    // VARIABLE
    spinMeRightRound = revGene(genomeSequence, revGenomeSeq);
    // REUSING THE THE SAME FIND CODONE FUNCTIONS
    findCodons(startCodone, spinMeRightRound, "ATG");
    findCodons(stopCodone, spinMeRightRound, "TGA");
    findCodons(stopCodone, spinMeRightRound, "TAA");
    findCodons(stopCodone, spinMeRightRound, "TAG"); 
    // RESORT THE REVERSE VECTOR
    selectGeneSort(stopCodone);
    // UTILIZES THE SAME LOOP FROM THE FIRST PASS 
    // FOR THE SECOND "REVERSED" PASS
    int start2 = startCodone.size();
    int stop2 = stopCodone.size();
    int numRevGenes = 0; 
    for(int i = 0; i < start2; ++i)
    {
        int startIndexR = startCodone[i]; 
        
        for(int j = 0; j < stop2; ++j)
        {   
            int stopIndexR = stopCodone[j]+2; 
            if(startIndexR < stopIndexR)
            {
                int geneLengthR = stopIndexR - (startIndexR - 1); 
                
                if (geneLengthR > 6 && geneLengthR%3==0)
                {   
                    string potentialGenes2 = spinMeRightRound.substr(startIndexR, geneLengthR); 
                    //write to file
                    fileHandler << ">Gene # " << numRevGenes + 1 << "\n"; 
                    fileHandler << " Start: " << startIndexR << " Stop: " << stopIndexR;
                    fileHandler << " Gene Length: " << geneLengthR << "\n";
                    
                    int length2 = potentialGenes2.length(); 
                    int startPos2 = 0; 
                    
                    while(length2 > 72)
                    {   
                        fileHandler << potentialGenes2.substr(startPos2, 72) << "\n"; 
                        length2 = length2 - 72; 
                        startPos2 +=72; 
                        
                    }
                    if (length2 != 0)
                    {
                        fileHandler << potentialGenes2.substr(startPos2, length2) << "\n";
                    }
                    fileHandler << "\n"; 
                    numRevGenes++; 
                    break;
                }  
            }
        }
    }
    cout << "\nReversing genome sequence... \n"; 
    cout << "\nFinding potential genes... \n"; 
    cout << "\nFound " << numRevGenes << " potential genes, gene sequences are writing into "<< fileName + "_rev_genes.fna " << "\n";
    // CLOSE THE FILE
    fileHandler.close();

    return 0; 
}
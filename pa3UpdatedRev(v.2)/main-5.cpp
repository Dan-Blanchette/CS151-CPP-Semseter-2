// Dan Blanchette and Taylor Martin
// Kung Flu Coding
// CS-151
// This program will take any researcher's virus genome files
// and display potential genes, percentage of GC content, and 
// record all potential genes and their original file locations to a 
// .fna report file.


#include "genes.h"
 
int main() 
{
    string fileName; 
    string extension = ".fna"; 
    string nameGenome, genomeSequence = " ";
    string revGenomeSeq =" ", spinMeRightRound; 
    char C = 'C'; 
    char G = 'G'; 
    vector <int> startCodone; 
    vector <int> stopCodone;
   
    
    cout << "\nPlease enter the File Name of a Genome:  "; 
    getline(cin,fileName); 
    
    fstream fileHandler(fileName + extension, ios::in); 
    if (fileHandler.fail())
    {
        cout << "Error opening the file! \n"; 
        exit(1); 
    } 
    
    cout << "Reading " << fileName << " .... \n\n"; 
    fileHandler.seekg(1L);
    getline(fileHandler, nameGenome); 
    cout << nameGenome << '\n';
    
    while (!fileHandler.eof())
    {
        string temp;
        getline(fileHandler,temp);
        genomeSequence = genomeSequence + temp;
    }

    fileHandler.close(); 
  
    int Genome1_Size = genomeSequence.length(); 
    string Size1 = to_string(Genome1_Size); 
    string formatted1 = formatThis(Size1); 
    cout << "The Genome Sequence has a length of "<< formatted1 <<  " and has a GC percent content of: " << count(genomeSequence, G, C) << "% \n\n";  
    
    
    findCodons(startCodone, genomeSequence, "ATG");
    findCodons(stopCodone, genomeSequence, "TGA");
    findCodons(stopCodone, genomeSequence, "TAA"); 
    findCodons(stopCodone, genomeSequence, "TAG"); 
    
    selectGeneSort(stopCodone); 
    
    int start = startCodone.size(); 
    int stop = stopCodone.size(); 
    fileHandler.open( fileName + "_genes.fna", ios::out); 
    int numPotentialGenes = 0; 
    for(int i = 0; i < start; ++i)
    {
        int startIndex = startCodone[i]; 
        
        for(int j = 0; j < stop; ++j)
        {   
            int stopIndex = stopCodone[j]+2; 
            if(startIndex < stopIndex)
            {
                int geneLength = stopIndex - (startIndex - 1); 
                if (geneLength > 6 && geneLength%3==0)
                {   
                    
                    string potentialGenes = genomeSequence.substr(startIndex, geneLength); 
                    fileHandler << ">Gene # " << numPotentialGenes + 1; 
                    fileHandler << " Start: " << startIndex << " Stop: " << stopIndex; 
                    fileHandler << " Gene Length: " << geneLength << "\n";
                    int length = potentialGenes.length(); 
                    int startPos = 0; 
                    
                    while(length > 72)
                    {   
                        fileHandler << potentialGenes.substr(startPos, 72) << "\n"; 
                        length = length - 72; 
                        startPos +=72; 
                        
                    }
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
    
    fileHandler.close();

    // CLEAR ALL VECTORS
    startCodone.clear(); 
    stopCodone.clear(); 

    fileHandler.open(fileName + "_rev_genes.fna", ios::out);

    // REVERSING THE ORDER OF VECTOR
    revGene(genomeSequence, revGenomeSeq);
    // ASSIGNING REVERSED VECTOR ELEMENTS TO SPINMERIGHTROUND 
    // VARIABLE
    spinMeRightRound = revGene(genomeSequence, revGenomeSeq);

    findCodons(startCodone, spinMeRightRound, "ATG");
    findCodons(stopCodone, spinMeRightRound, "TGA");
    findCodons(stopCodone, spinMeRightRound, "TAA");
    findCodons(stopCodone, spinMeRightRound, "TAG"); 

    selectGeneSort(stopCodone);

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
    
    fileHandler.close();

    return 0; 
}
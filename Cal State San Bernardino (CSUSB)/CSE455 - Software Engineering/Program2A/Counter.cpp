// Name: James Small
// Program: 2A
// Class: CSE455
// Description: Counter class Implementation File

#include "Counter.h"
#include <fstream>

using namespace std;

// This is the default constructor

Counter::Counter(string fileName)
{
    this->fileToRead = fileName;
}

// This method calcualtes the LOC in a file

int Counter::calculateLOC()
{
    ifstream infile;
    
    infile.open(fileToRead.c_str());
    
    int count = 0;
    string currentString;
    
    while (getline(infile,currentString))
        if ((currentString.find_first_not_of(' ') != string::npos))
            if (!(currentString[0] == '/'))
                count++;
    
    infile.close();
    
    return count;
}
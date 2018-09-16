// Name: James Small
// Program: 4B
// Class: CSE455
// Description: FileCheck class implementation file

#include "FileCheck.h"
#include <fstream>

// This method takes a string and returns true or false if a float

bool FileCheck::fileExist(string fileToCheck)
{
    ifstream infile;

    infile.open(fileToCheck.c_str());

    infile.close();

    return infile;
}
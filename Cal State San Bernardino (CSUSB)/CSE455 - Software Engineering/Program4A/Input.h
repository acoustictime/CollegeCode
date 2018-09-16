// Name: James Small
// Program: 3B
// Class: CSE455
// Description: Input class Header File

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "StringToFloat.h"
#include "FileCheck.h"

using namespace std;

class Input
{
public:
    Input();
    void writeToFile();
    void readFromFile();
    void modifyFile();
    
private :
    string fileToRead;
    float enterNumber();
    bool enterNewFileName(bool exists);
    StringToFloat stringToFloat;
    FileCheck fileCheck;
};
#endif

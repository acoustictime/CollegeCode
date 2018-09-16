// Name: James Small
// Program: 3B
// Class: CSE455
// Description: Input class Header File

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "StringToFloat.h"

using namespace std;

class Input
{
    public:
        Input(string fileName);
        void writeToFile();
        void readFromFile();
        void modifyFile();

    private :
        string fileToRead;
        float enterNumber();
        StringToFloat stringToFloat;
};
#endif

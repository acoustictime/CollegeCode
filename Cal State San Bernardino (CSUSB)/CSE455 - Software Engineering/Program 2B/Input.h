// Name: James Small
// Program: 2B
// Class: CSE455
// Description: Input class Header File

#ifndef INPUT_H
#define INPUT_H

#include <string>

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

};
#endif

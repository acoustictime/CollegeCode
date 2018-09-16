// Name: James Small
// Program: 2A
// Class: CSE455
// Description: Counter class Header File

#ifndef COUNTER_H
#define COUNTER_H

#include <string>

using namespace std;

class Counter
{
    public:
        Counter(string fileName);
        int calculateLOC();
 
    private :
        string fileToRead;
    
};
#endif

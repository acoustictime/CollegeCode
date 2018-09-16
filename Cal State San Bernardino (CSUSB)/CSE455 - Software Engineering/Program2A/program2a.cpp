// Name: James Small
// Program: 2A
// Class: CSE455
// Description: Main Program to count lines of code in a file

#include <iostream>
#include <string>
#include "Counter.h"

using namespace std;

int main()
{
    string file;
    
    cout << "Enter the file name to count lines from: ";
    cin >> file;
    
    Counter count(file);
    
    cout << "LOC for " << file << " = " << count.calculateLOC() << endl;
    
    return 0;
}
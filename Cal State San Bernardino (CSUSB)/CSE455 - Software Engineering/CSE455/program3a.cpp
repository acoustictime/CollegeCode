// Name: James Small
// Program: 3A
// Class: CSE455
// Description: Main Program to count lines of code in all files of a program

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
    count.calculateLOC();
    count.displayReport();
    
    return 0;
}

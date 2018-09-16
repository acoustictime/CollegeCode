// Name: James Small
// Program: 1B
// Class: CSE455
// Description: Input class Implementation File

#include "Input.h"
#include <fstream>
#include <iostream>

using namespace std;

// This is the default constructor

Input::Input(string fileName)
{
    this->fileToRead = fileName;
}

// This method asks user for a set of numbers and outputs them to a file

void Input::writeToFile()
{
    int count = 0;
    float currentValue;
    
    cout << "Enter the amount of numbers to write: ";
    
    cin >> count;
    
    ofstream outfile;
    
    outfile.open(fileToRead.c_str());
    
    for (int i = 0; i < count; i++) {
        
        cout << "Enter number " << i + 1 << ": ";
        
        cin >> currentValue;
        
        if (i == count - 1)
            outfile << currentValue;
        else
            outfile << currentValue << " ";
    }
    
    outfile.close();
}

// This method reads in a set of numbers from a file and displays them on screen

void Input::readFromFile()
{
    ifstream infile;
    
    infile.open(fileToRead.c_str());
    
    float currentValue = 0;
    
    while (!infile.eof()) {
        infile >> currentValue;
        cout << currentValue << endl;
    }
    
    infile.close();
}
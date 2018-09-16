// Name: James Small
// Program: 2B
// Class: CSE455
// Description: Input class Implementation File

#include "Input.h"
#include <fstream>
#include <iostream>
#include <vector>

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

// This method modifies an existing file one line at a time.

void Input::modifyFile()
{
    ifstream infile;

    infile.open(fileToRead.c_str());

    float currentValue = 0;
    int choice;
    vector<float> currentNumbers;
    bool acceptAllNumbers = false;

    while (!infile.eof()) {
        infile >> currentValue;

        if (acceptAllNumbers) {
            currentNumbers.push_back(currentValue);
        } else {
            cout << "\nWhat would you like to do with this number, " << currentValue << "?\n";
            cout << "Enter 1 to accept this number.\n";
            cout << "Enter 2 to replace this number.\n";
            cout << "Enter 3 to delete this number.\n";
            cout << "Enter 4 to insert a new number after current number.\n";
            cout << "Enter 5 to accept the remainder of the numbers.\n";
            cout << "Choice: ";

            cin >> choice;

            switch (choice) {
                case 1:
                    currentNumbers.push_back(currentValue);
                    break;
                case 2:
                    currentNumbers.push_back(enterNumber());
                    break;
                case 3:
                    break;
                case 4:
                    currentNumbers.push_back(currentValue);
                    currentNumbers.push_back(enterNumber());
                    break;
                case 5:
                    currentNumbers.push_back(currentValue);
                    acceptAllNumbers = true;
                    break;
                default:
                    break;
            }
        }
    }

    infile.close();

    cout << "\nWould you like to replace the current file or create a new file?\n";
    cout << "Enter 1 to replace the current file's contents.\n";
    cout << "Enter 2 to create a new file.\n";
    cout << "Choice: ";

    cin >> choice;

    if (choice == 2) {
        cout << "Enter the file name to access: ";
        cin >> fileToRead;
    }

    ofstream outfile;

    outfile.open(fileToRead.c_str());

    for (int i = 0; i < currentNumbers.size(); i++) {
        if (i == currentNumbers.size() - 1)
            outfile << currentNumbers[i];
        else
            outfile << currentNumbers[i] << " ";
    }
}

float Input::enterNumber()
{
    float current = 0;

    cout << "\nEnter number: ";

    cin >> current;

    return current;
}
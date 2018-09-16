// Name: James Small
// Program: 2B
// Class: CSE455
// Description: Program to input, output, or modify a file.

#include <iostream>
#include <string>
#include "Input.h"

using namespace std;

int main()
{
    int choice = 0;

    cout << "What would you like to do?\n";
    cout << "Enter 1 to read from file.\n";
    cout << "Enter 2 to write to file.\n";
    cout << "Enter 3 to modify a file.\n";
    cout << "Enter 0 to quit.\n";
    cout << "Choice: ";

    cin >> choice;

    if (choice != 0) {

        string file;

        cout << "Enter the file name to access: ";
        cin >> file;

        Input input(file);

        if (choice == 1)
            input.readFromFile();
        else if (choice == 2)
            input.writeToFile();
        else if (choice == 3)
            input.modifyFile();
    }

    return 0;
}
// Name: James Small
// Program: 4B
// Class: CSE455
// Description: Program to input, output, or modify, and calculate linear regression.

#include <iostream>
#include <string>
#include <stdlib.h> // for atoi
#include <ctype.h> // for isdigit
#include "Input.h"
#include "LinearRegression.h"

using namespace std;

int main()
{
    char choice = 0;
    bool choiceGood = false;

    do {
        cout << "What would you like to do?\n";
        cout << "Enter 1 to read from file.\n";
        cout << "Enter 2 to write to file.\n";
        cout << "Enter 3 to modify a file.\n";
        cout << "Enter 4 to calculate linear regression.\n";
        cout << "Enter 0 to quit.\n";
        cout << "Choice: ";

        cin >> choice;

        if (isdigit(choice)) {
            if (atoi(&choice) >= 0 && atoi(&choice) < 5)
                choiceGood = true;
            else
                cout << "\nInvalid Choice, Try again\n\n";
        } else
            cout << "\nInvalid Choice, Try again\n\n";

        cin.ignore(INT_MAX,'\n');

    } while (!choiceGood);

    if (choice != '0') {

        

        if (choice == '1') {
            Input input;
            input.readFromFile();
        }
        else if (choice == '2') {
            Input input;
            input.writeToFile();
        }
        else if (choice == '3') {
            Input input;
            input.modifyFile();
        }
        else if (choice == '4') {
            LinearRegression linear;
            
            if (linear.getGood())
                linear.report();
        }
    }

    return 0;
}
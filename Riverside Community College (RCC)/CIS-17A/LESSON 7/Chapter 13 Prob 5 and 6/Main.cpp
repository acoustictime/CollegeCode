// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 10-14-06															*
// *																	*
// * This program lets you choose between 2 programs to run.  The first *
// * prompts the user for the size of an array and then lets you		*
// * populate the array.  It will the output the highest, lowest, and   *
// * average values of the array.  The second program lets you enter    *
// * the hourly rate, and the amount of hours worked for 7 employees.   *
// * It then outputs these values.										*
// **********************************************************************

#include <iostream>
#include "FloatingArray.h"
#include "PayRoll.h"

using namespace std;

void menu();

int main()
{
	int menuchoice;

	while (menuchoice != 3) // Loop used to determine when the user wants to quit
	{
		menu();
		cin >> menuchoice;

		while (menuchoice < 1 || menuchoice > 3) // Loop used to make sure menuchoice is 1, 2, or 3
		{
			cout << "\n\nYour choice must be either 1, 2, or 3\n\n";
			menu();
		}
		
		if (menuchoice == 1) // Loop used if user selects choice 1 from the menu
		{
			int size, value;
				
			cout << "\nEnter the size of the array: ";
			cin >> size;
			cout << endl;
	
			FloatingArray array(size);

			cout << "Enter a value for each element of the array\n\n";

			for (int index = 0; index < size; index++) // Loop used input the values into the array
			{
				cout << "Enter the " << index + 1 << " value: ";
				cin >> value;
				
				if (!array.enter(index, value)) // Used if an invalid element is tried to be accessed
				{
					cout << "\nInvalid element value\n";
				}
			}		

			cout << "\n*** Here are the Results ***\n\n";
			
			if (!array.retrieve((array.highest()), value)) // Used if an invalid element is tried to be accessed
			{
				cout << "Invalid Subcript for this array\n\n";
			}
			cout << "The highest value in the array is " << value;
			
			if (!array.retrieve((array.lowest()), value)) // Used if an invalid element is tried to be accessed
			{
				cout << "Invalid Subcript for this array\n\n";
			}
			
			cout << "\nThe lowest value in teh array is " << value;
			cout << "\nThe average of the values in the array is " << array.average();
			cout << endl << endl;	
		}
		else if (menuchoice == 2) // Loop used if user selects program 2
		{
			const int size = 7;
			double ratetemp, hourstemp, paytemp;
			
			PayRoll employee[size];
		
			cout << "\nEnter the employees' info\n\n";

			for (int index = 0; index < size; index++) // Loop used to allow the input of the hourly rate and hours worked
			{
				cout << "Enter employee number " << index + 1 << "'s hourly rate: ";
				cin >> ratetemp;

				cout << "Enter employee number " << index + 1 << "'s hours worked: ";
				cin >> hourstemp;

				cout << endl;

				while(!employee[index].input(hourstemp, ratetemp)) // Loop used to make sure hours entered is between 0 and 60
				{
					cout << "The amount of hours can't be between 0 and 60\n";
					cout << "\nEnter employee number " << index + 1 << "'s hours worked: ";
					cin >> hourstemp;
					cout << endl;
				}
			}
				
			cout << "\n\n*** Here are the results ***\n\n";
			cout << "Employee # \tGross Pay\n\n";

			for (index = 0; index < size; index++) // Loop used to display the pay for each employee
			{
				employee[index].retreive(hourstemp, ratetemp, paytemp);
				
				cout << "Employee " << index + 1 << "\t" << "$" << paytemp << endl;
				
			}

			cout << endl;		
		}
	}
return 0;
}

// **********************************************************************
// * Definition of the function: menu								    *
// * This function displays the menu allowing the user to select which  *
// * which program to run.											    *
// **********************************************************************

void menu()
{
	cout << "*** Which program would you like to run ***\n\n";
	cout << "1. Array Program\n";
	cout << "2. Payroll Program\n";
	cout << "3. Quit\n\n";
	cout << "Your choice is: ";
}
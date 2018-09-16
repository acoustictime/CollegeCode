// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 10-11-06															*
// *																	*
// * This program takes as it's input, 20 numbers, and sorts them using	*
// * the bubble sort and selection sort methods.  It then displays		*
// * how many swaps it took each type of sort to accomplish it's goal.	*
// **********************************************************************

#include <iostream>
#include <string>
#include "Date.h"
#include "PopRate.h"

using namespace std;

void menu();

int main()
{
	
	Date entereddate;
	PopRate populationrates;

	int tempday, tempmonth, tempyear, choice;
	int temppop, tempbirth, tempdeath, menuchoice;
	
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
			cout << "\nEnter an interger for the month: ";
			cin >> tempmonth;

			while (!entereddate.getmonth(tempmonth)) // Loop used to make sure month is between 1 and 12
			{
				cout << "\nThe month must be an interger between 1 and 12: ";
				cin >> tempmonth;
			}
	
			cout << "\nEnter an interger for the day: ";
			cin >> tempday;

			while (!entereddate.getday(tempday)) // Loop used to make sure day between 1 and 31
			{
			cout << "\nThe day must be between 1 and 31: ";
			cin >> tempday;
			}

			cout << "\nEnter an interger for the year: ";
			cin >> tempyear;
			entereddate.getyear(tempyear);

			entereddate.menu();
			cin >> choice;

			while (choice < 1 || choice > 3) // Loop used to make sure menuchoice for the date program is between 1 and 3
			{
				cout << "\nThe choice must be between 1 and 3: \n\n";
				entereddate.menu();
				cin >> choice;
			}

			entereddate.datetype(choice);
		}
		else if (menuchoice == 2) // Loop used if user selects program 2
		{
			cout << "\nEnter the current population of at least 1: ";
			cin >> temppop;

			while (!populationrates.getpop(temppop)) // Loop used to make sure population is greater than 0
			{
				cout << "\nThe population must be great than 0\n\nEnter the current population of at least 1: ";
				cin >> temppop;
			}

			cout << "\nEnter the amount of deaths: ";
			cin >> tempdeath;

			while (!populationrates.getdeaths(tempdeath)) // Loop used to make sure deaths is greater than 1
			{
				cout << "\nThe amount of deaths must be greater than 0\n\nEnter the amount of deaths: ";
				cin >> tempdeath;
			}

			cout << "\nEnter the amount of births: ";
			cin >> tempbirth;

			while (!populationrates.getbirths(tempbirth)) // Loop used to make sure births is greater than 1
			{
				cout << "\nThe amount of births must be greater than 0\n\nEnter the amount of births: ";
				cin >> tempbirth;
			}

			cout << "\n\nThe Birth Rate is " << (populationrates.birthrate() * 100) << "% and the Death Rate is " << (populationrates.deathrate() * 100) << "%.\n\n";
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
	cout << "1. Date Program\n";
	cout << "2. Population Program\n";
	cout << "3. Quit\n\n";
	cout << "Your choice is: ";
}
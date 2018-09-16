// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 11-29-06															*
// *																	*
// * This program ask for values for the day, month, and year, and then *
// * displays the date in the format you would like.					*
// **********************************************************************

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date entereddate;
	
	int tempday, tempmonth, tempyear, choice;

	cout << "\nEnter an interger for the month: ";
	
	try // Used to check if the month is correct, if not, program ends
	{
		cin >> tempmonth;
		entereddate.getmonth(tempmonth);
	}
	catch (Date::InvalidMonth)
	{
		cout << "\nInvalid month entered, Game Over!!\n\n";
		return -1;
	}
		
	cout << "\nEnter an interger for the day: ";
	
	try // Used to check if the day is correct, if not, program ends
	{
		cin >> tempday;
		entereddate.getday(tempday);
	}
	catch (Date::InvalidDay)
	{
		cout << "\nInvalid day entered, Game Over!!\n\n";
		return -1;
	}

	cout << "\nEnter an interger for the year: ";
	
	try // Used to check if the year is correct, if not, program ends
	{
		cin >> tempyear;
		entereddate.getyear(tempyear);
	}
	catch (Date::InvalidYear)
	{
		cout << "\nInvalid year entered, Game Over!!\n\n";
		return -1;
	}

	entereddate.menu();
	cin >> choice;

	while (choice < 1 || choice > 3) // Loop used to make sure menuchoice for the date program is between 1 and 3
	{
		cout << "\nThe choice must be between 1 and 3: \n\n";
		entereddate.menu();
		cin >> choice;
	}

	entereddate.datetype(choice);

return 0;
}
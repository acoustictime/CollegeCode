// Date.cpp: implementation of the Date class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "Date.h"

using namespace std;

const int size = 10;

Date::Date() // Constructor
{
}

// **********************************************************************
// * Definition of the function: Date::getmonthname					    *
// * This class member function determines the name of the month that   *
// * was selected and then sets the monthname string to the value.	    *
// **********************************************************************

void Date::getmonthname()
{
	if (month == 1)
		monthname = "January";
	else if (month == 2)
		monthname = "February";
	else if (month == 3)
		monthname = "March";
	else if (month == 4)
		monthname = "April";
	else if (month == 5)
		monthname = "May";
	else if (month == 6)
		monthname = "June";
	else if (month == 7)
		monthname = "July";
	else if (month == 8)
		monthname = "August";
	else if (month == 9)
		monthname = "September";
	else if (month == 10)
		monthname = "October";
	else if (month == 11)
		monthname = "November";
	else if (month == 12)
		monthname = "December";
}

// **********************************************************************
// * Definition of the function: Date::getmonth						    *
// * This class member function takes as it's arguements an interger for*
// * the month that the user entered.  It then checks if the value is   *
// * valid and throws an error if it is.							    *
// **********************************************************************

void Date::getmonth(int tempmonth)
{
	if (tempmonth < 1 || tempmonth > 31)
		throw InvalidMonth();

	month = tempmonth;
}

// **********************************************************************
// * Definition of the function: Date::getday						    *
// * This class member function takes as it's arguements an interger for*
// * the day that the user entered.  It then checks if the value is     *
// * valid and throws an error if it is.							    *
// **********************************************************************

void Date::getday(int tempday)
{
	if (tempday < 1 || tempday > 31)
		throw InvalidDay();

	day = tempday;
}

// **********************************************************************
// * Definition of the function: Date::getyear						    *
// * This class member function takes as it's arguements an interger for*
// * the year that the user entered.  It then checks if the value is    *
// * valid and throws an error if it is.							    *
// **********************************************************************

void Date::getyear(int tempyear)
{
	if (tempyear < 1000 || tempyear > 9999)
		throw InvalidYear();

	year = tempyear;
}

// **********************************************************************
// * Definition of the function: Date::datetype						    *
// * This class member function takes as it's arguements an interger for*
// * the user's choice.  Depending on the user's choice, it will output *
// * the date entered in the corresponding format.  				    *
// **********************************************************************

void Date::datetype(int choice)
{
	if (choice == 1) // Used if user selected date format 1
	{
		char *ptr;
		ptr = new char[size]; // A dynamically created array to store the C-string for the year

		itoa(year, ptr, 10); // Used to convert an interger to a C-string so I can output the last 2 digits of the year only

		cout << endl << month << "/" << day << "/" << ptr[strlen(ptr) - 2] << ptr[strlen(ptr) - 1]; // Strlen used to help out the last two digits of the year
		cout << endl << endl;
		
		delete [] ptr; // Deletes the dynamically created array to store the C-string for the year
	}
	else if (choice == 2) // Used if user selected date format 1
	{
		getmonthname();
		cout << endl << monthname << " " << day << ", " << year;
		cout << endl << endl;;
	}
	else if (choice == 3) // Used if user selected date format 1
	{
		getmonthname();
		cout << endl << day << " " << monthname << " " << year;
		cout << endl << endl;
	}
}

// **********************************************************************
// * Definition of the function: Date::menu							    *
// * This class member function displays the menu for how the user can  *
// * output the date.												    *
// **********************************************************************

void Date::menu()
{
	cout << "\nPlease select a date format below\n\n";
	cout << "1. 12/25/05\n";
	cout << "2. December 25, 2005\n";
	cout << "3. 25 December 2005\n\n";
	cout << "Your choice is: ";
}

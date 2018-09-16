// Problem2.cpp: implementation of the Problem2 class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Problem2.h"

using namespace std;

const int namesize = 20;

Problem2::Problem2()
{
	name = new char [namesize];	//Declares a new character array for the name
}

// **********************************************************************
// * Definition of the function: PayRoll::paycalc					    *
// * This private memeber function calculates the employees' pay based  *
// * on their payrate and hours worked.								    *
// **********************************************************************

void Problem2::paycalc()
{
	if (hours <= 20) // Used if hours is less than 20
	{
		pay = ((20 - hours) * rate);
	}
	else if (hours > 20 && hours < 40) // Used if hours is between 20 and 40
	{
		pay = (20 * rate) + ((hours - 20) * (rate * 2));
	}
	else if (hours >= 40) // Used if hous is over 40
	{
		pay = (20 * rate) + (20 * (rate * 2)) + ((hours - 40) * (rate * 3));
	}
}

// **********************************************************************
// * Definition of the function: PayRoll::inputname					    *
// * This member function takes as it's arguements a pointer to a       *
// * character array and copies it into local variable for the name.    *
// **********************************************************************

void Problem2::inputname(char *n)
{
	strcpy(name, n);
}

// **********************************************************************
// * Definition of the function: PayRoll::inputrate					    *
// * This member function takes as it's arguements a double for the     *
// * hourly rate.  It returns true if the hourly rate is greater than 0.*
// * It then sets the rate internal value to the value entered.         *
// **********************************************************************

bool Problem2::inputrate(double r)
{
	bool status;

	if (r < 0) // Checks if rate is less than 0
	{
		status = false;
	}
	else
	{
		rate = r;
		status =true;
	}
return status;
}

// **********************************************************************
// * Definition of the function: PayRoll::inputhours				    *
// * This member function takes as it's arguements a double for the     *
// * hours worked.  It returns true if the hours worked is between 0 and*
// * 60.  It then sets the hours internal value to the value entered.   *
// **********************************************************************

bool Problem2::inputhours(double h)
{
	bool status;

	if (h < 0 || h > 60) // Used to make sure the hours entered is between 0 and 60
	{
		status = false;
	}
	else
	{
		hours = h;
		status = true;
	}
	
	Problem2::paycalc(); // Calculates the pay

return status;
}

// **********************************************************************
// * Definition of the function: PayRoll::retreive					    *
// * This member function takes as it's arguemnts a double reference    *
// * parameter for the hours, rate, and pay.  It then sets these values *
// * equal to the internal values stored for these valuables.		    *
// **********************************************************************

void Problem2::retreive(double &h, double &r, double &p)
{
	h = hours;
	r = rate;
	p = pay;
}

// **********************************************************************
// * Definition of the function: PayRoll::getname					    *
// * This member function returns the name stored in a local char array.*
// **********************************************************************

const char *Problem2::getname()
{
	return name;
}

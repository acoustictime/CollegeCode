// PayRoll.cpp: implementation of the PayRoll class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "PayRoll.h"

using namespace std;

PayRoll::PayRoll()
{

}

// **********************************************************************
// * Definition of the function: PayRoll::paycalc					    *
// * This private memeber function calculates the employees' pay based  *
// * on their payrate and hours worked.								    *
// **********************************************************************

void PayRoll::paycalc()
{
	pay = rate * hours;
}

// **********************************************************************
// * Definition of the function: PayRoll::input						    *
// * This member function takes as it's arguements a double for the     *
// * hours worked and the employees hourly rate.  It returns true if the*
// * hours worked is between 0 and 60.  It then sets the values inputted*
// * to the internal variables used to store them.					    *
// **********************************************************************

bool PayRoll::input(double h, double r)
{
	bool status;

	if (h < 0 || h > 60) // Used to make sure the hours entered is between 0 and 60
	{
		hours = 0;
		status = false;
	}
	else
	{
		hours = h;
		rate = r;
		status = true;
	}
	
	PayRoll::paycalc(); // Calcultates the pay

return status;
}

// **********************************************************************
// * Definition of the function: PayRoll::retreive					    *
// * This member function takes as it's arguemnts a double reference    *
// * parameter for the hours, rate, and pay.  It then sets these values *
// * equal to the internal values stored for these valuables.		    *
// **********************************************************************

void PayRoll::retreive(double &h, double &r, double &p)
{
	h = hours;
	r = rate;
	p = pay;
}

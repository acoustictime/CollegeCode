// NumDays.cpp: implementation of the NumDays class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include "NumDays.h"

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// **********************************************************************
// * Definition of the function: NumDays::NumDays					    *
// * This is a constructor member function.  It takes as it's parameter,*
// * a double for the amount of hours to be stored.  It then stores     *
// * this value in the member variable along with the amount of days    *
// * the hours represents.  										    *
// **********************************************************************

NumDays::NumDays(double h)
{
	hours = h;
	days = h / DayHours;
}

// **********************************************************************
// * Definition of the function: NumDays::NumDays					    *
// * This is a constructor member function.  This function doesn't take *
// * a parameter and is only used for temp purposes.				    *
// **********************************************************************

NumDays::NumDays()
{
}

NumDays::~NumDays()
{
}

// **********************************************************************
// * Definition of the function: NumDays::InputHours				    *
// * This member function takes as it's parameters a double for the     *
// * amount of hours.  It then checks if the amount of hours is greater *
// * than 0.  If it is, the hours and days are stored in the internal   *
// * member variables.												    *
// **********************************************************************

bool NumDays::InputHours(double h)
{
	bool status;

	if (h <= 0)
	{
		status = false;
	}
	else
	{
		hours = h;
		days = h / DayHours;
		status = true;
	}

return status;
}

// **********************************************************************
// * Definition of the function: NumDays::InputDays						*
// * This member function takes as it's parameters a double for the     *
// * amount of days.  It then checks if the amount of days is greater	*
// * than 0.  If it is, the hours and days are stored in the internal   *
// * member variables.												    *
// **********************************************************************

bool NumDays::InputDays(double d)
{
	bool status;

	if (d <= 0)
	{
		status = false;
	}
	else
	{
		days = d;
		hours = d * DayHours;
		status = true;
	}

return status;
}

// **********************************************************************
// * Definition of the function: NumDays::operator +					*
// * This member function takes as it's parameter a const NumDays       *
// * reference object for the right variable.  It then adds the days and*
// * hours from both objects together.								    *
// **********************************************************************

NumDays NumDays::operator + (const NumDays &right)
{
	NumDays temp;

	temp.hours = hours + right.hours;
	temp.days = days + right.days;

return temp;
}

// **********************************************************************
// * Definition of the function: NumDays::operator -					*
// * This member function takes as it's parameter a const NumDays       *
// * reference object for the right variable.  It then subtracts  the   *
// * days and hours from both objects together.						    *
// **********************************************************************

NumDays NumDays::operator - (const NumDays &right)
{
	NumDays temp;

	temp.hours = hours - right.hours;
	temp.days = days - right.days;

return temp;
}

// **********************************************************************
// * Definition of the function: NumDays::operator++					*
// * This member function is a post increament operator and increases   *
// * the amount of hours by 1 and then recalculates the days.		    *
// **********************************************************************

NumDays NumDays::operator++()
{
	++hours;
	days = hours / 8;

return *this;
}

// **********************************************************************
// * Definition of the function: NumDays::operator++					*
// * This member function is a post increament operator and increases	*
// * the amount of hours by 1 and then recalculates the days.  It takes *
// * it's parameter an int.  It then creates a temp NumDays object.  It *
// * returns the temp NumDays object.								    *
// **********************************************************************

NumDays NumDays::operator++(int)
{
	NumDays temp(hours);

	hours++;
	days = hours / 8;

return temp;
}
	
// **********************************************************************
// * Definition of the function: NumDays::operator--					*
// * This member function is a post increament operator and decreases   *
// * the amount of hours by 1 and then recalculates the days.		    *
// **********************************************************************

NumDays NumDays::operator--()
{
	--hours;
	days = hours / 8;

return *this;
}
		
// **********************************************************************
// * Definition of the function: NumDays::operator--					*
// * This member function is a post increament operator and decreases	*
// * the amount of hours by 1 and then recalculates the days.  It takes *
// * it's parameter an int.  It then creates a temp NumDays object.  It *
// * returns the temp NumDays object.								    *
// **********************************************************************

NumDays NumDays::operator--(int)
{
	NumDays temp(hours);

	hours--;
	days = hours / 8;

return temp;
}

// TimeOff.cpp: implementation of the TimeOff class.
//
//////////////////////////////////////////////////////////////////////

#include "TimeOff.h"
#include "NumDays.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// **********************************************************************
// * Definition of the function: TimeOff::TimeOff						*
// * This is the constructor member function.  It takes as it's			*
// * parameters, a c-string for the employee's name and an int for their*
// * id.  It then sets the internal variables to these values.		    *
// **********************************************************************

TimeOff::TimeOff(char name[], int id)
{
	employeename = name;
	iden = id;
}

// **********************************************************************
// * Definition of the function: TimeOff::maxvachours					*
// * This is the member function takes as it's parameters a double for  *
// * the amount of hours.  It then checks if the value is over 240.     *
// * If it is, internal hours is set to 240, otherwise, it's set to it's*
// * value.  It then passes that value into the NumDays object,         *
// * maxVacation.													    *
// **********************************************************************

void TimeOff::maxvachours(double hours)
{ 
	if (hours > 240)
	{
		hours = 240;
	}	
	
	maxVacation.InputHours(hours); 
}

// **********************************************************************
// * Definition of the function: TimeOff::maxvacdays					*
// * This is the member function takes as it's parameters a double for  *
// * the amount of days.  It then checks if the value is over 30	    *
// * If it is, internal hours is set to 30, otherwise, it's set to it's *
// * value.  It then passes that value into the NumDays object,         *
// * maxVacation.													    *
// **********************************************************************

void TimeOff::maxvacdays(double days)
{	
	if (days > 30)
	{
		days = 30;
	}	
	
	maxVacation.InputDays(days); 
}

		


	

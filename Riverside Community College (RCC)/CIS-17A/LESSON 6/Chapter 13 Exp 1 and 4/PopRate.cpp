// PopRate.cpp: implementation of the PopRate class.
//
//////////////////////////////////////////////////////////////////////

#include "PopRate.h"

// **********************************************************************
// * Definition of the function: PopRate::getpop					    *
// * This class member function takes as it's arguements an interger for*
// * the population.  It then checks to see if the value is greater than*
// * 1.  It alters the member variable population if the value is good. *
// * It returns a bool back to main to with the status of if the value  *
// * was good or not.												    *
// **********************************************************************

PopRate::PopRate() // Constructor
{
}

bool PopRate::getpop(int pop) 
{
	bool status;

	if (pop  < 1) // Used to make sure population is at least 2
	{
		population = 0;
		status = false;
	}
	else
	{
		population = pop;
		status = true;
	}

return status;
}

// **********************************************************************
// * Definition of the function: PopRate::getbirths					    *
// * This class member function takes as it's arguements an interger for*
// * the amount of births.  It then checks to see if the value is		*
// * greater than 0.  It alters the member variable births if the value *
// * is good.  It returns a bool back to main to with the status of if  * 
// * the value was good or not.										    *
// **********************************************************************

bool PopRate::getbirths(int birth)
{
	bool status;

	if (birth < 0) // Used to make sure births is at least 1
	{
		births = 0;
		status = false;
	}
	else
	{
		births = birth;
		status = true;
	}

return status;
}

// **********************************************************************
// * Definition of the function: PopRate::getdeaths					    *
// * This class member function takes as it's arguements an interger for*
// * the amount of deaths.  It then checks to see if the value is		*
// * greater than 0.  It alters the member variable births if the value *
// * is good.  It returns a bool back to main to with the status of if  * 
// * the value was good or not.										    *
// **********************************************************************

bool PopRate::getdeaths(int death)
{
	bool status;

	if (death < 0) // Used to make sure deaths is at least 1
	{
		deaths = 0;
		status = false;
	}
	else
	{
		deaths = death;
		status = true;
	}

return status;
}

// **********************************************************************
// * Definition of the function: PopRate::birthrate					    *
// * This class member function uses a temporary variable to determine  *
// * the birth rate by dividing the amount of births by the population. *
// * It then returns the rate to main.								    *
// **********************************************************************

double PopRate::birthrate()
{
	double rate;

	rate = static_cast<double>(births)/static_cast<double>(population);

return rate;
}

// **********************************************************************
// * Definition of the function: PopRate::deathrate					    *
// * This class member function uses a temporary variable to determine  *
// * the death rate by dividing the amount of deaths by the population. *
// * It then returns the rate to main.								    *
// **********************************************************************

double PopRate::deathrate()
{
	double rate;

	rate = static_cast<double>(deaths)/static_cast<double>(population);

return rate;
}
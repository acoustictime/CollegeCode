// MilTime.cpp: implementation of the MilTime class.
//
//////////////////////////////////////////////////////////////////////

#include "Time.h"
#include "MilTime.h"

MilTime::MilTime()
{
}

int MilTime::converthours(int h) // Function converts the amount of military hours to regular hours
{
	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h / 100;

return h;
}

int MilTime::convertminutes(int h) // Function converts the amount of military minutes to regular minutes
{
	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h % 100;

return h;
}

int MilTime::getHour() // Function returns the amount of military hours
{
return milHours;
}

int MilTime::getStandHr() // Function returns the amount of standard hours
{
	int h = milHours;

	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h / 100;

return h;
}

MilTime::setTime(int h, int s) // Function allows the input of the hours and seconds.  If the values are bad,
{							   // an exception was thrown
	if (h > 2359 || h < 1)
	{
		throw BadHour();
	}
	else if (s > 59 || s < 1)
	{
		throw BadSeconds();
	}

	
	milHours = h;
	milSeconds = s;
	hour = converthours(h);
	min = convertminutes(h);
	sec = s;
}



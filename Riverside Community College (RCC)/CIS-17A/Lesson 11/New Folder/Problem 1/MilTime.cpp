// MilTime.cpp: implementation of the MilTime class.
//
//////////////////////////////////////////////////////////////////////

#include "Time.h"
#include "MilTime.h"

int MilTime::converthours(int h)
{
	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h / 100;

return h;
}

int MilTime::convertminutes(int h)
{
	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h % 100;

return h;
}

int MilTime::getHour()
{
return milHours;
}

int MilTime::getStandHr()
{
	int h = milHours;

	if (h > 1200)
	{
		h = h - 1200;
	}

	h = h / 100;

return h;
}

MilTime::setTime(int h, int s)
{
	milHours = h;
	milSeconds = s;
	hour = converthours(h);
	min = convertminutes(h);
	sec = s;
}



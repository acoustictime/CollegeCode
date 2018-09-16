// TimeClock.cpp: implementation of the TimeClock class.
//
//////////////////////////////////////////////////////////////////////

#include "TimeClock.h"
#include "MilTime.h"
#include <cmath>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TimeClock::TimeClock(int h1, int s1, int h2, int s2)
{
	
	while(h1 > 2359 || h1 < 0 || h2 > 2359 || h2 < 0 || s1 > 59 || s1 < 0 || s2 > 59 || s2 < 0)
	{
		cout << "\nInvalid Time Entered, Try Again\n\n";
		
		cout << "Please enter the 1st time in military format: ";
		cin >> h1;
		cout << "Please enter the seconds for the 1st time: ";
		cin >> s1;
		cout << "Please enter the 2nd time in military format: ";
		cin >> h2;
		cout << "Please enter the seconds for the 2nd time: ";
		cin >> s2;
	}
	
	time1.setTime(h1, s1);
	time2.setTime(h2, s2);
}

void TimeClock::TimeDiff()
{
	int h, s, temp;

	if (time2.getHour() > time1.getHour())
	{
		h = time2.getHour() - time1.getHour();
		s = time2.getSec() - time1.getSec();

		if ((h % 100) > 59)
		{
			h = (h / 100) * 100;

			temp = (60 - (time1.getHour() % 100)) + (time2.getHour() % 100);
		
			h = h + temp;
		}

		if ((time2.getSec() - time1.getSec()) < 0)
		{
			h = h - 1;
			temp = time2.getSec() - time1.getSec();
			s = 60 - abs(temp);
		}
	}
	else if(time2.getHour() < time1.getHour())
	{
		h = time1.getHour() - time2.getHour();
		s = time1.getSec() - time2.getSec();

		if ((h % 100) > 59)
		{
			h = (h / 100) * 100;
		
			temp = (60 - (time2.getHour() % 100)) + (time1.getHour() % 100);
		
			h = h + temp;
	
		}

		if ((time1.getSec() - time2.getSec()) < 0)
		{
			h = h - 1;
			temp = time1.getSec() - time2.getSec();
			s = 60 - abs(temp);
		}
	}
	else
	{
		h = 0;
		s = 0;
	}

	hour = h / 100;
	minutes = h % 100;
	seconds = s;
}








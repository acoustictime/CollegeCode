// TimeClock.h: interface for the TimeClock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMECLOCK_H__A982149D_060B_4D80_8D09_4BB5E668DCF2__INCLUDED_)
#define AFX_TIMECLOCK_H__A982149D_060B_4D80_8D09_4BB5E668DCF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MilTime.h"

class TimeClock  : public MilTime
{
	protected:
		int hour, minutes, seconds;		

	public:
		MilTime time1, time2;
		TimeClock(int h1, int s1, int h2, int s2);

		void TimeDiff();
		int Hour()
		{ return hour;};
		int Seconds()
		{ return seconds;};
		int Minutes()
		{ return minutes;};

		

};

#endif // !defined(AFX_TIMECLOCK_H__A982149D_060B_4D80_8D09_4BB5E668DCF2__INCLUDED_)

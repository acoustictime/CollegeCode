// MilTime.h: interface for the MilTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILTIME_H__50E5C8A5_409F_499A_808D_B120182C7B3C__INCLUDED_)
#define AFX_MILTIME_H__50E5C8A5_409F_499A_808D_B120182C7B3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Time.h"
#include <iostream>

using namespace std;

class MilTime : public Time // Class is derived from the Time class
{

	protected:
		int milHours;
		int milSeconds;
		int converthours(int h);
		int convertminutes(int h);

	public:
	
		class BadHour // Exception class used if the amount of hours is bad
		{ };

		class BadSeconds // Exception class used if the amount of seconds is bad
		{ };		
		
		MilTime();

		int getHour();
		int getStandHr();
		setTime(int h, int s);
};

#endif // !defined(AFX_MILTIME_H__50E5C8A5_409F_499A_808D_B120182C7B3C__INCLUDED_)

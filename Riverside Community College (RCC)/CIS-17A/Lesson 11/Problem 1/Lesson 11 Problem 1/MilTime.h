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

class MilTime : public Time 
{

	protected:
		int milHours;
		int milSeconds;
		int converthours(int h);
		int convertminutes(int h);

	public:
	
		MilTime(int h, int s) : Time(converthours(h), convertminutes(h), s)
		{
			while (h > 2359 || h < 1 || s > 59 || s < 1)
			{
				cout << "\nInvalid Time Entered, Enter a New Time\n\n";
				cout << "Please enter the time in military format: ";
				cin >> h;
				cout << "Please enter the amount of seconds: ";
				cin >> s;

				setTime(h, s);
			}
			
			milHours = h; 
			milSeconds = s;
		};

		int getHour();
		int getStandHr();
		setTime(int h, int s);
};

#endif // !defined(AFX_MILTIME_H__50E5C8A5_409F_499A_808D_B120182C7B3C__INCLUDED_)

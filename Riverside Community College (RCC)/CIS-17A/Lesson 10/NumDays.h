// NumDays.h: interface for the NumDays class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NUMDAYS_H__F85968E2_B27E_441B_97A0_868C344B0CF3__INCLUDED_)
#define AFX_NUMDAYS_H__F85968E2_B27E_441B_97A0_868C344B0CF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

using namespace std;

const int DayHours = 8; // Used for how many hours in a day

class NumDays  
{
	private:
		double hours;
		double days;

	public:
		NumDays(double h);
		NumDays();
		~NumDays();

		double GetHours()
		{ return hours; }

		double GetDays()
		{ return days; }

		bool InputHours(double h);
		bool InputDays(double d);

		NumDays operator + (const NumDays &);
		NumDays operator - (const NumDays &);
		NumDays operator ++ ();
		NumDays operator ++ (int);
		NumDays operator -- ();
		NumDays operator -- (int);
};

#endif // !defined(AFX_NUMDAYS_H__F85968E2_B27E_441B_97A0_868C344B0CF3__INCLUDED_)

// Date.h: interface for the Date class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATE_H__95866672_8CBC_4890_8313_A1B2C6142F86__INCLUDED_)
#define AFX_DATE_H__95866672_8CBC_4890_8313_A1B2C6142F86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class Date
{
	private:
		int month, day, year;
		string monthname;
		void getmonthname();

		
	public:
		
		class InvalidDay
		{ };
		class InvalidMonth
		{ };
		class InvalidYear
		{ };

		Date();
		void getmonth(int tempmonth);
		void getday(int tempday);
		void getyear(int tempyear);
		void datetype(int choice);
		void menu();
};

#endif // !defined(AFX_DATE_H__95866672_8CBC_4890_8313_A1B2C6142F86__INCLUDED_)

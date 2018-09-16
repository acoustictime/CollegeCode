// Problem2.h: interface for the Problem2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROBLEM2_H__A6E7DD39_C4A5_49AB_A3F7_221E55A38A28__INCLUDED_)
#define AFX_PROBLEM2_H__A6E7DD39_C4A5_49AB_A3F7_221E55A38A28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Problem2  
{
	private:
		double rate, hours, pay;
		char *name;
		void paycalc();
		
	public:
		Problem2();
		void inputname(char *n);
		bool inputhours(double h);
		bool inputrate(double r);
		const char *getname();
		void retreive(double &h, double &r, double &p);

};

#endif // !defined(AFX_PROBLEM2_H__A6E7DD39_C4A5_49AB_A3F7_221E55A38A28__INCLUDED_)

// PopRate.h: interface for the PopRate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPRATE_H__D43619FE_8750_40F5_A940_C575089FDF21__INCLUDED_)
#define AFX_POPRATE_H__D43619FE_8750_40F5_A940_C575089FDF21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PopRate
{
	private:
		int population, births, deaths;

	public:
		PopRate();
		bool getpop(int pop);
		bool getbirths(int birth);
		bool getdeaths(int death);		
		double birthrate();
		double deathrate();
};

#endif // !defined(AFX_POPRATE_H__D43619FE_8750_40F5_A940_C575089FDF21__INCLUDED_)

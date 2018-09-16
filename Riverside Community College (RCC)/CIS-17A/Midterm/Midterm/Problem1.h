// Problem1.h: interface for the Problem1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROBLEM1_H__3A8B0DDB_8F6B_4AD1_9EA6_AE2BB5E877DF__INCLUDED_)
#define AFX_PROBLEM1_H__3A8B0DDB_8F6B_4AD1_9EA6_AE2BB5E877DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Problem1  
{
	private:
		int account;
		double balance;
		double begbalance;
		double checks;
		double deposits;
		bool over;
		void overdrawn();
	
	public:
		Problem1();
		bool accountupdate(int a);
		bool balanceupdate(double b);
		bool checksupdate(double c);
		bool despositsupdate(double d);	
		void results();

};

#endif // !defined(AFX_PROBLEM1_H__3A8B0DDB_8F6B_4AD1_9EA6_AE2BB5E877DF__INCLUDED_)

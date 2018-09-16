// Checking.h: interface for the Checking class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKING_H__7274718B_3148_4160_AE48_4B7AF461F57C__INCLUDED_)
#define AFX_CHECKING_H__7274718B_3148_4160_AE48_4B7AF461F57C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Account.h"
#include <fstream>

using namespace std;

class Checking : public Account // Checking class derived from Account class
{
	protected:
		fstream checksave; // Used for input and output

	public:
		
		// Constructor used for new account
		
		Checking(double bal, char lname[], char fname[], int acctnumber) : Account(bal, lname, fname, acctnumber)
		{
			acct.transactions++;
			checksave.open("checking_transactions.txt", ios::out);
			checksave << acct.transactions << " OpeningBalance " << bal;
			checksave.close();
		};
		
		Checking() : Account(){};
		void WithDraw(double amount);
		void Deposit(double amount);
		void monthlyProc();
		bool CheckBalance(double check);
		bool CheckStatus();
		void savefile();
		void calcInt();
		void transactions();
		void monthReport();
};

#endif // !defined(AFX_CHECKING_H__7274718B_3148_4160_AE48_4B7AF461F57C__INCLUDED_)

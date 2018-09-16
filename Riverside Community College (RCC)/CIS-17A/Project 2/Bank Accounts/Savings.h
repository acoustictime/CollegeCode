// Savings.h: interface for the Savings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVINGS_H__62681426_8CEB_4C9F_9D45_8AEFB0AEE458__INCLUDED_)
#define AFX_SAVINGS_H__62681426_8CEB_4C9F_9D45_8AEFB0AEE458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Account.h"
#include <fstream>
#include <string>

using namespace std;

class Savings  : public Account // Savings class derived from Account class
{
	protected:
		fstream savesave; // USed for input and output

	public:
	
	// COnstructor used for new accounts
		
	Savings(double bal, char lname[], char fname[], int acctnumber) : Account(bal, lname, fname, acctnumber)
	{
		acct.transactions++;
		savesave.open("savings_transactions.txt", ios::out);
		savesave << acct.transactions << " OpeningBalance " << bal;
		savesave.close();
	};

	Savings() : Account(){};
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

#endif // !defined(AFX_SAVINGS_H__62681426_8CEB_4C9F_9D45_8AEFB0AEE458__INCLUDED_)

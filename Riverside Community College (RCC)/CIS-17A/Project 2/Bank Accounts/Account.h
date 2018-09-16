// Account.h: interface for the Account class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCOUNT_H__79DFD862_8282_4FB1_94B0_EAFFBCB2D35B__INCLUDED_)
#define AFX_ACCOUNT_H__79DFD862_8282_4FB1_94B0_EAFFBCB2D35B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std; // Used for the first name and last name

const int namesize = 15; // Used for the namesize;

struct Acct // Struct used to hold the user's bank information
{
	double balance;
	int acctNumber;
	string fname;
	string lname;
	bool accountstatus;
	int withdraws;
	int deposits;
	double deptotal;
	double withtotal;
	double interestearned;
	double serviceCharges;
	int months;
	int transactions;
};

class Account  
{
	protected:
		
		Acct acct; // Struct variable
				
	public:
		Account(double bal, char lname[], char fname[], int acctnumber); // Constructor used for new account
		Account(); // Constructor used for old accounts
		virtual void Deposit(double deposit); // Used for deposits
		virtual void Withdraw(double withdraw); // Used for withdraws
		virtual void monthlyProc(); // Used to process end of the month stuff
		
		bool acctstatus() // Returns the account status
		{ return acct.accountstatus; };
		double getbalance() // Returns the account balance
		{ return acct.balance; };
		bool status() // Returns the account status
		{ return acct.accountstatus;};
		void closing(); // Used for when the game closes
		
		void getlname(char lname[]) // Input for last name
		{ acct.lname = lname;};
		void getfname(char fname[]) // Input for first name
		{ acct.fname = fname;};
		void getacctnum(int acctnum) // Input for account number
		{ acct.acctNumber = acctnum;};
		void getacctstatus(bool acctstatus) // Input for account status
		{ acct.accountstatus = acctstatus;};
		void getacctbalance(double balance)// Input for account balance
		{ acct.balance = balance; };
		void getdeposits(int deposits) // Input for the amount of deposits
		{ acct.deposits = deposits; };
		void getdeptotal(double deptotal) // Input fo the total of all deposits made
		{ acct.deptotal = deptotal; };
		void getinterest(double interest) // Input for interest earned
		{ acct.interestearned = interest; };
		void getmonths(int months) // Input for months account is open
		{ acct.months = months; };
		void getscharges(double scharges) // Input for service charges total
		{ acct.serviceCharges = scharges; };
		void getwith(int with) // Input for the amount of withdraws
		{ acct.withdraws = with; };
		void getwithtotal(double withtotal) // Input for the total of all withdraws made
		{ acct.withtotal = withtotal; };
		void gettrans(int transactions) // Input for the amount of transactions
		{ acct.transactions = transactions; };
};

#endif // !defined(AFX_ACCOUNT_H__79DFD862_8282_4FB1_94B0_EAFFBCB2D35B__INCLUDED_)

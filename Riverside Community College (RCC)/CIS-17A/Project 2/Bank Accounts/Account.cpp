// Account.cpp: implementation of the Account class.
//
//////////////////////////////////////////////////////////////////////

#include "Account.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// **********************************************************************
// * Definition of member function: Account::Account				    *
// * This constructor is used for old accounts, it doesn't do anything  *
// **********************************************************************

Account::Account()
{

}

// **********************************************************************
// * Definition of member function: Account::Account				    *
// * This contructor function takes as it's parameters, a double for the*
// * balance, and c-string for the first and last name, and an int for  *
// * the account number.  It then sets the new account variable info    *
// * for the new accounts.											    *
// **********************************************************************

Account::Account(double bal, char lname[], char fname[], int acctnumber)
{
	// Sets all the account variables to their new values
	
	acct.deptotal = 0;
	acct.withtotal = 0;
	acct.interestearned = 0;
	acct.serviceCharges = 0;
	acct.withdraws = 0;
	acct.deposits = 0; 
	acct.months = 0;
	acct.transactions = 0;
	acct.accountstatus = true;
	acct.balance = bal;
	acct.lname = lname;
	acct.fname = fname;
	acct.acctNumber = acctnumber;
}

// **********************************************************************
// * Definition of member function: Account::Deposit				    *
// * This member function takes as it's parameters a double for the     *
// * deposit amount.  It then updates the balance, deposit total, and   *
// * deposits amount.												    *
// **********************************************************************

void Account::Deposit(double deposit)
{
	acct.deptotal = acct.deptotal + deposit;
	acct.deposits++;
	acct.balance = acct.balance + deposit;
}
		
// **********************************************************************
// * Definition of member function: Account::Withdraw				    *
// * This member function takes as it's parameters a double for the     *
// * withdraw amount.  It then updates the balance, withdraw total, and *
// * withdraw amount.												    *
// **********************************************************************

void Account::Withdraw(double withdraw)
{	
	acct.withtotal = acct.withtotal + withdraw;
	acct.withdraws++;
	acct.balance = acct.balance - withdraw;
}
		
// **********************************************************************
// * Definition of member function: Account::monthlyProc			    *
// * This member function is used to process end of the month stuff.  It*
// * resets the withdraws, deposits, and service charges variables.  It *
// * also increases the month variable by one.						    *
// **********************************************************************

void Account::monthlyProc()
{
	acct.withdraws = 0;
	acct.deposits = 0;
	acct.serviceCharges = 0;
	acct.months++;
}





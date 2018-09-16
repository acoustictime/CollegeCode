// Project1.cpp: implementation of the Project1 class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Problem1.h"

using namespace std;

const int overprice = 12;


// **********************************************************************
// * Definition of the function: Problem1::Problem1					    *
// * This is the constructor member function that initializes the values*
// * stored in the class.											    *
// **********************************************************************

Problem1::Problem1()
{
	account = 0;
	balance = 0.0;
	begbalance = 0.0;
	checks = 0.0;
	deposits = 0.0;
	over = false;
}

// **********************************************************************
// * Definition of the function: Problem1::overdrawn				    *
// * This member function determines if the account balance is less than*
// * 0.  If it is, a bool value is set to true which will be used later *
// * to say there was an overage.  It also subtracts 12 dollars from the*
// * current account balance.										    *
// **********************************************************************

void Problem1::overdrawn()

{
	if (balance < 0)
	{
		balance = balance - overprice;
		over = true;
	}
}

// **********************************************************************
// * Definition of the function: Problem1::accountupdate			    *
// * This member function takes as it's arguements an interger for the  *
// * account number.  It returns a bool for true if the account number  *
// * is valid.  If the value is good, it updates the internal value for *
// * the account number.											    *
// **********************************************************************

bool Problem1::accountupdate(int a)
{
	bool status;

	if (a < 10000 || a > 99999)
	{
		account = 0;
		status = false;
	}
	else
	{
		account = a;
		status = true;
	}
return status;
}	
		
// **********************************************************************
// * Definition of the function: Problem1::balanceupdate			    *
// * This member function takes as it's arguements an interger for the  *
// * balance number.  It returns a bool for true if the balance number  *
// * is valid.  If the value is good, it updates the internal value for *
// * the balance number.											    *
// **********************************************************************

bool Problem1::balanceupdate(double b)
{
	bool status;

	if (b < 0)
	{
		status = false;
	}
	else
	{
		balance = b;
		begbalance = b;
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of the function: Problem1::checksupdate				    *
// * This member function takes as it's arguements an interger for the  *
// * check amount.    It returns a bool for true if the check amount    *
// * is valid.  If the value is good, it updates the internal value for *
// * the check amount.												    *
// **********************************************************************

bool Problem1::checksupdate(double c)
{
	bool status;

	if (c <= 0.0)
	{
		status =false;
	}
	else
	{
		checks = c;
		balance = balance - c;
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of the function: Problem1::depositsupdate			    *
// * This member function takes as it's arguements an interger for the  *
// * deposit amount.    It returns a bool for true if the deposit amount*
// * is valid.  If the value is good, it updates the internal value for *
// * the deposit amount.											    *
// **********************************************************************

bool Problem1::despositsupdate(double d)
{
	bool status;

	if (d <= 0.0)
	{
		status = false;
	}
	else
	{
		deposits = d;
		balance = balance + d;
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of the function: Problem1::results					    *
// * This member function calls the overdrawn member function to		*
// * determine if the account was overdrawn.  It then displays a monthly*
// * statement.  If account was overdrawn, a 12 dollar finance charge   *
// * was added to the balance.										    *
// **********************************************************************

void Problem1::results()
{ 
	Problem1::overdrawn();
	
	cout << "\n\nHere is your monthly statement for account number " << account << ".\n\n";
	cout << left << setw(25) << "Beginning Balance" << right << setw(10) << "$" << left << setw(10) << begbalance << endl;
	cout << left << setw(25) << "Total Checks" << right << setw(10) << "$" << left << setw(10) << checks << endl;
	cout << left << setw(25) << "Total Deposits" << right << setw(10) << "$" << left << setw(10) << deposits << endl;
	cout << left << setw(25) << "Ending Balance" << right << setw(10) << "$" << left << setw(10) << balance << endl;
	
	if (over)
	{
		cout << "\nYour account was overdrawn and you were charged a " << overprice << " dollar finance charge.";
		cout << "\nYour balance has been updated to reflect this charge.\n\n";
	}
	else
	{
		cout << endl << endl;
	}

	
}

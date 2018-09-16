// Savings.cpp: implementation of the Savings class.
//
//////////////////////////////////////////////////////////////////////

#include "Savings.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int withcharge = 1; // Used for the withdraw charge
const int servicecharge = 15; // Used for the service charge amount
const double interestrate = .04; // Interest rate

// **********************************************************************
// * Definition of member function: Savings::WithDraw				    *
// * This member function takes as it's parameter a double for the      *
// * withdraw amount.  It then passes it to the Account::Withdraw       *
// * function.  It the checks if the withdraw causes the balance to go  *
// * below 25.  Lastly it writes the transactions to the transctions    *
// * file.															    *
// **********************************************************************

void Savings::WithDraw(double amount)
{
		Account::Withdraw(amount); // Passes the amount of the Account::Withdraw function
		
		if(CheckBalance(amount)) // Used if the balance is less than 25
		{
			system("cls");
			cout << "This withdraw caused the balance to go below $25" << endl << endl;
			system("pause");
		}
			
			acct.transactions++; // Increases the transactions by 1

			savesave.open("savings_transactions.txt", ios::out | ios::app); // Writes the transaction to the transcations file
			savesave << endl << acct.transactions << " Withdraw " << amount;
			savesave.close();
}

// **********************************************************************
// * Definition of member function: Savings::Deposit				    *
// * This member function takes as it's parameter a double for the		*
// * deposit amount.  It then passes that to the Account::Deposit       *
// * function.	It increases the transactions by 1 and writes the       *
// * transaction to the transactions file.  Lastly sets the account     *
// * status to active if the balance is greater than 25.			    *
// **********************************************************************

void Savings::Deposit(double amount)
{
	Account::Deposit(amount); // Passes the amount to the Account::Deposit function

	acct.transactions++; // Increases the transactions by 1

	savesave.open("savings_transactions.txt", ios::out | ios::app); // Writes the transaction to the transaction file
	savesave << endl << acct.transactions << " Deposit " << amount;
	savesave.close();

	if (acct.balance > 25) // Used to make the account active if the balance is greater than 25
	{
		acct.accountstatus = true;
	}
}

// **********************************************************************
// * Definition of member function: Savings::monthlyProc			    *
// * This member function process the end of the month stuff.  IF the   *
// * amount of withdraws this month is greater than 4, then the account *
// * is assessed service charges.  If the service charges cause the     *
// * balance to go below 25, then the account becomes inactive.  Lastly *
// * it calculates the interest, displays the month end report, and     *
// * calls the Account::monthlyProc function.						    *
// **********************************************************************

void Savings::monthlyProc()
{
	if (acct.withdraws > 4) // Used if the amount of withdraws is greater than 4
	{
		acct.balance = acct.balance - ((acct.withdraws - 4) *  withcharge); // Takes service charges

		acct.transactions++; // Increases the transactions by 1

		savesave.open("savings_transactions.txt", ios::out | ios::app); // Writes the transaction to the transactions file
		savesave << endl << acct.transactions << " ServiceCharges " << ((acct.withdraws - 4) *  withcharge);
		savesave.close();

		acct.serviceCharges = acct.serviceCharges + ((acct.withdraws - 4) *  withcharge); // Updates the service charges variable
		
		if (acct.balance < 25) // Used if the balance is now less than 25, and sets the account to inactive
		{
			system("cls");
			cout << "Your account is now inactive because the balance is less than $25";
			cout << "\n\nYou can't write anymore checks until the balance is greater than $25\n\n";
			acct.accountstatus = false;
			system("pause");
		}
	}

	Savings::calcInt(); // Called to caluclate interest
	Savings::monthReport();// Dipslays month end report
	Account::monthlyProc(); // Runs the Account::monthlyProc stuff
}

// **********************************************************************
// * Definition of member function: Savings::CheckBalance			    *
// * This member function takes as it's parameter a double the the check*
// * amount.  It then returns true if the account balance is now less   *
// * than 25.  If it is less than 25, it updates the account balance with *
// * the penalty service charges and writes that transaction to the     *
// * transction file.  Lastly it calls the CheckStatus function to see  *
// * if the account needs to be set as inactive						    *
// **********************************************************************

bool Savings::CheckBalance(double check)
{
	bool status;

	if ((acct.balance) < 25)
	{
		acct.balance = acct.balance - servicecharge; // Subtracts the service charge if the balance is less than 25
		
		acct.transactions++; // Increases the transactions by 1

		savesave.open("savings_transactions.txt", ios::out | ios::app); // Writes the transaction to the transaction file
		savesave << endl << acct.transactions << " ServiceCharges " << servicecharge;
		savesave.close();

		acct.serviceCharges = acct.serviceCharges + servicecharge; // Increases the service charges variable
		
		Savings::CheckStatus();
		status = true;
	}
	else
	{
		status = false;
	}

return status;
}

// **********************************************************************
// * Definition of member function: Savings::CheckStatus			    *
// * This member function returns false if the balance is less than 25  *
// * sets the account status to false.  If the balance is greater than  *
// * 25, it sets the account status to true.						    *
// **********************************************************************

bool Savings::CheckStatus()
{
	bool status;

	if (acct.balance < 25) // Used if the balance is less than 25
	{
		system("cls");
		cout << "Your account is now inactive because the balance is less than $25";
		cout << "\n\nYou can't write anymore checks until the balance is greater than $25\n\n";
		
		acct.accountstatus = false; // Sets account to inactive
		
		status = false;
		system("pause");
	}
	else
	{
		acct.accountstatus = true; // Sets the account to active
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of member function: Savings::savefile				    *
// * This member function saves the account info the the save file	    *
// **********************************************************************

void Savings::savefile()
{
	savesave.open("savings.txt", ios::out);
	savesave << acct.lname << " " << acct.fname << " " << acct.acctNumber << " " << acct.accountstatus << " ";
	savesave << acct.balance << " " << acct.deposits << " " << acct.deptotal << " " << acct.interestearned  << " ";
	savesave << acct.months << " " << acct.serviceCharges << " " << acct.withdraws << " " << acct.withtotal << " " << acct.transactions << endl;
	savesave.close();
}

// **********************************************************************
// * Definition of member function: Savings::calcInt				    *
// * This function calculates the interest earned this month on the     *
// * account and updates the balance.  It also write the transaction to *
// * the transactions file.  Lastly it updates the interestearned       *
// * varibale.														    *
// **********************************************************************

void Savings::calcInt()
{	
	acct.balance = acct.balance + (acct.balance * (interestrate / 12)); // Adds interest to balance

	acct.transactions++; // Increases transcations by 1

	savesave.open("savings_transactions.txt", ios::out | ios::app); // Writes transaction to transctions file
	savesave << endl << acct.transactions << " Interest " << (acct.balance * (interestrate / 12));
	savesave.close();

	acct.interestearned = acct.interestearned + (acct.balance * (interestrate / 12)); // Increases interest earned variable
}

// **********************************************************************
// * Definition of member function: Savings::transactions			    *
// * This member function reads the transactions from the transactions  *
// * file and displays them on the screen.							    *
// **********************************************************************

void Savings::transactions()
{
	// Temp variables for input and output
	string type;
	int trans;
	double amount;
	
	savesave.open("savings_transactions.txt", ios::in); // Opens file for read
	system("cls");

	cout << "***** Transaction History *****\n\n";
	cout << fixed << setprecision(2);
	cout << setw(8) << left << "Tran#" << setw(15) << left << "Type" << setw(10) << right << "Amount" << endl << endl;
	
	while (!savesave.eof()) // Loops untl end of file
	{
		// Reads in from file and outputs to the screen
		savesave >> trans;
		savesave >> type;
		savesave >> amount;

		cout << setw(8) << left << trans << setw(15) << left << type << setw(10) << right << amount << endl;
	}

	cout << endl;
	
	system("pause");
	system("cls");
	savesave.close();
}

// **********************************************************************
// * Definition of member function: Savings::monthReport			    *
// * This member function displays the account values at the end of the *
// * month.															    *
// **********************************************************************

void Savings::monthReport()
{
	system("cls");

	cout << "______________________________\n\n";
	cout << "   Savings Month End Report\n";
	cout << "______________________________\n\n";
	cout << fixed << setprecision(2);
	cout << setw(20) << left << "Account Number:" << setw(10) << right << acct.acctNumber << endl;
	cout << setw(20) << left << "Account Status:";
	
	if (acct.accountstatus == 0) // Displays the account status, inactive or active
	{
		cout << setw(10) << right << "Inactive" << endl;
	}
	else if (acct.accountstatus == 1)
	{
		cout << setw(10) << right << "Active" << endl ;
	}

	cout << setw(20) << left << "Current Balance:" << setw(10) << right << acct.balance << endl;
	cout << setw(20) << left << "Deposit Count:" << setw(10) << right << acct.deposits << endl;
	cout << setw(20) << left << "Deposit Total:" << setw(10) << right << acct.deptotal << endl;
	cout << setw(20) << left << "Withdraw Count:" << setw(10) << right << acct.withdraws << endl;
	cout << setw(20) << left << "Withdraw Total:" << setw(10) << right << acct.withtotal << endl;
	cout << setw(20) << left << "Interest Earned:" << setw(10) << right << acct.interestearned << endl;
	cout << setw(20) << left << "Service Charges:" << setw(10) << right << acct.serviceCharges << endl;
	cout << setw(20) << left << "Transaction Count:" << setw(10) << right << acct.transactions << endl;
	cout << setw(20) << left << "Months Open:" << setw(10) << right << acct.months << endl << endl;
	cout << "______________________________\n\n";
	
	system("pause");
	system("cls");
}
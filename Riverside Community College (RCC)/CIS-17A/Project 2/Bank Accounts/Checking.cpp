// Checking.cpp: implementation of the Checking class.
//
//////////////////////////////////////////////////////////////////////

#include "Checking.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int servicecharge = 15; // Used for the service charge amount
const double checkservicecharge = 5; // Used for the check service charge amount
const double percheckcharge = .10; // Used for the percheck charge
const double interestrate = .04; // Used for the interest rate amount

// **********************************************************************
// * Definition of member function: Checking::WithDraw				    *
// * This member function takes as it's parameter a double for the      *
// * withdraw amount.  It then passes the amount to the Account:Withdraw*
// * function. It also checks if this check caused the balance to go    *
// * below 0 and let's you know you were charges 15 dollars for it.  It *
// * then increases the amount of transactions by 1 and writes that     *
// * transaction to the output file.								    *
// **********************************************************************

void Checking::WithDraw(double amount)
{
		Account::Withdraw(amount); // Passes amount to the Account::Withdraw function
		
		if(CheckBalance(amount)) // Used if the check amount causes the balance to go below 0
		{
			system("cls");
			cout << "This check caused the balance to go below $0";
			cout << "\n\nYou have been assessed a $15 dollar service charge\n\n";
			system("pause");
		}
		
		acct.transactions++; // Increases the amount of transactions by 1.
		
		checksave.open("checking_transactions.txt", ios::out | ios::app); // Writes transaction to transaction file
		checksave << endl << acct.transactions << " Withdraw " << amount;
		checksave.close();
}

// **********************************************************************
// * Definition of member function: Checking::Deposit				    *
// * This member function takes as it's parameter a double for the      *
// * deposit amount.  It then passes that to the Account::Deposit       *
// * function.  It then increases the amount of transactions by 1.  It  *
// * then writes the transaction to the transaction file.			    *
// **********************************************************************

void Checking::Deposit(double amount)
{
	Account::Deposit(amount); // Passes the amount fo the Account::Deposit function
	
	acct.transactions++; // Increases the transactions by 1
	
	checksave.open("checking_transactions.txt", ios::out | ios::app); // Writes the transaction to the transaction file
	checksave << endl << acct.transactions << " Deposit " << amount;
	checksave.close();

	if (acct.balance > 0) // Sets the account status variable to true if the balance is greater than 0
	{
		acct.accountstatus = true;
	}
}

// **********************************************************************
// * Definition of member function: Checking::monthlyProc			    *
// * This member function determines the service charges and then takes *
// * that amount from the balance.  It writes that transaction to the   *
// * to the transactions file.  It also increases the serviceCharges    *
// * variable.  Lastly it calls the calcInt function to calculate the   *
// * interest earned, displays the month end report, and then calls the *
// * Account::monthlyProc function.									    *
// **********************************************************************

void Checking::monthlyProc()
{
	// Subtracts the service charges from the balance
	acct.balance = acct.balance - (checkservicecharge + (static_cast<double>(acct.withdraws) * percheckcharge));
	
	acct.transactions++; // Increases the transactions by 1

	checksave.open("checking_transactions.txt", ios::out | ios::app); // Writes the transaction to the transactions file
	checksave << endl << acct.transactions << " ServiceCharges " << (checkservicecharge + (static_cast<double>(acct.withdraws) * percheckcharge));
	checksave.close();

	// Update the servicCharges variable with the new service charges.
	acct.serviceCharges = acct.serviceCharges + (checkservicecharge + (static_cast<double>(acct.withdraws) * percheckcharge));
		
	Checking::calcInt(); // Calculates interest
	Checking::monthReport(); // Displyas the month end report
	Account::monthlyProc(); // Runs the Account::monthlyProc function
}

// **********************************************************************
// * Definition of member function: Checking::CheckBalance			    *
// * This member function takes as it's parameter a double the the check*
// * amount.  It then returns true if the account balance is now less   *
// * than 0.  If it is less than 0, it updates the account balance with *
// * the penalty service charges and writes that transaction to the     *
// * transction file.  Lastly it calls the CheckStatus function to see  *
// * if the account needs to be set as inactive						    *
// **********************************************************************

bool Checking::CheckBalance(double check)
{
	bool status;

	if ((acct.balance) < 0) // Used if the account balance is less than 0
	{
		acct.balance = acct.balance - servicecharge; // Subtracts the service charge if the balance is less than 0
		
		acct.transactions++; // Increases the transactions by 1

		checksave.open("checking_transactions.txt", ios::out | ios::app); // Writes the transaction to the transaction file
		checksave << endl << acct.transactions << " ServiceCharges " << servicecharge;
		checksave.close();

		acct.serviceCharges = acct.serviceCharges + servicecharge; // Increases the service charges variable

		Checking::CheckStatus(); // Called to see if the account is now inactive or not
		status = true;
	}
	else
	{
		status = false;
	}

return status;
}

// **********************************************************************
// * Definition of member function: Checking::CheckStatus			    *
// * This member function returns false if the balance is less than 0   *
// * sets the account status to false.  If the balance is greater than 0*
// * , it sets the account status to true.							    *
// **********************************************************************

bool Checking::CheckStatus()
{
	bool status;

	if (acct.balance < 0) // Used if the balance is less than 0.
	{
		system("cls");
		cout << "Your account is now inactive because the balance is less than $0";
		cout << "\n\nYou can't write anymore checks until the balance is greater than $0\n\n";
		
		acct.accountstatus = false; // Changes the account to inactive
		
		status = false;
		system("pause");
	}
	else
	{
		acct.accountstatus = true; // Changes the account to active
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of member function: Checking::savefile				    *
// * This member function saves the account info the the save file	    *
// **********************************************************************

void Checking::savefile()
{
	checksave.open("checking.txt", ios::out);
	checksave << acct.lname << " " << acct.fname << " " << acct.acctNumber << " " << acct.accountstatus << " ";
	checksave << acct.balance << " " << acct.deposits << " " << acct.deptotal << " " << acct.interestearned  << " ";
	checksave << acct.months << " " << acct.serviceCharges << " " << acct.withdraws << " " << acct.withtotal << " " << acct.transactions << endl;
	checksave.close();
}

// **********************************************************************
// * Definition of member function: Checking::calcInt				    *
// * This function calculates the interest earned this month on the     *
// * account and updates the balance.  It also write the transaction to *
// * the transactions file.  Lastly it updates the interestearned       *
// * varibale.														    *
// **********************************************************************

void Checking::calcInt()
{	
	acct.balance = acct.balance + (acct.balance * (interestrate / 12)); // Adds interest to balance

	acct.transactions++; // Increases transactions by 1

	checksave.open("checking_transactions.txt", ios::out | ios::app); // Writes transaction to transaction file
	checksave << endl << acct.transactions << " Interest " << (acct.balance * (interestrate / 12));
	checksave.close();

	acct.interestearned = acct.interestearned + (acct.balance * (interestrate / 12)); // Updates interestearned variable
}

// **********************************************************************
// * Definition of member function: Checking::transactions			    *
// * This member function reads the transactions from the transactions  *
// * file and displays them on the screen.							    *
// **********************************************************************

void Checking::transactions()
{
	// Temp varibales used for input and output	
	string type;
	int trans;
	double amount;
	
	checksave.open("checking_transactions.txt", ios::in); // Opens read file
	
	system("cls");

	cout << "***** Transaction History *****\n\n";
	cout << fixed << setprecision(2);
	cout << setw(8) << left << "Tran#" << setw(15) << left << "Type" << setw(10) << right << "Amount" << endl << endl;
	
	while (!checksave.eof()) // Loops until end of file is found
	{
		// Reads in values to temp variables and displays them on the screen
		checksave >> trans;
		checksave >> type;
		checksave >> amount;
		cout << setw(8) << left << trans << setw(15) << left << type << setw(10) << right << amount << endl;
	}
	
	cout << endl;
	
	system("pause");
	system("cls");
	checksave.close();
}

// **********************************************************************
// * Definition of member function: Checking::monthReport			    *
// * This member function displays the account values at the end of the *
// * month.															    *
// **********************************************************************

void Checking::monthReport()
{
	system("cls");

	cout << "______________________________\n\n";
	cout << "   Checking Month End Report\n";
	cout << fixed << setprecision(2);
	cout << "______________________________\n\n";
	cout << setw(20) << left << "Account Number:" << setw(10) << right << acct.acctNumber << endl;
	cout << setw(20) << left << "Account Status:";
	
	if (acct.accountstatus == 0) // Used to determine account status, inactive or active
	{
		cout << setw(10) << right << "Inactive" << endl;
	}
	else if (acct.accountstatus == 1)
	{
		cout << setw(10) << right << "Active" << endl;
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
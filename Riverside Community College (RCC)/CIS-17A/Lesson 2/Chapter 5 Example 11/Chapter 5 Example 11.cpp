// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-7-06			  											    	*
// *																	*
// * This program calculates the balance of a bank account after a      *
// * certain amount of months.  It takes as it's input, the original    *
// * balance, the interest rate, and how many months the account has    *
// * been opened.														*
// **********************************************************************
 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	double rate, balance, begbalance, deposits = 0, withdrawals = 0, currentdeposit, currentwithdraw, interestearned = 0; 
	int months, count;

	cout << "What is the initial balance of the account? ";
	cin >> balance;
	cout << "\nWhat is the annual interest rate? ";
	cin >> rate;
	cout << "\nHow many months has the account been open? ";
	cin >> months;
	
	begbalance = balance;
	
	for (count = 1; count <= months; count++) // Ask how much was deposited and withdrawn from the account
	{
		cout << "\nHow much was deposited into the account for month " << count << "? ";
		cin >> currentdeposit;
		
		while (currentdeposit < 0)
		{
			cout << "\nYou can't enter a negative amount";
			cout << "\nHow much was deposited into the account for month " << count << "? ";
			cin >> currentdeposit;
		}

		balance = balance + currentdeposit;
		deposits = deposits + currentdeposit;
		
		cout << "\nHow much was withdrawn from the account for month " << count << "? ";
		cin >> currentwithdraw;
		
		while (currentwithdraw < 0)
		{
			cout << "\nYou can't enter a negative amount";
			cout << "\nHow much was withdrawn from the account for month " << count << "? ";
			cin >> currentwithdraw;
		}

		balance = balance - currentwithdraw;
		withdrawals = withdrawals + currentwithdraw;

		if (balance < 0)
		{
			cout << "\nYour balance dropped below zero, we have closed your acount.\n";

			return 0;
		}
		
		interestearned = interestearned + (((rate / 12) / 100) * balance);	// Determines interested earned
		balance = ((rate / 12) / 100) * balance + balance; // Determines the balance
	}

	cout << fixed << setprecision(2);
	cout << setw(20) << left << "\nBeginning Balance:" << setw(10) << right << begbalance;
	cout << setw(20) << left << "\nAnnual Interest Rate:" << setw(8) << right << rate << "%";
	cout << setw(20) << left << "\nDeposits Totaling:" << setw(10) << right << deposits;
	cout << setw(20) << left << "\nWithdraws Totaling:" << setw(10) << right << withdrawals;
	cout << setw(20) << left << "\nInterest Earned:" << setw(10) << right << interestearned;
	cout << setw(20) << left << "\nEnding Balance:" << setw(10) << right << balance << endl;

return 0;
}
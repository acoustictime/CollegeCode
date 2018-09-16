// ******************************************************************************
// * James Small																*
// * Cis-17a																	*
// * 9-7-06																		*
// *																			*
// * This program takes as it's input, the principal amount, the interest rate, *
// * and the amount of years, and returns what the monthly payment would be.    *
// ******************************************************************************

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double loanAmount = 0;
	double rate = 0;
	int payments = 0;
	double paymentAmount = 0;
	
	cout << "What is the annual interest rate? "; 
	cin >> rate;
	cout << "How many payments will be made on the loan? ";
	cin >> payments;
	cout << "What is the initial amount of the loan? ";
	cin >> loanAmount;

	rate = rate / 12; // Converts the rate from yearly to monthly

// This formula actually calculates the monthly payment.  
	
	paymentAmount = (((rate / 100) * (pow((1 + (rate / 100)), payments))) / ((pow((1 + (rate / 100)), payments)) - 1)) * loanAmount;

	cout << fixed << setprecision(2);
	cout << setw(25) << left << "Loan Amount:            $" << setw(9) << right << loanAmount << endl;
	cout << setw(25) << left << setprecision(0) << "Monthly Interest Rate:" << setw(9) << right << rate << "%" << endl;
	cout << setw(25) << left << setprecision(2) << "Number of Payments:" << setw(9) << right << payments << endl;
	cout << setw(25) << left << "Monthly Payment:        $" << setw(9) << right << paymentAmount << endl;
	cout << setw(25) << left << "Amount Paid Back:       $" << setw(9) << right << paymentAmount * payments << endl;
	cout << setw(25) << left << "Interest Paid:          $"<< setw(9) << right << (paymentAmount * payments) - loanAmount << endl;

return 0;
}
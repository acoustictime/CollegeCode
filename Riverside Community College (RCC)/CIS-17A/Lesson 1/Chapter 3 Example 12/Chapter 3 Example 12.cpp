// ******************************************************************************
// * James Small																*
// * Cis-17a																	*
// * 9-7-06																		*
// *																			*
// * This program takes as it's input, the principal amount, the interest rate, *
// * and how many times the interest is compounded and returns how much interst *
// * has accumulated in one year.												*
// ******************************************************************************

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double principal = 0;
	double interestRate = 0;
	int compounded = 0;
	double interestEarned = 0;

	cout << "What is the principal amount?" << endl;
	cin >> principal;
	cout << "What is the interest rate?" << endl;
	cin >> interestRate;
	cout << "How many times will the interest be compounded?" << endl;
	cin >> compounded;

// This formula computes the interest using the above parameters
	
	interestEarned = principal * pow((1 + (interestRate / 100) / compounded), compounded);

	cout << fixed << setprecision(2);
	cout << setw(20) << left << "Interest Rate:" << setw(10) << right << interestRate << "%" << endl;
	cout << setw(20) << left << "Times Compounded:" << setw(10) << right << compounded << endl;
	cout << setw(20) << left << "Principal:          $" << setw(9) << right << principal << endl;;
	cout << setw(20) << left << "Interest:           $" << setw(9) << right << interestEarned - principal << endl;
	cout << setw(20) << left << "Amount in Savings:  $" << setw(9) << right << interestEarned << endl;
	
return 0;
}
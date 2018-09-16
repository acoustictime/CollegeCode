// James Small

// 4-12-06

// Ch7_Part1_Small

// This program prompts the user for the variables hours and rate and uses
// them to compute their net pay.  It uses 3 void functions with parameters 
// to do this.

#include <iostream>
#include <iomanip>

using namespace std;

void GetData(double& rate, double& hours);
void ComputePay(double rate, double hours, double& net);
void DisplayNet(double net);

int main()
{
	double PayRate = 0;
	double HoursWorked = 0;
	double NetPay = 0;

	GetData(PayRate, HoursWorked);
	ComputePay(PayRate, HoursWorked, NetPay);
	DisplayNet(NetPay);

return 0;
}

void GetData(double& rate, double& hours)
{
	cout << "Enter Rate of Pay: ";
	cin >> rate;
	cout << "Enter Hours: ";
	cin >> hours;
}

void ComputePay(double rate, double hours, double& net)
{
	net = rate * hours;
}

void DisplayNet(double net)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Net Pay: $" << net << endl;
}

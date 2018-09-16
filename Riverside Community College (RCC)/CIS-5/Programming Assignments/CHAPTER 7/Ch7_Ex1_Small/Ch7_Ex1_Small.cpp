// James Small

// 4-13-06

// Ch7_Ex1_Small

// This program 6 void functions to perform different kinds of tasks.  It prompts the user for 
// hours worked and pay rate and returns the amount to be paid.  It uses a void function to 
// increase the value of a char variable by 1.  It finally prompts for an interger and uses it
// along with two other variables to output the new results of a variable.


#include <iostream>
#include <iomanip>

using namespace std;

void initialize(int& x, int& y, char& z);
void getHoursRate(double& rate, double& hours);
void payCheck(double rate, double hours, double& amount);
void printCheck(double rate, double hours, double amount);
void funcOne(int& x, int y);
void nextChar(char& z);

int main()
{
	int x, y;
	char z;
	double rate, hours;
	double amount;

	initialize(x, y, z);
	cout << "After initialization: x = " << x << ", y = " << y << ", z = " << z << endl;
	getHoursRate(rate, hours);
	payCheck(rate, hours, amount);
	printCheck(rate, hours, amount);
	x = 35;
	y = 20;
	cout << "Before calling funcOne: x = " << x << ", y = " << y << endl;
	funcOne(x, y);
	cout << "After funcOne: x = " << x << endl;
	z = 'B';
	cout << "z = " << z << endl;
	nextChar(z);
	cout << "After nextChar: z = " << z << endl;
	
return 0;
}

void initialize(int& x, int& y, char& z)
{
	x = 0;
	y = 0;
	z = ' ';
}

void getHoursRate(double& rate, double& hours)
{
	cout << "Enter hours worked: ";
	cin >> hours;
	cout << endl << "Enter pay rate: ";
	cin >> rate;
	cout << endl;
}

void payCheck(double rate, double hours, double& amount)
{	
	if (hours > 40)
	{
		amount = 40 * rate + (hours - 40) * (rate * 1.5);
	}
	else
	{
		amount = hours * rate;
	}
}

void printCheck(double rate, double hours, double amount)
{
	cout << setw(20) << left << "Hours worked:" << hours << endl;
	cout << setw(20) << left << "Pay Rate:" << "$" << rate << endl;
	cout << setw(20) << left << "This week's salary:" << "$" << amount << endl;
}

void funcOne(int& x, int y)
{
	int num;
	cout << "Enter an integer: ";
	cin >> num;

	x = 2 * x + (y - num);
}

void nextChar(char& z)
{
	z++;
}
// James Small

// Ch8_Ex6_Small

// 4-23-06

// This program emulates a calculator for Fractions.  The user can specify
// the type of operation.  Either addition, subtraction, multiplication, or 
// division.  It will then prompt the user for the two fractions and output
// the result.

#include <iostream>

using namespace std;

void menu(char& operation);
void getnumbers(int& num1, int& den1, int& num2, int& den2);
void addFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult);
void subtractFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult);
void multiplyFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult);
void divideFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult);

int main()
{

char operation;
int num1, den1, num2, den2, numresult, denresult;

menu(operation);

while (operation != 'x')
{
getnumbers(num1, den1, num2, den2);
switch (operation)
{
case 'a': case 'A':

	addFractions(num1, den1, num2, den2, numresult, denresult);
	cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << numresult << "/" << denresult << endl;
	break;

case 's': case 'S':
	
	subtractFractions(num1, den1, num2, den2, numresult, denresult);
	cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = " << numresult << "/" << denresult << endl;
	break;

case 'm': case 'M':
	
	multiplyFractions(num1, den1, num2, den2, numresult, denresult);
	cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << numresult << "/" << denresult << endl;
	break;

case 'd': case 'D':
	
	divideFractions(num1, den1, num2, den2, numresult, denresult);
	cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << numresult << "/" << denresult << endl;
	break;

default: cout << "Invalid Selection" << endl;
}
menu(operation);
}
	return 0;
}

void menu(char& operation)
{
	cout << "This program performs operations of fraction. Enter" << endl;
	cout << "a : To add fraction" << endl;
	cout << "s : To subtract fraction" << endl;
	cout << "m : To multiply fraction" << endl;
	cout << "d : To divide fraction" << endl;
	cout << "x : To exit the program" << endl;
	cin >> operation;
	cout << endl;
}

void getnumbers(int& num1, int& den1, int& num2, int& den2)
{
	cout << "For fraction 1" << endl << "Enter the numerator: ";
	cin >> num1;
	cout << endl << "Enter the denominator: ";
	cin >> den1;
	cout << endl;
	
	while (den1 == 0)
	{
		cout << "The denominator must be nonzero" << endl << "Enter the denominator: ";
		cin >> den1;
		cout << endl;
	}	
	
	cout << endl << "For fraction 2" << endl << "Enter the numerator: ";
	cin >> num2;
	cout << endl << "Enter the denominator: ";
	cin >> den2;
	cout << endl;
	
	while (den2 == 0)
	{
		cout << "The denominator must be nonzero" << endl << "Enter the denominator: ";
		cin >> den2;
		cout << endl;
	}
}

void addFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult)
{
	if (den1 == den2)
	{
		denresult = den1;
		numresult = num1 + num2;
	}
	else
	{
		denresult = den1 * den2;
		numresult = (num1 * den2) + (num2 * den1);
	}
}

void subtractFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult)
{
	if (den1 == den2)
	{
		denresult = den1;
		numresult = num1 - num2;
	}
	else
	{
		denresult = den1 * den2;
		numresult = (num1 * den2) - (num2 * den1);
	}
}

void multiplyFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult)
{
		denresult = den1 * den2;
		numresult = num1 * num2;
}

void divideFractions(int num1, int den1, int num2, int den2, int& numresult, int& denresult)
{
		denresult = den1 * num2;
		numresult = num1 * den2;
}


// James Small

// Ch5_Ex8_Small

// 3-24-06

// This program prompts the user to enter two intergers.
// It outputs all the odd numbers between the numbers the
// user entered.  It outputs the sum of all the even intergers
// between the numbers the user entered. It outputs the numbers
// between 1 and 10 along with their squares.  It then outputs
// the sum of the squares of all odd numbers between the
// numbers the user entered.  Lastly it outputs all uppercase
// letters.  It does all of this using while loops. 


#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
	int num1, num2, sumeven = 0, sumoddsq = 0, currentnum, i = 0, square = 1;
	string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Enter two numbers." << endl;
	cout << "First number must be less than or equal to the second number you enter." << endl;
	cout << "Enter numbers: ";
	cin >> num1 >> num2;
	cout << endl;

	currentnum = num1 + 1;

	if (num2 - num1 == 2)
	{	
		if ((num1 + 1) % 2 == 0)
			cout << "There are no Odd intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Odd intergers between " << num1 << " and " << num2 << " are" << endl;
	}
	else 
	{
		if (num2 - num1 <= 1)
			cout << "There are no Odd intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Odd intergers between " << num1 << " and " << num2 << " are" << endl; 
	}

	while (num2 > currentnum)
	{
	
		switch (currentnum % 2)
		{
		case 0: sumeven = sumeven + currentnum;
				currentnum++;
				break;
		case 1:
		case -1: cout << currentnum << " ";
				 sumoddsq = sumoddsq + pow(currentnum, 2);
				 currentnum++;
				 break;
		}
	}
	
	cout << endl;
	if (num2 - num1 == 2)
	{	
		if ((num1 + 1) % 2 == 1)
			cout << "There are no Even intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Sum of even integers between " << num1 << " and " << num2 << " = " << sumeven << endl;
	}
	else 
	{
		if (num2 - num1 <= 1)
			cout << "There are no Even intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Sum of even integers between " << num1 << " and " << num2 << " = " << sumeven << endl;
	}
	
	cout << setw(10) << left << "Number" << setw(20) << left << "Square of Number" << endl;
	while (square <= 10)
	{
		cout << setw(4) << right << square << setw(18) << pow(square,2) << endl;
		square++;
	}
	cout << endl;
	
	if (num2 - num1 == 2)
	{
		if ((num1 + 1) % 2 == 0)
			cout << "There are no Odd intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Sum of the squares of odd integers between " << num1 << " and " << num2 << " = " << sumoddsq << endl;
	}
	else 
	{
		if (num2 - num1 <= 1)
			cout << "There are no Odd intergers between " << num1 << " and " << num2 << endl;
		else 
			cout << "Sum of the squares of odd integers between " << num1 << " and " << num2 << " = " << sumoddsq << endl;
	}	
	
	
	cout << "Upper case letters are: ";
	while (i <= 26) 
	{
		cout << letter[i] << " ";
		i++;
	}
	cout << endl;

return 0;
}

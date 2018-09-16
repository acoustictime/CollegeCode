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
// letters.  It does all of this using for loops. 

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
	int num1, num2, sumeven = 0, sumoddsq = 0, currentnum, square, i;
	string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "Enter two numbers." << endl;
	cout << "First number must be less than or equal to the second number you enter." << endl;
	cout << "Enter numbers: ";
	cin >> num1 >> num2;
	cout << endl;
 
	cout << "Odd intergers between " << num1 << " and " << num2 << " are" << endl; 
	
	for (currentnum = num1; num2 >= currentnum; currentnum++)
	{
	
		switch (currentnum % 2)
		{
		case 0: sumeven = sumeven + currentnum;
				break;
		case 1:
		case -1: cout << currentnum << " ";
				 sumoddsq = sumoddsq + pow(currentnum, 2);
				 break;
		}
	}
	
	cout << endl;
	cout << "Sum of even integers between " << num1 << " and " << num2 << " = " << sumeven << endl;
	
	cout << setw(10) << left << "Number" << setw(20) << left << "Square of Number" << endl;
	while (square <= 10)
	for (square = 1; square <= 10; square++)
	{
		cout << setw(4) << right << square << setw(18) << pow(square,2) << endl;
	}
	cout << endl;
	cout << "Sum of the squares of odd integers between " << num1 << " and " << num2 << " = " << sumoddsq << endl;	
	
	cout << "Upper case letters are: ";
	for (i = 0; i <= 26; i++) 
	{
		cout << letter[i] << " ";
	}
	cout << endl;

return 0;
}

// James Small

// Ch3_Ex5_Small

// 3-10-06

// This program prompts the user for a temperature in 
// degrees Fahrenheit and converts it to degress centigrade.

#include <iostream>

using namespace std;

int main()
{
	int fahrenheit;
	int centigrade;

	cout << "Enter temperature in Fahrenheit: " << flush;
	cin >> fahrenheit;
	cout << endl;

	centigrade = (5.0 / 9.0) * (fahrenheit - 32);

	cout << "Current Temperature = " << fahrenheit << "F" << endl;
	cout << "Current Temperature = " << centigrade << "C" << endl;

	return 0;

}

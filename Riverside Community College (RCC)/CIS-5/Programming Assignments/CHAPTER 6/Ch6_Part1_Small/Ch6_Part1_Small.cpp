// James Small

// 3-29-06

// Ch6_Part1_Small

// This program prompts the user for a temprature in Fahrenheit
// and converts it to Centigrade.  It outputs both of these
// tempratures.  It does this by using functions.


#include <iostream>

using namespace std;

int GetFahrenheit();
double ComputeCentigrade(int f);
int DisplayCentigrade(int f, double c);

int main()
{
	int fahr = GetFahrenheit();
	int cent = ComputeCentigrade(fahr);		// I converted the double centigrade amount to an int because
											// the output in your example was an int.

	DisplayCentigrade(fahr, cent);
	
return 0;

}

int GetFahrenheit()
{
	double fahrenheit;
	
	cout << "Enter temprature in Fahrenheit: ";
	cin >> fahrenheit;
	cout << endl;

	return fahrenheit;
}

double ComputeCentigrade(int f)
{
	double centigrade;

	centigrade = (5.0/9.0) * (f - 32);

	return centigrade;
}

int DisplayCentigrade(int f, double c)
{
	
	cout << "Current temprature = " << f << "F" << endl;
	cout << "Current temprature = " << c << "C" << endl;
 return 0;
}




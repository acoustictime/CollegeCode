// James Small

// 4-10-06

// Ch6_Ex7_Small

// This program prompts the user to enter the population, death, and birth rates along

// with the number of years.  It will use these values to output the population after

// the amount of years you specified.  It uses multiple functions to do this.

#include <iostream>
#include <iomanip>

using namespace std;

double growthrate(double b, double d);
double estimatedPopulation(int p, double gr, int n);

int main()
{
	int population;
	double birth;
	double death;
	int years;

	cout << "Enter current population: ";
	cin >> population;
	cout << endl;
		
	while (population < 2)
	{
		cout << "Current population must be greater than 2" << endl;
		cout << "Enter current population: ";
		cin >> population;
		cout << endl;
	}
	
	cout << "Enter birth rate: ";
	cin >> birth;
	cout << endl;
	
	while (birth < 0)
	{
		cout << "Birth rate must be greater than or equal to 0" << endl;
		cout << "Enter birth rate:  ";
		cin >> birth;
		cout << endl;
	}
	
	cout << "Enter death rate: ";
	cin >> death;
	cout << endl;
	
	while (death < 0)
	{
		cout << "Death rate must be greater than or equal to 0" << endl;
		cout << "Enter death rate:  ";
		cin >> death;
		cout << endl;
	}

	cout << "Enter the number of years for the projected population: ";
	cin >> years;
	cout << endl << endl;

	cout << fixed << setprecision(2) << showpoint;
	cout << "Growth rate = " << growthrate(birth, death) << "%" << endl;
	cout << "Projected population after " << years << " years = " << estimatedPopulation(population, (growthrate(birth, death)), years) << endl;

return 0;
}

double growthrate(double b, double d)
{
	double rate = 0;
	rate = b -d;

return rate;
}

double estimatedPopulation(int p, double gr, int n)
{
	int estimated = 0;
	int count = 1;

	if (n <= 0)
		estimated = p;
	else
	{	
		while (count <= n)
		{
			estimated = (p + gr * p / 100);
			p = estimated;
			count++;
		}
	}

return estimated;
}

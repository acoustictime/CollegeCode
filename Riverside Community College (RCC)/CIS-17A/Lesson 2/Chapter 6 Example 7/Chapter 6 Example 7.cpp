// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-7-06															    *
// *																	*
// * This program prompts the user to enter the population, death, and  * 
// * birth rates along with the number of years.  It will use these     *
// * values to output the population after the amount of years you		*
// * specified.															*
// **********************************************************************

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
		
	while (population < 2)  // Loop makes sure the population is great than 2
	{
		cout << "Current population must be greater than 2" << endl;
		cout << "Enter current population: ";
		cin >> population;
		cout << endl;
	}
	
	cout << "Enter annual birth rate: ";
	cin >> birth;
	cout << endl;
	
	while (birth < 0) // Loop makes sure the birth rate is greater than 0
	{
		cout << "Birth rate must be greater than or equal to 0" << endl;
		cout << "Enter birth rate:  ";
		cin >> birth;
		cout << endl;
	}
	
	cout << "Enter annual death rate: ";
	cin >> death;
	cout << endl;
	
	while (death < 0) // Loop makes sure the death rate is greater than 0
	{
		cout << "Death rate must be greater than or equal to 0" << endl;
		cout << "Enter death rate:  ";
		cin >> death;
		cout << endl;
	}

	cout << "Enter the number of years for the projected population: ";
	cin >> years;
	cout << endl;

	while (years < 1) // Loop makes sure the the amount of years is at least 1
	{
		cout << "Please enter at least 1 for the number of years" << endl;
		cout << "Enter the number of years for the projected population: ";
		cin >> years;
		cout << endl;
	}

	cout << fixed << setprecision(2) << showpoint;
	cout << "Growth rate = " << growthrate(birth, death) << "%" << endl;
	cout << "Projected population after " << years << " years = " << estimatedPopulation(population, (growthrate(birth, death)), years) << endl;

return 0;
}


// **********************************************************************
// * Definition of the function: growthrate							    *
// * This function takes as it's arguements, the birth and death rates  *
// * and returns a single value for both. 							    *
// **********************************************************************

double growthrate(double b, double d)
{
	double rate = 0;
	rate = b -d;

return rate;
}

// **********************************************************************
// * Definition of the function: estimatedpopulation					*
// * This function takes as it's arguements, the population, birth/death*
// * rates, and the number of years.  It cycles through the number of   *
// * years and calculates the population every year. 				    *
// **********************************************************************

double estimatedPopulation(int p, double gr, int n)
{
	int estimated = 0;
	int count = 1;

		while (count <= n)
		{
			estimated = (p + gr / 100 * p);
			p = estimated;
			count++;
		}
	
return estimated;
}
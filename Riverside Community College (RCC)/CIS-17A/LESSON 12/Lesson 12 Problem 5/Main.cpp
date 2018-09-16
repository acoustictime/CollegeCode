// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 12-2-06															*
// *																	*
// * This program adds up five different numbers using a template       *
// * function.															*
// **********************************************************************

#include <iostream>

using namespace std;

// **********************************************************************
// * Definition of the function: Total						     	    *
// * This template function takes as it's arguement the amount of       *
// * numbers to add together.  It then asks the user for the amount of  *
// * numbers and adds them together.								    *
// **********************************************************************

template <class T>
void Total(T amount)
{
	T total = 0;
	T num;
	
	cout << "Enter " << amount << " numbers: ";

	for (int index = 0; index < amount; index++)
	{
		cin >> num;
		total = total + num;
	}

	cout << "The total of the numbers is: " << total << endl << endl;
}

int main()
{
	int amount;

	cout << "Enter the amount of numbers you wish to add together: ";
	cin >> amount;
	Total(amount);

return 0;
}
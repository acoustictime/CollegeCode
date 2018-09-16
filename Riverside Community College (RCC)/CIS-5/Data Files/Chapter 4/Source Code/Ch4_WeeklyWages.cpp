//Program: Weekly wages
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	double wages, rate, hours;

	cout << fixed << showpoint << setprecision(2);			//Line 1
	cout << "Line 2: Enter working hours and rate: ";  		//Line 2
	cin >> hours >> rate;  									//Line 3

	if (hours > 40.0)  										//Line 4
		 wages = 40.0 * rate + 
			 	1.5 * rate * (hours - 40.0);				//Line 5
	else													//Line 6
		 wages = hours * rate;								//Line 7

	cout << endl;											//Line 8
	cout << "Line 9: The wages are $" <<  wages << endl;	//Line 9

  return 0;
}

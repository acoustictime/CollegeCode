// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 11-30-06															*
// *																	*
// * This driver program uses a function template to return the absolute*
// * value of value passed in to it.	*
// **********************************************************************

#include <iostream>
#include <cmath>

using namespace std;

// **********************************************************************
// * Definition of the function: absolute							    *
// * This template function takes as it's arguements a template value   *
// * and returns the absolute value of it.							    *
// **********************************************************************

template <class T>
T absolute(T number)
{
	return abs(number);
}

int main()
{
	cout << "Absolute of the int is " << absolute(-5);
	cout << "\nAbsolute of the double is " << absolute(-4.5);
	cout << "\nAbsolute of the float is " << absolute(-143434);
	cout << "\nAbsolute of the char is " << absolute('a') << endl;

return 0;
}
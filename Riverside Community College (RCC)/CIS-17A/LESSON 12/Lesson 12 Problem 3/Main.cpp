// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 12-2-06															*
// *																	*
// * This driver program compares the two numbers and returns either the*
// * Min or Max number.  It uses two templates to do this.				*
// **********************************************************************

#include <iostream>

using namespace std;

// **********************************************************************
// * Definition of the function: Max								    *
// * This template funciton returns the larger number of the two passed *
// * to it as arguements.											    *
// **********************************************************************

template<class T1,class T2>
T2 Max(T1 num1,T2 num2)
{
	if(num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

// **********************************************************************
// * Definition of the function: Min								    *
// * This template funciton returns the lesser number of the two passed *
// * to it as arguements.											    *
// **********************************************************************

template<class T1,class T2>
T2 Min(T1 num1,T2 num2)
{
	if(num1 < num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

int main()
{

	cout << "Min between 1.5 and 6 is " << Min(1.5, 6);
	cout << "\nMin between 3.456 and 13 is " << Min(3.456, 13);
	cout << "\nMax between 1335.53434 and 534 is " << Max(1335.53434, 534);
	cout << "\nMax between .00001 and .00002 is " << Max(.00001, .00002) << endl << endl;

return 0;
}
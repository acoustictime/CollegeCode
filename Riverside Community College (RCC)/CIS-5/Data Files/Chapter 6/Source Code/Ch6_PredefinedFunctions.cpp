// How to use predefined functions.
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
	int   x;
	double  u,v;
	
	cout << "Line 1: Uppercase a is "
		 << static_cast<char>(toupper('a'))
		 << endl; 									//line 1

	u = 4.2;										//line 2
	v = 3.0;										//line 3
	cout << "Line 4: " << u << " to the power of "
		 << v << " = " << pow(u, v) << endl; 		//line 4

	cout << "Line 5: 5 to the power of 4 = "
		 << pow(5, 4) << endl;		 				//line 5

	u = u + pow(3, 3);								//line 6
	cout << "Line 7: u = " << u << endl;			//line 7

	x = -15;										//line 8
	cout << "Line 9: Absolute value of " << x
		 << " = " << abs(x) << endl;  				//line 9

	return 0;
}

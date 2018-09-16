//Example: setprecision, fixed, showpoint

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, y, z;

	x = 15.674;										//Line 1
	y = 235.73;										//Line 2
	z = 9525.9864;									//Line 3

	cout << fixed << showpoint;						//Line 4

	cout << setprecision(2)
		 << "Line 5: setprecision(2)" << endl;		//Line 5
	cout << "Line 6: x = " << x << endl;			//Line 6
	cout << "Line 7: y = " << y << endl;			//Line 7
	cout << "Line 8: z = " << z << endl;			//Line 8

	cout << setprecision(3)
		 << "Line 9: setprecision(3)" << endl;		//Line 9
	cout << "Line 10: x = " << x << endl;			//Line 10
	cout << "Line 11: y = " << y << endl;			//Line 11
	cout << "Line 12: z = " << z << endl;			//Line 12

	cout << setprecision(4)
		 << "Line 13: setprecision(4)" << endl;		//Line 13
	cout << "Line 14: x = " << x << endl;		    //Line 14
	cout << "Line 15: y = " << y << endl;		    //Line 15
	cout << "Line 16: z = " << z << endl;			//Line 16

	cout << "Line 17: "
		 << setprecision(3) << x << "  "
		 << setprecision(2) << y << "  "
		 << setprecision(4) << z << endl;			//Line 17

	return 0;
}




//Example: setw 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x = 19;							         //Line 1
	int a = 345;						         //Line 2
	double y = 76.384;					         //Line 3

	cout << fixed << showpoint;				     //Line 4

	cout << "12345678901234567890" << endl;	     //Line 5

	cout << setw(5) << x << endl;				 //Line 6
	cout << setw(5) << a << setw(5) << "Hi"
		 << setw(5) << x << endl << endl;		 //Line 7
	
	cout << setprecision(2);				     //Line 8
	cout << setw(6) << a << setw(6) << y
		 << setw(6) << x << endl;				 //Line 9
    cout << setw(6) << x << setw(6) << a
		 << setw(6) << y << endl << endl;		 //Line 10

	cout << setw(5) << a << x << endl;			 //Line 11
	cout << setw(2) << a << setw(4) << x << endl;	//Line 12

	return 0;
}



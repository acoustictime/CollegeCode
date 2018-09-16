//Input Failure program
#include <iostream>
using namespace std;

int main()
{
	int a = 10;									     //Line 1
	int b = 20;									     //Line 2
	int c = 30;									     //Line 3
	int d = 40;									     //Line 4
	
	cout << "Line 5: Enter four integers: ";		 //Line 5 
	cin >> a >> b >> c >> d;					     //Line 6
	cout << endl;									 //Line 7
	cout << "Line 8: The numbers you entered are:"
		 << endl;									 //Line 8
	cout << "Line 9: a = " << a << ", b = " << b		
		 << ", c = " << c << ", d = " << d << endl;	 //Line 9

	return 0;
}

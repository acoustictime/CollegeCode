//Example: left justification

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x = 15;								  	   //Line 1
	int y = 7634;								   //Line 2

	cout << left;								   //Line 3
	
	cout << "12345678901234567890" << endl;		   //Line 4
	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			   //Line 5

	cout << setfill('*');						   //Line 6

	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			   //Line 7


	cout << setw(5) << x << setw(7) << setfill('#')
		 << y << setw(8) << "Warm" << endl;		   //Line 8


	cout << setw(5) << setfill('@') << x
		 << setw(7) << setfill('#') << y
		 << setw(8) << setfill('^') << "Warm" 
		 << endl;	                               //Line 9

	cout << right;						           //Line 10
	cout << setfill(' ');						   //Line 11

	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			   //Line 12

	return 0;
}
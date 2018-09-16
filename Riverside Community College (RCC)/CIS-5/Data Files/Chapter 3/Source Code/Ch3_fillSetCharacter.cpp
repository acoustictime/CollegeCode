//Example: setfill

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	int x = 15;								      //Line 1			
	int y = 7634;							      //Line 2

	cout << "12345678901234567890" << endl;		  //Line 3
	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			  //Line 4

	cout << setfill('*');						  //Line 5
	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			  //Line 6			

	cout << setw(5) << x << setw(7) << setfill('#')	
		 << y << setw(8) << "Warm" << endl;		  //Line 7

	cout << setw(5) << setfill('@') << x
		 << setw(7) << setfill('#') << y
		 << setw(8) << setfill('^') << "Warm"
		 << endl;								  //Line 8

	cout << setfill(' ');						  //Line 9
	cout << setw(5) << x << setw(7) << y
		 << setw(8) << "Warm" << endl;			  //Line 10

	return 0;
}
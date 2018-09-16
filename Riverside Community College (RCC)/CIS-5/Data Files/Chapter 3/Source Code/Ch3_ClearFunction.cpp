//Input failure and the clear function
#include <iostream>
using namespace std;

int main()
{
    int a = 23;								      //Line 1
    int b = 34;								      //Line 2

    cout << "Line 3: Enter a number followed"
 	    << " by a character: ";				      //Line 3
    cin >> a >> b;								  //Line 4
    cout << endl << "Line 5: a = " << a
 	     << ", b = " << b << endl;				  //Line 5

    cin.clear();		    //Restore input stream; Line 6

    cin.ignore(200,'\n');       //Clear the buffer; Line 7

    cout << "Line 8: Enter two numbers: ";		  //Line 8
    cin >> a >> b;								  //Line 9
    cout << endl << "Line 10: a = " << a
	     << ", b = " << b << endl;			      //Line 10

	return 0;
}

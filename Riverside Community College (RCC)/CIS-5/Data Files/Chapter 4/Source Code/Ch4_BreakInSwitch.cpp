//Program: Effect of break statements in a switch structure

#include <iostream>
using namespace std;

int main ()
{
	int a;

	cout << "Enter an integer between 0 and 10: ";			//Line 1
	cin >> a;												//Line 2

	cout << "\nThe number you entered is " << a << endl;	//Line 3
	
	switch (a)												//Line 4
    {
     case 0:												//Line 5
     case 1: cout << "Hello ";								//Line 6
     case 2: cout << "there. ";								//Line 7
     case 3: cout << "I am ";								//Line 8
     case 4: cout << "Mickey." << endl;						//Line 9
	         break;											//Line 10
     case 5: cout << "How ";								//Line 11
     case 6:												//Line 12
     case 7:												//Line 13
     case 8: cout << "are you?" << endl;					//Line 14
	         break;											//Line 15
     case 9: break;											//Line 16
     case 10: cout << "Have a nice day." << endl;			//Line 17
	          break;										//Line 18
     default: cout << "Sorry, the number is out of "	
				   << "range." << endl;						//Line 19
     }

     cout << "Out of switch structure." << endl;			//Line 20

     return 0;
}

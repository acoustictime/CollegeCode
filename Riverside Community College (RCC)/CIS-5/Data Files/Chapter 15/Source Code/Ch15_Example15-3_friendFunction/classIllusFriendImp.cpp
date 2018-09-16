
#include <iostream>
#include "classIllusFriend.h"

using namespace std;

void classIllusFriend::print()
{
	cout << "In class classIllusFriend: x = " << x << endl;
}

void classIllusFriend::setx(int a)
{
	x = a;
}

void two(classIllusFriend cIFObject)				//Line 1
{
	classIllusFriend localTwoObject;				//Line 2

	localTwoObject.x = 45;							//Line 3

	localTwoObject.print();							//Line 4
	cout << endl;									//Line 5
	cout << "Line 6: In Friend Function two accessing "
		 << "private data member x = "
		 << localTwoObject.x << endl;				//Line 6
	
	cIFObject.x = 88;								//Line 7

	cIFObject.print();								//Line 8
	cout << endl;									//Line 9
	cout << "Line 10: In Friend Function two accessing "
		 << "private data member x = "
		 << cIFObject.x << endl;					//Line 10
}
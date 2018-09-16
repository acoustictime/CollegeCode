//Friend Function Illustration

#include <iostream>
#include "classIllusFriend.h"

using namespace std;

int main()
{	
	classIllusFriend aObject;						//Line 11

	aObject.setx(32);								//Line 12

	cout << "Line 13: aObject.x: ";					//Line 13
	aObject.print();								//Line 14
	cout << endl;									//Line 15
	cout << "*~*~*~*~*~* Testing Friend Function "
		 << "two *~*~*~*~*~*" << endl << endl;		//Line 16

	two(aObject);									//Line 17

	return 0;
}




#include <iostream>

#include "derivedClass.h"

using namespace std;

void callPrint(baseClass& p);

int main()
{
	baseClass one(5);						//Line 1
	derivedClass two(3, 15);				//Line 2

	one.print();							//Line 3
	two.print();							//Line 4

	cout << "*** Calling the function callPrint  ***"
		 << endl;							//Line 5
	callPrint(one); 						//Line 6
	callPrint(two); 						//Line 7

	return 0;
}

void callPrint(baseClass& p)
{	
	p.print();
}

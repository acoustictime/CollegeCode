//Chapter 14: Virtual Functions

#include <iostream>

#include "derivedClass.h"

using namespace std;

void callPrint(baseClass *p);

int main()
{
	baseClass *q;							//Line 1
	derivedClass *r;						//Line 2

	q = new baseClass(5);					//Line 3
	r = new derivedClass(3,15);				//Line 4

	q->print();								//Line 5
	r->print();								//LIne 6

	cout << "*** Calling the function callPrint  ***"
		 << endl;								//Line 7
	callPrint(q);							//Line 8
	callPrint(r);							//Line 9

	return 0;
}


void callPrint(baseClass *p)
{
	p->print();
}


//Test program for constructor with default values

#include <iostream>
#include "testClassConstructor.h"

using namespace std;

int main()
{
	testClass  one;					//Line 1
	testClass  two(5, 6);			//Line 2
	testClass  three(5, 7, 4.5);	//Line 3
	testClass  four(4, 9, 12);		//Line 4
	testClass  five(3.4, 'D');		//Line 5

	one.print();					//Line 6; output one
	two.print();					//Line 7; output two
	three.print();					//Line 8; output three
	four.print();					//Line 9; output four
	five.print();					//Line 10; output five

	return 0;
}

//Constructor with default values implementation file

#include <iostream>
#include "testClassConstDefaultValues.h"

using namespace std;

void testClass::print() const
{
	cout << "x = " << x << ", y = " << y << ", z = " << z
		 << ", ch = " << ch << endl;
}


testClass::testClass(int tX, int  tY, double tZ, char tCh)
{
	x = tX;
	y = tY;
	z = tZ;
	ch = tCh;
}

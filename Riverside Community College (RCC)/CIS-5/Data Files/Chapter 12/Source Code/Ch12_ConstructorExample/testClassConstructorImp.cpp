//Constructor with default values implementation file

#include <iostream>
#include "testClassConstructor.h"

using namespace std;

void testClass::print() const
{
	cout << "x = " << x << ", y = " << y << ", z = " << z
		 << ", ch = " << ch << endl;
}


testClass::testClass()	//default constructor
{
	x = 0;
	y = 0;
	z = 0;
	ch = '*';
}

testClass::testClass(int tX, int tY)
{
	x = tX;
	y = tY;
	z = 0;
	ch = '*';
}

testClass::testClass(int tX, int tY, double tZ)
{
	x = tX;
	y = tY;
	z = tZ;
	ch = '*';
}

testClass::testClass(double tZ, char tCh)
{
	x = 0;
	y = 0;
	z = tZ;
	ch = tCh;
}

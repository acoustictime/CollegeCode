//Chapter 14: Example 14-2

#include <iostream>

using namespace std;

int main()
{
	int *p;
	int x = 37;

	cout << "Line 1: x = " << x << endl;				//Line 1

	p = &x;												//Line 2

	cout << "Line 3: *p = " << *p
		 << ", x = " << x << endl;						//Line 3
	
	*p = 58;											//Line 4

	cout << "Line 5: *p = " << *p
		 << ", x = " << x << endl;						//Line 5

	cout << "Line 6: Address of p = " << &p << endl;	//Line 6

	cout << "Line 7: Value of p = " << p << endl;		//Line 7

	cout << "Line 8: Value of the memory location "
		 << "pointed to by, *p = " << *p << endl;		//Line 8
	cout << "Line 9: Address of x = " << &x << endl;	//Line 9
	cout << "Line 10: Value of x = " << x << endl;		//Line 10

	return 0;
}
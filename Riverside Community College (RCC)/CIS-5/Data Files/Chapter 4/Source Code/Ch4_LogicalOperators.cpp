//Chapter 4 Logical operators

#include <iostream>

using namespace std;

int main()
{
	bool found = true;
	bool flag = false;
	int num = 1;
	double x = 5.2;
	double y = 3.4;
	int a = 5, b = 8;
	int n = 20;
	char ch = 'B';

	cout << "Line 1: !found evaluates to "	
		 << !found << endl;									//Line 1
	cout << "Line 2: x > 4.0 evaluates to "
		 << (x > 4.0) << endl;								//Line 2
	cout << "Line 3: !num evaluates to "
		 << !num << endl;									//Line 3
	cout << "Line 4: !found && (x >= 0) evaluates to "
		 << (!found && (x >= 0)) << endl;					//Line 4
	cout << "Line 5: !(found && (x >= 0)) evaluates to "
		 << (!(found && (x >= 0))) << endl;					//Line 5
	cout << "Line 6: x + y <= 20.5 evaluates to "
		 << (x + y <= 20.5) << endl;						//Line 6
	cout << "Line 7: (n >= 0) && (n <= 100) evaluates to "
		 << ((n >= 0) && (n <= 100)) << endl;				//Line 7
	cout << "Line 8: ('A' <= ch && ch <= 'Z') evaluates to "
		 << ('A' <= ch && ch <= 'Z') << endl;				//Line 8
	cout << "Line 9: (a + 2 <= b) && !flag evaluates to "
		 << ((a + 2 <= b) && !flag) << endl;				//Line 9

	return 0;
}


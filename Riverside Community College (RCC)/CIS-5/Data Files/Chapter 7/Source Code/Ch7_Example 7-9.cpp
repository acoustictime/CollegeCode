//Example 7-9: Reference and value parameters

#include <iostream>

using namespace std;

int t;

void funOne(int& a, int& x);

int main()
{
	int num1, num2;

	num1 = 10;											//Line 1
	num2 = 20;											//Line 2	
	t = 15;												//Line 3

	cout << "Line 4: In main: num1 = " << num1 << ", num2 = "
		 << num2 << ", and t = " << t  << endl;			//Line 4
   							
	funOne(num1, t);									//Line 5
	cout << "Line 6: In main after funOne: " << "num1 = "
    	 << num1 << ", num2 = " << num2 << ", and t = " << t
 		 << endl;										//Line 6

	return 0;											//Line 7
}

void funOne(int& a, int& x)
{
	int z;

	z = a + x;											//Line 8

	cout << "Line 9: In funOne: a = " << a << ", x = " << x
		 << ", z = " << z << ", and t = " << t << endl; //Line 9
			
	x = x + 5;											//Line 10
	cout << "Line 11: In funOne: a = " << a << ", x = " << x
		 << ", z = " << z << ", and t = " << t << endl; //Line 11
				
	a = a + 12; 										//Line 12
	cout << "Line 13: In funOne: a = " << a << ", x = " << x
		 << ", z = " << z << ", and t = " << t << endl; //Line 13
				
	t = t + 13;											//Line 14

	cout << "Line 15: In funOne: a = " << a << ", x = " << x
		 << ", z = " << z << ", and t = " << t << endl; //Line 15
				
}

//Example string relational operations

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2, str3, str4; 		//Line 1

	str1 = "Hello";						//Line 2
	str2 = "Hi";						//Line 3
	str3 = "Air";						//Line 4
	str4 = "Bill";						//Line 5
	
	if (str1 < str2)
		cout << "Line 6: true" << endl; 	//Line 6
	else
		cout << "Line 7: false" << endl; 	//Line 7

	if (str1 > "Hen")
		cout << "Line 8: true" << endl; 	//Line 8
	else 
		cout << "Line 9: false" << endl; 	//Line 9

	if (str3 < "An")	
		cout << "Line 10: true" << endl; 	//Line 10
	else 
		cout << "Line 11: false" << endl; 	//Line 11
	
	if (str1 == "hello")
		cout << "Line 12: true" << endl; 	//Line 12
	else 
		cout << "Line 13: false" << endl; 	//Line 13
		
	if (str4 >= "Billy")	
		cout << "Line 14: true" << endl; 	//Line 14
	else 
		cout << "Line 15: false" << endl; 	//Line 15

	return 0;
}


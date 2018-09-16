//Example length function

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name, firstName;								//Line 1
	string str;											//Line 2
	string::size_type len;								//Line 3
	
	firstName = "Elizabeth";							//Line 4
	name = firstName + " Jones";						//Line 5
	str = "It is sunny and warm.";						//Line 6

	cout << "Line 7: Length of \"" << firstName << "\" = " 
		 << static_cast<unsigned int> (firstName.length())
		 << endl;										//Line 7
	cout << "Line 8: Length of \"" << name << "\" = " 
		 << static_cast<unsigned int> (name.length())
		 << endl;										//Line 8  	
	cout << "Line 9: Length of \"" << str << "\" = " 
		 << static_cast<unsigned int> (str.length()) 
		 << endl;	                                    //Line 9

	len = firstName.length();   						//Line 10
	cout << "Line 11: len = " 
		 << static_cast<unsigned int> (len) 
		 << endl;										//Line 11

	len = name.length();								//Line 12
	cout << "Line 13: len = " 
		 << static_cast<unsigned int> (len) << endl;	//Line 13

	len = str.length();									//Line 14
	cout << "Line 15: len = " 
		 << static_cast<unsigned int> (len) << endl;	//Line 15

	return 0;
}


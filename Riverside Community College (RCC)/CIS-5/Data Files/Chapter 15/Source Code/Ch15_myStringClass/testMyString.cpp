//Test Program
#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
	newString str1 = "Sunny"; 		//initialize str1 using 
									//the assignment operator 
	const newString str2("Warm");	//initialize str2 using 
									//the conversion constructor
	newString str3;  //initialize str3 to null
	newString str4;  //initialize str4 to null

	cout << "Line 1: " << str1 << "    " << str2 << "  ***"
		 << str3 << "###." << endl; 					//Line 1

	if (str1 <= str2)     	     //compare str1 and str2; Line 2
		cout << "Line 3: " << str1 << " is less than " 
 			 << str2 << endl; 							//Line 3
	else												//Line 4
		cout << "Line 5: " << str2 << " is less than "
   			 << str1 << endl; 							//Line 5

	cout << "Line 6: Enter a string with a length "
		 << "of at least 7: ";  						//Line 6
	cin >> str1;         				//input str1;	  Line 7
	cout << endl << "Line 8: The new value of str1 = "
 		 << str1 << endl;   		 					//Line 8

	str4 = str3 = "Birth Day";							//Line 9
	cout << "Line 10: str3 = " << str3 << ", str4 = "
		 << str4 << endl;								//Line 10

	str3 = str1;										//Line 11
	cout << "Line 12: The new value of str3 = "
		 << str3 << endl;	                            //Line 12

	str1 = "Bright Sky";  								//Line 13

	str3[1] = str1[5];									//Line 14
	cout << "Line 15: After replacing the second "
		 << "character of str3 = " << str3 << endl; 	//Line 15

	str3[2] = str2[0];				  					//Line 16
	cout << "Line 17: After replacing the third "
		 << "character of str3 = " << str3 << endl; 	//Line 17

	str3[5] = 'g'; 										//Line 18
	cout << "Line 19: After replacing the sixth "
		 << "character of str3 = " << str3 << endl; 	//Line 19

	return 0;
}
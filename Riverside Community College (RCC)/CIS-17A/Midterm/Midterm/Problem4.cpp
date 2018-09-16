// Problem4.cpp: implementation of the Problem4 class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "Problem4.h"

using namespace std;

const int arraysize = 4;

Problem4::Problem4()
{
	
}

// **********************************************************************
// * Definition of the function: Problem4::encrypt					    *
// * This member function encrypts the values stored in the num internal*
// * array.  It encrypts each value in the array by adding 3 to it. Then*
// * by taking the modulus of it.  Lastly it swaps value 1 with 2 and 3 *
// * with 4 and outputs the encrypted number.						    *
// **********************************************************************

void Problem4::encrypt()
{
	int temp;
	
	for (int index = 0; index < arraysize; index++) // Loop adds 3 to every number then takes the modulus
	{
		num[index] = (num[index] + 3) % 8;
	}
		
// Swaps value 1 with 2 and 3 with 4
	
	temp = num[0];
	num[0] = num[1];
	num[1] = temp;

	temp = num[2];
	num[2] = num[3];
	num[3] = temp;
	
	cout << "\nThe encrypted code is: ";

	for (index = 0; index < arraysize; index++) // Loop outputs the encrypted code
	{
		cout << num[index];
	}
		
	cout << endl;
}

// **********************************************************************
// * Definition of the function: Problem4::decrypt					    *
// * This member function decrypts the values stored in the num internal*
// * array.  It decrypts each value in the array by reversing the       *
// * encryption from the encrypt function.							    *
// **********************************************************************	

void Problem4::decrypt()
{
	int temp;

// Swaps value 1 with 2 and 3 with 4

	temp = num[0];
	num[0] = num[1];
	num[1] = temp;

	temp = num[2];
	num[2] = num[3];
	num[3] = temp;
	
	for (int index = 0; index < arraysize; index++) // Reverses the modulus and 3 addition done in the encrypt function
	{
		if (num[index] > 2)
		{
			num[index] = num[index] - 3;
		}
		else
		{
			num[index] = num[index] + 5;
		}
	}

	cout << "\nThe decrypted code is: ";

	for (index = 0; index < arraysize; index++) // Displays decrypted code
	{
		cout << num[index];
	}
		
	cout << endl; 
}

// **********************************************************************
// * Definition of the function: Problem4::enternum					    *
// * This member function takes as it's arguments an int for the        *
// * subscript and a char for the value being entered.  It converts the *
// * char to a int and stores it in the internal num array.  It then    *
// * calls the valid private function.  Depending on if the value is ok,*
// * it will return true or false back to main.						    *
// **********************************************************************

bool Problem4::enternum(int i, char a)
{
	bool status;
	
	char *test = &a; // Assignes the char's memory address to a pointer

	num[i] = atoi(test); // Converts the pointer to an int in the num array at location i.

	if(valid(num[i])) // Checks if the num is valid.  Returns false if not, true if it is.
	{
		status = true;
	}
	else
	{
		status = false;
	}
return status;
}

// **********************************************************************
// * Definition of the function: Problem4::valid					    *
// * This private member function takes as it's arguements an int for   *
// * the number to be checked.  If it between 0 and 7, it returns true, *
// * and false if not.												    *
// **********************************************************************

bool Problem4::valid(int num)
{
	bool status;

	if (num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7) // Checks if between 0 and 7
	{
		status = true;
	}
	else
	{
		status = false;
	}
return status;
}

	




		
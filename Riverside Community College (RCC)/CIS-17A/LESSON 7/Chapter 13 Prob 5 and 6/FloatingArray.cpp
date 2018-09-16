// FloatingArray.cpp: implementation of the FloatingArray class.
//
//////////////////////////////////////////////////////////////////////

#include "FloatingArray.h"

// **********************************************************************
// * Definition of the function: FloatingArray::FloatingArray		    *
// * This is the constructor function that dynmaically allocates an     *
// * array and initializes it's values to 0.						    *
// **********************************************************************

FloatingArray::FloatingArray(int size)
{
	ptr = new int[size];
	arraysize = size;

	for (int index = 0; index < arraysize; index++) // Loop sets the value of each element to 0
	{
		ptr[index] = 0;
	}
}

// **********************************************************************
// * Definition of the function: FloatingArray::~FloatingArray		    *
// * This is the deconstructor function that deletes the dynamically    *
// * allocated array.												    *
// **********************************************************************

FloatingArray::~FloatingArray()
{
	delete [] ptr;
}

// **********************************************************************
// * Definition of the function: FloatingArray::valid				    *
// * This member function takes as it's arguement and interger.  It then*
// * returns true if the value is between 0 and the size of the array.  *
// **********************************************************************

bool FloatingArray::valid(int element)
{
	bool status;

	if(element < 0 || element >= arraysize) // Used if the element is outside of the range
	{
		status = false;
	}
	else
	{
		status = true;
	}
return status;
}

// **********************************************************************
// * Definition of the function: FloatingArray::enter				    *
// * This member function takes as it's agruements, and int for the     *
// * the element and an interger for a value.  It returns true if the   *
// * value entered was valid and sets the element of the array to the   *
// * value.															    *
// **********************************************************************

bool FloatingArray::enter(int element, int value)
{
	bool status;

	if (valid(element)) // Used if element is outside of the range
	{
		ptr[element] = value;
		status = true;
	}
	else
	{
		status = false;
	}
return status;
}

// **********************************************************************
// * Definition of the function: FloatingArray::retrieve			    *
// * This member function takes as it's arguements an interger for the  *
// * element of the array, and an interger passed by reference.  It     *
// * returns true if the element is valid and then sets the value to the*
// * value in the array set by the element.  It returns the value.	    *
// **********************************************************************

bool FloatingArray::retrieve(int element, int &value)
{
	bool status;

	if (valid(element)) // Used if element is outside of range
	{
		value = ptr[element];
		status = true;
	}
	else
	{
		status = false;
	}
return status;
}

// **********************************************************************
// * Definition of the function: FloatingArray::average				    *
// * This member function determines the average of the numbers in the  *
// * array and returns the value.									    *
// **********************************************************************

double FloatingArray::average()
{
	double average = 0;

	for (int index = 0; index < arraysize; index++) // Loop sums up the values in the array
	{
		average = average + ptr[index];
	}

	average = average / arraysize;

return average;
}

// **********************************************************************
// * Definition of the function: FloatingArray::highest				    *
// * This member function returns the index of the highest value stored *
// * in the array.													    *
// **********************************************************************

int FloatingArray::highest()
{
	int highestindex = 0;

	for (int index = 1; index < arraysize; index++) // Loop determines the index of the highest value in the array
	{
		if (ptr[index] > ptr[highestindex])
		{
			highestindex = index;
		}
	}
return highestindex;
}

// **********************************************************************
// * Definition of the function: FloatingArray::lowest				    *
// * This member function returns the index of the lowest value stored *
// * in the array.													    *
// **********************************************************************

int FloatingArray::lowest()
{
	int lowestindex = 0;

	for (int index = 1; index < arraysize; index++)  // Loop determines the index of the lowest value in the array
	{
		if (ptr[index] < ptr[lowestindex])
		{
			lowestindex = index;
		}
	}
return lowestindex;
}





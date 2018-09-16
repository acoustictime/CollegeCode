// *************************************************************************
// * James Small														   *
// * Cis-17a															   * 
// * 9-14-06															   *
// *																	   *
// * This program takes an array of intergers and passes it to a function  *
// * using a pointer.  It then determines the mode of the list of numbers, *
// * and returns a pointer to a dynamcially created array, with the first  *
// * position the size of the array, and the next positions, the values of *
// * the mode.															   *
// *************************************************************************																	

#include <iostream>

using namespace std;

void getscores(int *ptr, int size);
int *modefunc(int *ptr, int size);
void printmode(int *ptr, int *ptr2, int size);

int main()
{
	int size; 
	cout << "Enter the amount of numbers in the array ";
	cin >> size;
 
	while  (size < 2) // Confirms the number is at least 2
	{
		 cout << "\nThe number must be at least 2\n";
		 cout << "Enter the amount of numbers in the array ";
		 cin >> size;
	}
	cout << endl;
 
	int *arrayptr;
	int *modeptr;
	
	arrayptr = new int[size];
	getscores(arrayptr, size);
	modeptr = modefunc(arrayptr, size);
	printmode(modeptr, arrayptr, size);

	delete [] arrayptr;
	delete [] modeptr;
	
return 0;
}

// *********************************************************************
// * Definition of the function: getscores							   *
// * This function prompts the user for the values that will be in the *
// * array.  It's arguements are the pointer to the array, and the     *
// * array's size.													   *
// *********************************************************************

void getscores(int *ptr, int size)
{
	for (int count = 0; count < size; count++) // Allows input to the array.
	{ 
		cout << "Enter number " << count + 1 << ": ";
		cin >> *(ptr + count);
  
		while (*(ptr + count) < 0) // Confirms the number isn't negative.
		{
			cout << "\nThe number must not be negative\n";
			cout << "Enter number " << count + 1 << ": ";
			cin >> *(ptr + count); 
		}
		cout << endl;
	}
 
}

// *********************************************************************
// * Definition of the function: modefunc							   *
// * This function takes as it's arguements, a pointer to an array,    *
// * and the array's size.  It uses dynamic memory allocation to       *
// * determine the mode of the orignal array.  To do this, I create    *
// * two dymanicly allocated arrays, and use them to total how many    *
// * times each number appears.  You can then determine the mode by    *
// * looking at how many times each number appears. It then passes     * 
// * back a dynamically created array, the first position of which is  *
// * the array's size, the rest of the positions are the mode itself.  *
// *********************************************************************

int *modefunc(int *ptr, int size)
{
//	Sort Array in Ascending Order using a selection sort

	int startScan, minIndex;
	int minElem;
	
	for (startScan = 0; startScan < (size - 1); startScan++) // Selection sort
	{
		minIndex = startScan;
		minElem = *(ptr + startScan);
		
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(ptr + index) < minElem)
			{
				minElem = *(ptr + index);
				minIndex = index;
			}
		}
		
		*(ptr + minIndex) = *(ptr + startScan);
		*(ptr + startScan) = minElem;
	}

//	Create two arrays that I will use to find the mode.
//  I also initialized the values in these arrays.

	int *values, *totals;

	values = new int[size];
	totals = new int[size];	

	for (int count = 0; count < size; count++) // Initializes the values
	{
		*(values + count) = 0;
		*(totals + count) = 0;
	}	

//	Using two arrays, I total how many times
//  each number appears in the original array
//  using the subscripts of each array
	
	int current = 0;
	*(values + current) = *(ptr + current);
	*(totals + current) = 1;
	
	for (count = 1; count < size; count++)				// Checks each value of the array and stores them in the values
	{													// array and using subscripts, stores each number,s total in the 
		if (*(ptr + count) == *(values + current))	    // totals array
		{
			*(totals + current) = *(totals + current) + 1;
		}
		else
		{
			current++;
			*(values + current) = *(ptr + count);
			*(totals + current) = *(totals + current) + 1;
		}
	}

//	Find the total for the value that occurs most often

	int highest;
	
	highest = totals[0];
	
	for (count = 1; count < size; count++) // Finds the highest value in the totals array
	{
		if (*(totals + count) > highest)
		{
			highest = *(totals + count);
		}
	}

// 	Determine how many intergers are in the mode,
//  if no number occurs more than once, set mode
//	bool to true.

	int modesize = 0;
	bool ifmode = false;
	
	if (highest >= 2)
	{		
		for (count = 0; count < size; count++) // Determines how many values are in the mode by comparing
		{									   // the values to the highest total number
			if (*(totals + count) == highest)
			{
				modesize++;
			}
		}
	}
	else
	{
		modesize = 1;
		ifmode = true; // Sets bool to true because no number occurs more than once.
	}

//	Create another dynamic new array

	int *mode;

	mode = new int[modesize + 1];	

//	Store the size and mode in new dynamic array.
//  If there is no modev, it uses a bool to set the
//  mode value to -1

	current = 0;
	*(mode + current) = modesize + 1; // Stores the mode size in the mode array
	current++;
	
	if (ifmode) // Stores the mode into the mode array.
	{
		*(mode + current) = -1;
	}
	else
	{
		for (count = 0; count < size; count++)
		{
					
			if (*(totals + count) == highest)
			{
				*(mode + current) = *(values + count);
				current++;			
			}
		}
	}

	delete [] values;
	delete [] totals;

return mode;
}

// *********************************************************************
// * Definition of the function: printmode							   *
// * This function takes as it's arguement, the original array, the    *
// * mode array, and the array's size.  It then prints out the original*
// * array, the mode (if any), and the mode array's size.			   *
// *********************************************************************

void printmode(int *ptr, int *ptr2, int size)
{
	int count;
	
	if (*(ptr + 1) == -1) // Determines if there was a mode
	{
		cout << "The array's size is " << *(ptr) << ", but\n"
			 << "there is no mode because no\n"
			 << "number occurs more than once.\n";
	}
	else
	{		
		cout << "The array's size is " << *(ptr) << ", and\n"
			 << "the mode of the following list of numbers:\n\n";
		 
		cout << "{";
		
		for (count = 0; count < size; count++) // Displays original values of the array
		{
			cout << *(ptr2 + count);

			if (count == size - 1)
			{
				cout << "} ";
			}
			else
			{
				cout << ",";
			}
		}

		cout << "\n\nis {";

		for (count = 1; count < *(ptr); count ++) // Displays the mode values from the array
		{
			cout << *(ptr + count);

			if (count == (*(ptr) - 1))
			{
				cout << "} ";
			}
			else
			{
				cout << ",";
			}
		}
		cout << "because they occur the most times in the list.\n";
	}
}

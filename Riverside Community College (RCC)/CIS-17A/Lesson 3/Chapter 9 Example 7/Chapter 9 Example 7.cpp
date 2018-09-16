// *************************************************************************
// * James Small														   *
// * Cis-17a															   * 
// * 9-16-06															   *
// *																	   *
// * This program takes an array of intergers and passes it to a function  *
// * using a pointer.  It then determines the median of the list.  It      *
// * returns a float for the median and then prints the results			   *
// *************************************************************************																	

#include <iostream>
#include <iomanip>

using namespace std;

void getscores(int *ptr, int size);
float medianfunc(int *ptr, int size);
void printmedian(int *ptr, float value, int size);

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
	float median;
	
	arrayptr = new int[size];
	getscores(arrayptr, size);
	median = medianfunc(arrayptr, size);
	printmedian(arrayptr, median, size);

	delete [] arrayptr;
	
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
// * Definition of the function: medianfunc							   *
// * This function takes as it's arguements, a pointer to an array,    *
// * and the array's size.  It then determines the median of the list  *
// * of numbers and returns a float for the median                     *
// *********************************************************************

float medianfunc(int *ptr, int size)
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

// Determine if there is an even or odd number of intergers and then determine the median

	float median;
	
	if (size % 2 == 0)
	{
		median = static_cast<float>(*(ptr + ((size / 2) - 1)) + *(ptr +(size / 2))) / 2;  // Static cast to convert the int to float
	}
	else
	{
		median = *(ptr + (size / 2));
	}

return median;
}

// *********************************************************************
// * Definition of the function: printmedian						   *
// * This function takes as it's arguement, the original array, the    *
// * array's size, and the median.  It then prints out the original    *
// * array, and the median of the array.							   *
// *********************************************************************

void printmedian(int *ptr, float value, int size)
{
	int count;
	
	cout << "The median of the following list of numbers: \n\n";
		
	cout << "{";
		
	for (count = 0; count < size; count++) // Displays original values of the array
	{
		cout << *(ptr + count);

		if (count == size - 1)
		{
			cout << "} ";
		}
		else
		{
			cout << ",";
		}
	}

	cout << setprecision(2);
	cout << "\n\nis " << value << ", because it's the middle number of the list.\n";	
}

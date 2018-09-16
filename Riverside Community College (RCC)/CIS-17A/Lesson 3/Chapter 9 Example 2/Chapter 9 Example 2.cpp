// **************************************************************
// * James Small												*
// * Cis-17a													*
// * 9-14-06													*
// *															*
// * This program uses dynamic memory allocation to define an   *
// * array.  It then uses multiple functions to sort the array, *
// * find the average of the array, and print the array.        *
// **************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int *array(int amount);
void getscores(int* arrayptr, int amount);
void sortarray(int* arrayptr, int amount);
void avg(int* arrayptr, int amount, double &average);
void print(int* arrayptr, int amount, double average);

int main()
{
	int amount;
	double average = 0;
	
	cout << "Enter the number of test scores to calculate: ";
	cin >> amount;

	while (amount < 1) // Confirms the amount is at least 1
	{
		cout << "\nEnter at least 1 for the amount\n";
		cout << "Enter the number of test scores to calculate: ";
		cin >> amount;
	}

	int *ptr;
	ptr = array(amount);

	getscores(ptr, amount);
	sortarray(ptr, amount);
	avg(ptr, amount, average);
	print(ptr, amount, average);
		
return 0;
}

// **********************************************************************
// * Definition of the function: *array      						    *
// * This function takes as it's arguements, the size of the array.  It *
// * then dynamically creates an array, initializes the array, and then *
// * returns a pointer to that array.								    *
// **********************************************************************

int *array(int amount)
{
	int *arrayptr;

	arrayptr = new int[amount];
	for(int count = 0; count < amount; count++) // Initializes the array
	{
		*(arrayptr + count) = 0;
	}
return arrayptr;
}

// **********************************************************************
// * Definition of the function: getscores							    *
// * This function takes as it's arguements, a pointer to an array, and *
// * the size of the array.  It then prompts the user to populate the   *
// * array.     													    *
// **********************************************************************

void getscores(int *arrayptr, int amount)
{
	int count;
	
	cout << endl;
	
	for (count = 0; count < amount; count++) // Used to enter tests scores
	{
		cout << "Enter test score # " << count + 1 << " : ";
		cin >> *(arrayptr + count);

		while (*(arrayptr + count) < 0) // Confirms value entered is at least 0
		{
			cout << "\nThe score must at least zero\n";
			cout << "Enter test score # " << count + 1 << " : ";
			cin >> *(arrayptr + count);
		}
	}
}

// **********************************************************************
// * Definition of the function: sortarray							    *
// * This function takes as it's arguements, a pointer to an array, and *
// * the size of the array.  It then sorts the array using a selection  *
// * sort.															    *
// **********************************************************************

void sortarray(int* arrayptr, int amount)
{
	int startScan, minIndex;
	int minElem;

	for (startScan = 0; startScan < (amount - 1); startScan++)
	{
		minIndex = startScan;
		minElem = *(arrayptr + startScan);
		
		for (int index = startScan + 1; index < amount; index++)
		{
			if (*(arrayptr + index) < minElem)
			{
				minElem = *(arrayptr + index);
				minIndex = index;
			}
		}

		*(arrayptr + minIndex) = *(arrayptr + startScan);
		*(arrayptr + startScan) = minElem;
	}
}

// **********************************************************************
// * Definition of the function: avg    							    *
// * This function takes as it's arguements, a pointer to an array, and *
// * the size of the array, and a reference variable for the average.   *  
// * It calculates the average of the array.						    *
// **********************************************************************

void avg(int* arrayptr, int amount, double &average)
{
	int count;
	double sum = 0;

	for (count = 0; count < amount; count++) // Sums the values of the array
	{
		sum = sum + *(arrayptr + count);
	}

	average = sum / amount;
}

// **********************************************************************
// * Definition of the function: print								    *
// * This function takes as it's arguements, a pointer to an array, and *
// * the size of the array, and the array's average.  It then displays  *
// * the average of the array.										    *
// **********************************************************************

void print(int *arrayptr, int amount, double average)
{
	int count;

	cout << "\n*** Here are the Results ***\n\n";
	cout << "The average of the following array:\n\n{";
		
	for (count = 0; count < amount; count++) // Displays the the original array
	{
		cout << *(arrayptr + count);

		if (count == amount - 1)
		{
			cout << "}";
		}
		else
		{
			cout << ",";
		}
	}

	cout << setprecision(2) << fixed << "\n\nis: " << average << ".\n";
}


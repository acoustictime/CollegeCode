// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-11-06															*
// *																	*
// * This program takes as it's input, 20 numbers, and sorts them using	*
// * the bubble sort and selection sort methods.  It then displays		*
// * how many swaps it took each type of sort to accomplish it's goal.	*
// **********************************************************************


#include <iostream>

using namespace std;

const int size = 20;

void input(int barray[], int sarray[]);
void bsort(int barray[], int& bcount);
void ssort(int sarray[], int& scount);

int main()
{
	
	int barray[size];
	int sarray[size];

	int bcount = 0;
	int scount = 0;
	
	input(barray, sarray);
	bsort(barray, bcount);
	ssort(sarray, scount);

	cout << endl;
	cout << "The Bubble Sort took " << bcount << " swaps" << endl;
	cout << "The Selection Sort took " << scount << " swaps" << endl;
	
return 0;
}

// *********************************************************************
// * Definition of the function: input  							   *
// * This function takes as it's arguements, the bubble and selection  *
// * sort arrays.  It then prompts the user for 20 numbers to populate *
// * both of the arrays.                                               *
// *********************************************************************

void input(int barray[], int sarray[])
{
	int count;
	int num = 0;

	cout << "Enter 20 intergers seperated by spaces" << endl;

	for (count = 0; count < size; count++)
	{
		cin >> num;
		barray[count] = num;
		sarray[count] = num;
	}
}

// **********************************************************************
// * Definition of the function: bsort  							    *
// * This function takes as it's arguements, the bubble sort array,     *
// * and the count value.  It then sorts the array using the bubble     *
// * sort method.  It counts the amount of swaps that occur and returns *
// * that value.													    *
// **********************************************************************

void bsort(int barray[], int& bcount)
{
	bool swap;
	int temp;

	do
	{
		swap = false;

		for (int count = 0; count < (size - 1); count++)
		{
			if (barray[count] > barray[count + 1])
			{
				temp = barray[count];
				barray[count] = barray[count + 1];
				barray[count + 1] = temp;
				swap = true;
				bcount++;
			}
		}
	} while (swap); 
}

// **********************************************************************
// * Definition of the function: ssort  							    *
// * This function takes as it's arguements, the selection sort array,  *
// * and the count value.  It then sorts the array using the selection  *
// * sort method.  It counts the amount of swaps that occur and returns *
// * that value.													    *
// **********************************************************************

void ssort(int sarray[], int& scount)
{
	int startScan, minIndex, minValue;

	for(startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = sarray[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (sarray[index] < minValue)
			{
				minValue = sarray[index];
				minIndex = index;	
			}
		}

		sarray[minIndex] = sarray[startScan];
		sarray[startScan] = minValue;
		scount++;
	} 
}
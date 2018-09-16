#include <iostream>

using namespace std;

void selectionSort(int list[],  int length);

int main()
{
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};  //Line 1
    int i;                                                //Line 2

    selectionSort(list, 10);                              //Line 3

    cout << "After sorting, the list elements are:" 
		 << endl;                                         //Line 4

    for (i = 0; i < 10; i++)                              //Line 5
        cout << list[i] << " ";                           //Line 6

    cout << endl;                                         //Line 7

    return 0;                                             //Line 8
}


void selectionSort(int list[],  int length)
{
    int index;
	int smallestIndex;
	int minIndex;
	int temp;

	for (index = 0; index < length - 1; index++)
    {
			//Step a
		smallestIndex = index; 

		for (minIndex = index + 1; minIndex < length; minIndex++)
			if (list[minIndex] < list[smallestIndex])
				smallestIndex = minIndex; 

			//Step b
  		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
    }
}



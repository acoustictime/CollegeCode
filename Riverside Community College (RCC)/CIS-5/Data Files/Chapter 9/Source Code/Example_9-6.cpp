//Arrays as parameters to functions

#include <iostream>

using namespace std;

const int arraySize = 10;

void initializeArray(int x[],int sizeX);
void fillArray(int x[],int sizeX);
void printArray(const int x[],int sizeX);
int sumArray(const int x[],int sizeX);
int indexLargestElement(const int x[],int sizeX);
void copyArray(const int x[], int y[], int length);


int main()
{
	int listA[arraySize] = {0};							//Line 1
	int listB[arraySize];								//Line 2

	cout << "Line 1: listA elements: ";					//Line 3
	printArray(listA,arraySize);						//Line 4
	cout << endl;											//Line 5

	initializeArray(listB,arraySize);					//Line 6

	cout << "Line 7: ListB elements: ";					//Line 7
	printArray(listB,arraySize);						//Line 8
	cout << endl << endl;									//Line 9

	cout << "Line 10: Enter " << arraySize
		 << " integers: ";								//Line 10
	fillArray(listA, arraySize);						//Line 11
	cout << endl;											//Line 12

	cout << "Line 13: After filling listA elements are:"
		 << endl;											//Line 13
	printArray(listA,arraySize);							//Line 14
	cout << endl << endl;									//Line 15

	cout << "Line 16: Sum of the elements of listA is: "
		 << sumArray(listA,arraySize) << endl << endl;		//Line 16
	cout << "Line 17: Position of the largest element in listA is: "
		 << indexLargestElement(listA,arraySize)
		 << endl;											//Line 17
	cout << "Line 18: Largest element in listA is: "
		 << listA[indexLargestElement(listA,arraySize)]
		 << endl << endl;									//Line 18

	copyArray(listA, listB, arraySize);						//Line 19
	cout << "Line 20: After copying the elements of "
		 << "listA into listB" << endl
		 << "         listB elements are: ";				//Line 20
	printArray(listB,arraySize);							//Line 21
	cout << endl;											//Line 22

	return 0;
}

    //Function to initialize an array to 0
void initializeArray(int list[], int listSize)
{
    int counter;

    for (counter = 0; counter < listSize; counter++)
        list[counter] = 0;
}

    //Function to read data and store in an array
void fillArray(int list[], int listSize)
{
    int counter;

    for (counter = 0; counter < listSize; counter++)
        cin >> list[counter];
}

    //Function to print the array
void printArray(const int list[], int listSize)
{
    int counter;

    for (counter = 0; counter < listSize; counter++)
        cout << list[counter] << " ";
}

    //Function to find and return the sum of an array 
int sumArray(const int list[], int listSize)
{
    int counter;
    int sum = 0;

    for (counter = 0; counter < listSize; counter++)
        sum = sum + list[counter];

    return sum;
}

    //Function to find and return the index of the 
    //largest element of an array 
int indexLargestElement(const int list[], int listSize)
{
    int counter;
    int maxIndex = 0; //Assume first element is the largest

    for (counter = 1; counter < listSize; counter++)
        if (list[maxIndex] < list[counter])
            maxIndex = counter;

    return maxIndex;
}

    //Function to copy one array into another array
    //The array listB must be at least as large as the array listA.
void copyArray(const int listA[], int listB[], int listASize)
{
    int counter;

    for (counter = 0; counter < listASize; counter++)
        listB[counter] = listA[counter];
}

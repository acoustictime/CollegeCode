//Arrays as parameters to functions

#include <iostream>

using namespace std;

const int arraySize = 10;

	//function prototypes
void initializeArray(int list[], int listSize);
void fillArray(int list[], int listSize);
void printArray(const int list[], int listSize);
int sumArray(const int list[], int listSize);
int indexLargestElement(const int list[], int listSize);
void copyArray(const int listOne[], int listTwo[],
			   int listOneSize);

int main()
{
    int listA[arraySize] = {0};  //declare the array listA 
                                 //of 10 components and 
                                 //initialize each component 
                                 //to 0;	
    int listB[arraySize];        //declare the array listB 
                                 //of 10 components;   

    cout << "Line 1: listA elements: ";             //Line 1

        //output the elements of listA using
        //the function printArray
    printArray(listA, arraySize);                   //Line 2
    cout << endl;                                   //Line 3

        //initialize listB using the function initialize
    initializeArray(listB, arraySize);              //Line 6

    cout << "Line 7: listB elements: ";             //Line 7

        //output the elements of listB
    printArray(listB, arraySize);                   //Line 8
    cout << endl << endl;                           //Line 9

    cout << "Line 10: Enter " << arraySize
         << " integers: ";                          //Line 10

        //input data into listA using the function fillArray
    fillArray(listA, arraySize);                    //Line 11
    cout << endl;                                   //Line 12

    cout << "Line 13: After filling listA, " 
         << "the elements are:" << endl;            //Line 13

        //output the elements of listA
    printArray(listA, arraySize);                   //Line 14
    cout << endl << endl;                           //Line 15

        //find and output the sum of the elements of listA
    cout << "Line 16: The sum of the elements of listA is: "
         << sumArray(listA, arraySize) << endl 
         << endl;                                   //Line 16

        //find and output the position of the largest
        //element in listA
    cout << "Line 17: The position of the largest element " 
         << "in listA is: "
         << indexLargestElement(listA, arraySize)
         << endl;                                   //Line 17

        //find and output the largest element in listA
    cout << "Line 18: The largest element in listA is: "
         << listA[indexLargestElement(listA, arraySize)]
         << endl << endl;                           //Line 18

        //copy the elements of listA into listB using the
        //function copyArray
    copyArray(listA, listB, arraySize);             //Line 19

    cout << "Line 20: After copying the elements of "
         << "listA into listB" << endl
         << "         listB elements are: ";        //Line 20

        //output the elements of listB    
    printArray(listB, arraySize);                   //Line 21
        cout << endl;                               //Line 22

    return 0;
}

    //Function to initialize an int array to 0.
    //The array to be initialized and its size are 
    //passed as parameters. The parameter listSize
    //specifies the number of elements to be initialized.
void initializeArray(int list[], int listSize)
{
    int index;

    for (index = 0; index < listSize; index++)
        list[index] = 0;
}

    //Function to read and store the data into an int array.
    //The array to store the data and its size are passed as 
    //parameters. The parameter listSize specifies the number
    //of elements to be read.
void fillArray(int list[], int listSize)
{
    int index;

    for (index = 0; index < listSize; index++)
        cin >> list[index];
}

    //Function to print the elements of an int array.
    //The array to be printed and the number of elements 
    //are passed as parameters. The parameter listSize
    //specifies the number of elements to be printed.
void printArray(const int list[], int listSize)
{
    int index;

    for (index = 0; index < listSize; index++)
        cout << list[index] << " ";
}

    //Function to find and return the sum of the
    //elements of an int array. The parameter listSize
    //specifies the number of elements to be added.
int sumArray(const int list[], int listSize)
{
    int index;
    int sum = 0;

    for (index = 0; index < listSize; index++)
        sum = sum + list[index];

    return sum;
}

    //Function to find and return the index of the first
    //largest element in an int array. The parameter listSize
    //specifies the number of elements in the array.
int indexLargestElement(const int list[], int listSize)
{
    int index;
    int maxIndex = 0; //Assume the first element is the largest

    for (index = 1; index < listSize; index++)
        if (list[maxIndex] < list[index])
            maxIndex = index;

    return maxIndex;
}

    //Function to copy one array into another array.
    //The elements of listOne are copied into listTwo.
    //The array listTwo must be at least as large as the 
    //number of elements to be copied. The parameter 
    //listOneSize specifies the number of elements of 
    //listOne to be copied into listTwo.
void copyArray(const int listOne[], int listTwo[],
			   int listOneSize)
{
    int index;

    for (index = 0; index < listOneSize; index++)
        listTwo[index] = listOne[index];
}


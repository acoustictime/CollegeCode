#include <iostream> 
#include <iomanip>

using namespace std;

const int numberOfRows = 6;
const int numberOfColumns = 5;

void printMatrix(int matrix[][numberOfColumns], int noOfRows);
void sumRows(int matrix[][numberOfColumns], int noOfRows);
void largestInRows(int matrix[][numberOfColumns], int noOfRows);

int main()
{
    int board[numberOfRows][numberOfColumns] 
                    = {{23, 5, 6, 15, 18},
                       {4, 16, 24, 67, 10},
                       {12, 54, 23, 76, 11},
                       {1, 12, 34, 22, 8},
                       {81, 54, 32, 67, 33},
                       {12, 34, 76, 78, 9}};   //Line 1

    printMatrix(board, numberOfRows);          //Line 2
    cout << endl;                              //Line 3
    sumRows(board, numberOfRows);              //Line 4
    cout << endl;                              //Line 5
    largestInRows(board, numberOfRows);        //Line 6

    return 0;
}

void printMatrix(int matrix[][5], int rowSize)
{
    int row, col;

    for (row = 0; row < rowSize; row++)
    {
        for (col = 0; col < 5; col++)
	      cout << setw(5) << matrix[row][col] << " ";

        cout << endl;
    }
}

void sumRows(int matrix[][5], int rowSize)
{
    int row, col;
    int sum;

         //sum of each individual row
    for (row = 0; row < rowSize; row++)
    {
        sum = 0;

        for (col = 0; col < 5; col++)
            sum = sum + matrix[row][col];

        cout << "Sum of row " << (row + 1) << " = " << sum
			 << endl;
    }
}

void largestInRows(int matrix[][5], int rowSize)
{
    int row, col;
    int largest;

         //Largest element in each row
    for (row = 0; row < rowSize; row++)
    {
       largest = matrix[row][0]; //assume that the first element 
                                 //of the row is the largest
       for (col = 1; col < 5; col++)
           if (largest < matrix[row][col])
              largest = matrix[row][col];

       cout << "The largest element of row " << (row + 1) 
            << " = " << largest << endl;
    }
}

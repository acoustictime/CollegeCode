// Program: AVG1
#include <iostream>
using namespace std;

int main()
{
	int limit;		//variable to store the number of items 
					//in the list 
	int number;		//variable to store the number  
	int sum;		//variable to store the sum
	int counter;	//loop control variable


	cout << "Line 1: Enter data for processing"
		 << endl;									//Line 1
	cin >> limit;									//Line 2

	sum = 0;										//Line 3
	counter = 0;									//Line 4

	while (counter < limit)							//Line 5
	{
		cin >> number;  							//Line 6
		sum = sum + number;							//Line 7
		counter++;  								//Line 8
	}

	cout << "Line 9: The sum of the " << limit
		 << " numbers = " << sum << endl;			//Line 9

	if (counter != 0)								//Line 10
		cout << "Line 11: The average = "
			 << sum / counter << endl;				//Line 11
	else											//Line 12
		cout << "Line 13: No input." << endl;		//Line 13

	return 0;
}

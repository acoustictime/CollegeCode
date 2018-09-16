//Program:  AVG2 
#include <iostream>
using namespace std;

const int SENTINEL = -999;

int main()
{
	int number; 	//variable to store the number  
	int sum = 0;  	//variable to store the sum
	int count = 0; 	//variable to store the total 
					//numbers read

	cout << "Line 1: Enter numbers ending with "
		 << SENTINEL << endl;						//Line 1
	cin >> number;									//Line 2

	while (number != SENTINEL)						//Line 3
	{
		sum = sum + number; 						//Line 4
		count++;    								//Line 5
		cin >> number;   							//Line 6
	}

	cout << "Line 7: The sum of the " << count
		 << " numbers is " << sum << endl;			//Line 7

	if (count != 0)									//Line 8
		cout << "Line 9: The average is "
			 <<  sum / count << endl;				//Line 9
	else											//Line 10
		cout << "Line 11: No input." << endl;		//Line 11
	
	return 0;
 }

// James Small

// Ch4_Ex2_Small

// 3-18-06

//  This program prompts for three numbers and outputs
//  them in ascending order.

#include <iostream>

using namespace std;

int main()
{
	double num1, num2, num3;
	double lowest, middle, highest;

	cout << "Enter three numbers: "; 
	cin >> num1 >> num2 >> num3;
	cout << endl;

	if (num1 >= num2 && num1 >= num3)
	{
	    highest = num1;
	    
		if (num2 >= num3)
		{
			middle = num2;
			lowest = num3;
		}

		else
		{
			middle = num3;
			lowest = num2;
		}
	}
	else if (num2 >= num1 && num2 >= num3)
	{
	    highest = num2;
	    
		if (num1 >= num3)
		{
			middle = num1;
			lowest = num3;
		}

		else
		{
			middle = num3;
			lowest = num1;
		}
	}
	else if (num3 >= num2 && num3 >= num1)
	{
	    highest = num3;
	    
		if (num2 >= num1)
		{
			middle = num2;
			lowest = num1;
		}

		else
		{
			middle = num1;
			lowest = num2;
		}
	}
	
	cout << "The numbers in ascending order are: " << lowest << " " << middle << " " << highest << endl;


   return 0;
}

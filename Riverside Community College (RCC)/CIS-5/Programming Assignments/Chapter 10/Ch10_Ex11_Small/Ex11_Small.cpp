// James Small

// Ex11_Small

// 5-22-06

// This program prompts the user to enter up to 100 positive intergers
// and then counts how many times each number appears.  It then outputs
// the numbers in ascending order along with the totals.


#include <iostream>
#include <iomanip>

using namespace std;

const int length = 100; 

void initialize(int numbers[], int totals[][2], int length);
void input(int numbers[], int length);
void print(int numbers[], int totals[][2], int length, int current);
void sort(int numbers[], int length);
void count(int numbers[], int totals[][2], int length, int& current);

int main()
{

int current = 0;
int numbers[length];
int totals[length][2];

initialize(numbers, totals, length);
input(numbers, length);
sort(numbers, length); 
count(numbers, totals, length, current);
print(numbers, totals, length, current);

return 0;
}

void input(int numbers[], int length)
{

	int num;
	int count = 0;
	
	cout << "Enter a maximum of 100 positive integers ending with -999" << endl;

	cin >> num;

	while (num != -999 || count > length)
	{
		numbers[count] = num;
		cin >> num;
		count++;
	}
}

void initialize(int numbers[], int totals[][2], int length)
{
	int count;
	int count2;

	for (count = 0; count < length; count++)
	{
		numbers[count] = -999;
	}

 	for (count = 0; count < 2; count++)
	{
		for (count2 = 0; count2 < length; count2++)
		{
			totals[count2][count] = -999;
		}
	} 
}

void print(int numbers[], int totals[][2], int length, int current)
{
	int count;	
	
	cout << " Number  Count" << endl;
	for (count = 0; count < current; count++)
	{
		cout << right << setw(5) << totals[count][0];
		cout << right << setw(8) << totals[count][1] << endl;
	}
}

void sort(int numbers[], int length)
{
	int count;
	int smallest;
	int min;
	int temp;

	for (count = 0; count < length -1; count++)
	{
		smallest = count;

		for (min = count + 1; min < length; min++)
		{
			if (numbers[min] < numbers[smallest])
			{
				smallest = min;
			}
		}

		temp = numbers[smallest];
		numbers[smallest] = numbers[count];
		numbers[count] = temp;
	}
}

void count(int numbers[], int totals[][2], int length, int& current)
{
	int num;
	int count = 0;	
	
	for (count = 0; count < length; count++)
	{
		num = numbers[count];
		
		if (num == -999)
		{
			continue;
		}

		if (totals[current][0] == -999)
		{
			totals[current][0] = num;
		}
		
		if (totals[current][1] == -999)
		{
			totals[current][1] = 0;
		}
		
		totals[current][1] = totals[current][1] + 1;

		if (num == numbers[count + 1])
		{
			continue;
		}
		
		current++;
	}
}
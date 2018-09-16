// James Small

// Ch9_Ex4_Small

// 5-10-06

// This program calculates the score from a gymnastics or swimming 
// competition.  It prompts to user to input the scores and then
// outputs the final score.  The final score is calculated by 
// taking the total score minus the lowest and highest scores.

#include <iostream>
#include <iomanip>

using namespace std;

const int arraysize = 8;

void initialize(double scores[], int arraysize);
void inputarray(double scores[], int arraysize);
void calcscore(double scores[], int arraysize, double& finalscore);

int main()
{
	double scores[arraysize];
	int max = 0;
	double finalscore;
	initialize(scores, arraysize);
	inputarray(scores, arraysize);
	calcscore(scores, arraysize, finalscore);

	cout << fixed << showpoint << setprecision(2);
	cout << "Total Points = "  << finalscore;
	cout << endl;

return 0;
}

void initialize(double scores[], int arraysize)
{
	int index;

	for (index = 0; index < arraysize; index++)
	{		
		scores[index] = 0;
	}
}

void inputarray(double scores[], int arraysize)
{
	cout << "Input Date: ";
	int count;
	for (count = 0; count < arraysize; count++)
	{
		cin >> scores[count];
	}
	
	cout << endl;
}

void calcscore(double scores[], int arrayszie, double& finalscore)
{
	int maxindex = 0;
	int minindex = 0;
	double sum = 0;
	int count;

	for (count = 1; count < arraysize; count++)
	{
		if (scores[maxindex] < scores[count])
		{
			maxindex = count;
		}
	}

	for (count = 1; count < arraysize; count++)
	{
		if (scores[minindex] > scores[count])
		{
			minindex = count;
		}
	}

	for (count = 0; count < arraysize; count++)
	{
		sum = sum + scores[count];
	}

	finalscore = sum - scores[maxindex] - scores[minindex];
}

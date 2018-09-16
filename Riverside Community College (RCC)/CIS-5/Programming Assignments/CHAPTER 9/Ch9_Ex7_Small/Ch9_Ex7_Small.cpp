// James Small

// Ch9_Ex7_Small

// 5-15-06

// This program prompts the user to enter the names on amount
// votes received by five candidates.  It will then output
// the percentage of votes each candidate received and then
// will output the winner along with the total votes.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int rows = 5;
void initializearray(string name[], int votes[], int rows);
void inputarray(string name[], int votes[], int rows);
void calculate(int votes[], int rows, int& winner, double& total);
void printarray(string name[], int votes[], int rows, int winner, double total);

int main()
{
	string name[rows];
	int votes[rows];
	int winner = 0;
	double total = 0;

	initializearray(name, votes, rows);
	inputarray(name, votes, rows);
	calculate(votes, rows, winner, total);
	printarray(name, votes, rows, winner, total);

	return 0;
}

void initializearray(string name[], int votes[], int rows)
{
	int count;

	for (count = 0; count < rows; count++)
	{
		name[count] = "";
		votes[count] = 0;
	}
}

void inputarray(string name[], int votes[], int rows)
{
	int count;
	string names;
	int vote;

	cout << "Enter candidate's name and the votes received by the candidate" << endl;

	for (count = 0; count < rows; count++)
	{
		cin >> names;
		name[count] = names;
		
		cin >> vote;
		votes[count] = vote;

	}
}

void calculate(int votes[], int rows, int& winner, double& total)
{
	int count;
	

	for (count = 0; count < rows; count++)
	{
		total = total + votes[count];
	}
	
	for (count = 1; count < rows; count++)
	{
		if (votes[winner] < votes[count])
		{
			winner = count;
		}
	}
}

void printarray(string name[], int votes[], int rows, int winner, double total)
{
	int count;
	

	cout << endl;
	cout << "Candidate     Votes Received    # of Total Votes" << endl;

	for (count = 0; count < rows; count++)
	{
		cout << fixed << showpoint << setprecision(2);
		
		cout << left << setw(10)<< name[count];
		cout << right << setw(12) << votes[count];
		cout << right << setw(16) << (votes[count] / total) * 100;
		cout << endl;
	}
	
	cout << endl << "Total Votes: " << total;
	cout << endl << "Winner: " << name[winner] << endl;
	cout << endl;
		
}






// James Small

// Ch11_Ex1_Small

// 5-26-06

// This program reads from an input file a students name and their corresponding test score.
// It stores these values in a struct with the students name, score, and letter grade.  It 
// outputs these names, scores, and grades followed by the highest testscore and the students
// who received that test score.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int noofstudents = 20;

struct studenttype
{
	string fname;
	string lname;
	int testscore;
	char grade;
};

void initialize(studenttype students[], int noofstudents);
void input(ifstream& infile, studenttype students[], int noofstudents);
void grade(ifstream& infile, studenttype students[], int noofstudents);
void highest(studenttype students[], int noofstudents, int& highscore);
void print(ofstream& outfile, studenttype students[], int noofstudents, int highscore);

int main()
{

int highscore = 0;
ifstream infile;
ofstream outfile;

infile.open("Ch11_Ex1Data.txt");

if (!infile)
{
	cout << "Cannont open the input file." << endl;
return 1;
}

outfile.open("Ch11_Ex1Out.txt");
	
studenttype students[noofstudents];
initialize(students, noofstudents);
input(infile, students, noofstudents);
grade(infile, students, noofstudents);
highest(students, noofstudents, highscore);
print(outfile, students, noofstudents, highscore);

infile.close();
outfile.close();

cout << "File: Ch11_Ex1out.txt  Created" << endl;

return 0;
}

void initialize(studenttype students[], int noofstudents)
{
	int count;

	for (count = 0; count < noofstudents; count++)
	{
		students[count].fname = " ";
		students[count].lname = " ";
		students[count].testscore = 0;
		students[count].grade = ' ';
	}
}

void print(ofstream& outfile, studenttype students[], int noofstudents, int highscore)
{
	int count;
	string fullname;

	outfile << "Student Name           Test Score  Grade" << endl << endl;
		
	for (count = 0; count < noofstudents; count++)
	{
		fullname = students[count].lname + ", " + students[count].fname;
		
		outfile << left << setw(29) << fullname;
		outfile << left << setw(6) << students[count].testscore;
		outfile << left << setw(4) << students[count].grade << endl;
	}

	outfile << endl;
	outfile << "Highest Test Score: " << highscore << endl << endl;
	outfile << "Students having the highest test score:" << endl << endl;

	for (count = 0; count < noofstudents; count++)
	{
		if (students[count].testscore == highscore)
		{
			outfile << students[count].lname << ", " << students[count].fname << endl;
		}
	}
}

void input(ifstream& infile, studenttype students[], int noofstudents)
{
	int count;
	string first;
	string last;
	int score;

	for (count = 0; count < noofstudents; count++)
	{
		infile >> first >> last >> score;

		students[count].fname = first;
		students[count].lname = last;
		students[count].testscore = score;
	}
}
		
void grade(ifstream& infile, studenttype students[], int noofstudents)
{
	int count;
	int score = 0;

	for (count = 0; count < noofstudents; count++)
	{
		score = students[count].testscore;

		if (score >= 90)
			students[count].grade = 'A';
		else if (score >= 80)
			students[count].grade = 'B';
		else if (score >= 70)
			students[count].grade = 'C';
		else if (score >= 60)
			students[count].grade = 'D';
		else
			students[count].grade = 'F';
	}
}

void highest(studenttype students[], int noofstudents, int& highscore)
{
	int count;
	int high = 0;

	for (count = 1; count < noofstudents; count ++)
	{
		if (students[high].testscore < students[count].testscore)
		{
			high = count;
		}
	}
	
	highscore = students[high].testscore;
}


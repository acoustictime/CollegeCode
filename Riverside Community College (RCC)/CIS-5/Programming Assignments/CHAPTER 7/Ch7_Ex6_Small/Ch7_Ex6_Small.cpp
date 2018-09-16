// James Small

// 4-14-06

// Ch7_Ex6_Small

// This program calculates the average of five tests per student and also calculates
// their grade after the five tests.  It also gives a class average of all the tests.
// It uses multiple functions to accomplish this. 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void calculateAverage(ifstream& inp, ofstream& outp, double& avgtest, string name);
char calculateGrade(double avgtest);

int main()
{
	
	string name;
	double testavg;
	double classavg = 0;
	int classcount = 0;

	ifstream infile;
	ofstream outfile;

	infile.open("scores.txt");

	if (!infile)
	{
		cout << "Unable to open the file." << endl;
		return 1;
	}


	outfile.open("grades.txt");
	outfile << fixed << showpoint << setprecision(2);
	outfile << "Student   Test1   Test2   Test3   Test4   Test5   Average   Grade" << endl;
	
	infile >> name;

	while (infile)
	{	
		calculateAverage(infile, outfile, testavg, name);
		
		outfile << left << setw(10) << testavg;
		outfile << calculateGrade(testavg);
		outfile << endl;

		classavg = classavg + testavg;
		classcount++;
		
		infile >> name;
	}
	
	outfile << endl;
	outfile << "Class Average = " << (classavg / classcount) << endl;
	
	infile.close();
	outfile.close();
	
return 0;
}

void calculateAverage(ifstream& inp, ofstream& outp, double& avgtest, string name)
{
	int testcount = 0;
	int score;
	int i;
	int amountoftests = 5;
	int testtotal = 0;	
	
	outp << left << setw(12) << name;

	for (i = 0; i < amountoftests; i++)
	{
		inp >> score;

		testtotal = testtotal + score;
		testcount++;
	
		outp << left << setw(8) << score;
		
	}

	avgtest = testtotal / testcount;

}

char calculateGrade(double avgtest)
{
	static_cast<int>(avgtest);

	if (avgtest >= 90)
		return 'A';
	else if (avgtest >= 80)
		return 'B';
	else if (avgtest >= 70)
		return 'C';
	else if (avgtest >= 60)
		return 'D';
	else
		return 'F';
}
	

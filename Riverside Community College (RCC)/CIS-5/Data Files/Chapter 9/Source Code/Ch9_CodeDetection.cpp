//Program: Check Code
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int maxCodeSize = 250;

void readCode(ifstream& infile, int list[], 
			  int& length, bool& lenCodeOk);
void compareCode(ifstream& infile, ofstream& outfile,
				 int list[], int length);

int main()
{
			//Step 1
	int codeArray[maxCodeSize];	//array to store the secret code
	int	codeLength;  			//variable to store the length 
								//of the secret code
	bool lengthCodeOk;	//variable to indicate if the length of the
						//secret code is less than or equal to 250
	ifstream incode;   	//input file stream variable
	ofstream outcode;  	//output file stream variable
	char inputfile[25];		//variable to store the name of the 
							//input file
	char outputfile[25];	//variable to store the name of the 
							//output file

	cout << "Enter the input file name: ";
	cin >> inputfile;
	cout << endl;
				//Step 2
	incode.open(inputfile);
	if (!incode)
	{
		cout << "Cannot open the input file." << endl;
		return 1;
	}

	cout << "Enter the output file name: ";
	cin >> outputfile;
	cout << endl;

	outcode.open(outputfile);
  
	readCode(incode, codeArray, codeLength, lengthCodeOk);	//Step 3

	if (lengthCodeOk) 										//Step 4
		compareCode(incode, outcode, codeArray, codeLength);  
	else
		cout << "Length of the secret code must be <= "
			 << maxCodeSize << endl;							//Step 5

	incode.close();
	outcode.close();

	return 0;
}

void readCode(ifstream& infile, int list[], int& length, 
			  bool& lenCodeOk)
{
	int count;

	lenCodeOk = true;
	
	infile >> length;  // get the length of the secret code
	if (length > maxCodeSize)
	{
		lenCodeOk = false;
		return;
	}

	for (count = 0; count < length; count++) // get the secret code
		infile >> list[count];
}

void compareCode(ifstream& infile, ofstream& outfile,
				 int list[], int length)
{
	int length2;
	int digit;
	bool codeOk;
	int count;

	codeOk = true;

	infile >> length2; 

	if (length != length2) 
	{
		cout << "The original code and its copy are not of"
 			 << " the same length." << endl;
     	return;
	}

	outfile << "Code Digit    Code Digit Copy" << endl;
	for (count = 0; count < length; count++)
	{
		infile >> digit;
		outfile << setw(7) << list[count] << setw(20) << digit;
		if (digit != list[count])  
		{
			outfile << "          code digit not the same" << endl;
			codeOk = false;
		}
		else
			outfile << endl;
	}

	if (codeOk)
		outfile << "Message transmitted OK." << endl;
	else
		outfile << "Error in transmission. Retransmit!!" << endl;
}

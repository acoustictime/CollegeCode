// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 10-29-06															*
// *																	*
// * This program reads in characters from a file, and outputs the      *
// * decrypted form of the letter to another file.  It essentially reads*
// * in the file and outputs the decrypted version of the file.         *
// **********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char temp; // Temp char used when reading in file
	
	fstream infile, outfile; // Defines input and output files

	cout << "*** Decryption Program ***\n\n";

	infile.open("8-input.txt", ios::in); // Opens input file

	if (infile.fail()) // Checks for existance of input file and exits program if there is no file
	{
		cout << "Error: Cannot open file for input.\n\n";
		return 0;
	}

	outfile.open("8-output.txt", ios::out); // Opens output file

	while (!infile.eof()) // Loops until the end of the file
	{
		infile.get(temp); // Reads in character into temp variable
		outfile.put(temp - 6); // Outputs the temp variable minus 6
	}

	cout << "File Decryption is Done.\n\n";

return 0;
}
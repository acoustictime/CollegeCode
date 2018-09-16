// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-28-06															*
// *																	*
// * This program takes as it's input, a string of up to 100 characters * 
// * and counts up the amount of words and the average number of letters*
// * per word.															*
// **********************************************************************




#include <iostream>
#include <iomanip>

using namespace std;


void counter(char *strptr, int& words, int& letters);


int main()
{
	const int size = 100;
	int words = 0, letters = 0;

	char userstring[size];

	cout << "Enter a string (up to 100 characters): ";
	cin.getline(userstring, size);

	counter(userstring, words, letters);
	
	cout << "There are " << words << " words";
	cout << setprecision(2) << "\nThe average number of letters is " << static_cast<double>(letters) / static_cast<double>(words);
	cout << endl;
	
return 0;
}

// **********************************************************************
// * Definition of the function: choices							    *
// * This function takes as it's arguements, a pointer to array of chars*
// * a reference parameter for the amount of words, and a reference     *
// * parameter for the amount of letters.							    *
// **********************************************************************

void counter(char *strptr, int& words, int& letters)
{
	bool space = false; // Used to determine if string has multiple spaces next to each other
	
	while (*strptr != '\0') // Loop used to determine the end of the string
	{
		if (*strptr == ' ') // Loop used to determine if the char is a space
		{
			if (space == true) // Used when there is multipe spaces in a row
			{
				space = false;
				strptr++;
			}
			else
			{
				strptr++;
			}
		}
		else
		{
			if (space == false) // Enters loop if beginning of new word
			{
				words++;
				space = true;
				letters++;
				strptr++;
			}
			else
			{
				letters++;
				strptr++;
			}
		}
	}
}

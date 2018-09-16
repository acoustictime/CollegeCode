// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 10-1-06															*
// *																	*
// * This program takes as it's input, a string of characters of up to  *
// * 100 characters.  It then displays a menu asking you if you want to *
// * count the amount of vowels, the amount of consonants, both vowels  *
// * and consonants, or enter a new string.								*
// **********************************************************************

#include <iostream>
#include <cctype>

using namespace std;

const int size = 100;

void menu();
void input(char *strptr);
int isvowel(char *strptr);
int isconsonant(char *strptr);

int main()
{	
		
	char menuchoice;
	int vowels = 0;
	int consonants = 0;
	char *strptr;

	strptr = new char[size];
	
	input(strptr);
	
	while (tolower(menuchoice) != 'e') // Loop changes menuchoice to lowercase and loops until the user enters an 'e'
	{
		menu();
		cin >> menuchoice; // Get menu choice input
		
		cin.ignore(100, '\n'); // Ignores the next 100 characters, or until the newline character appears

		switch (tolower(menuchoice)) // Switch lowers case of menuchoice and uses it to determine choice
		{
			case 'a':
			{	
				cout << "\nThere are " << isvowel(strptr) << " vowels in this string.\n";
				break;
			}
			case 'b':
			{
				cout << "\nThere are " << isconsonant(strptr) << " consonants in this string.\n";
				break;
			}
			case 'c':
			{
				cout << "\nThere are " << isvowel(strptr) << " vowels and " << isconsonant(strptr) << " consonants in this string.\n";
				break;
			}
			case 'd':
			{
				input(strptr); // Grabs user input again
				break;
			}
			case 'e':
			{
				cout << "\n***** Thanks For Playing *****\n\n"; 
				
				break;
			}
			default: cout << "\nInvalid Entry\n";			
		}
	}	

return 0;
}

// **********************************************************************
// * Definition of the function: menu								    *
// * This function displays the menu of choices for the user		    *
// **********************************************************************

void menu()
{
	cout << "\n***** Please Enter Your Choice *****\n\n";
	cout << "A: Count the Number of Vowels in the String\n";
	cout << "B: Count the Number of Consonants in the String\n";
	cout << "C: Count both the Vowels and Consonants in the String\n";
	cout << "D: Enter Another String\n";
	cout << "E: Exit the Program\n\n";
	cout << "Choice: ";
}

// **********************************************************************
// * Definition of the function: input								    *
// * This function takes as it's arguements, a pointer to a string of   *
// * characters.  It then asks the user to enter a string up to 100     *
// * characters.													    *
// **********************************************************************

void input(char *strptr)
{
	cout << "Enter a string (up to 100 characters): ";
	cin.getline(strptr, size);
}
				
// **********************************************************************
// * Definition of the function: isvowel							    *
// * This function takes as it's arguements, a pointer to a string of   *
// * characters.  It then returns the amount of vowels in the string.   *
// **********************************************************************

int isvowel(char *strptr)
{
	int vowels = 0;	
	
	while (*strptr != '\0') // Loops through the characts until it reaches the end of the string
	{
				
		if (isalpha(*strptr)) // Loop determines if the character is a letter
		{	
			// Loop determines if the letter is a vowel
			
			if (tolower(*strptr) == 'a' || tolower(*strptr) == 'e' || tolower(*strptr) == 'i' || tolower(*strptr) == 'o' || tolower(*strptr) == 'u')
			{			
				vowels++;
				*strptr++;
			}
			else
			{
				*strptr++;
			}
		}
		else
		{
			*strptr++;
		}
		
		
	}

return vowels;
}	

// **********************************************************************
// * Definition of the function: isconsonant						    *
// * This function takes as it's arguements, a pointer to a string of   *
// * characters.  It then returns the amount of consonants in the string*
// **********************************************************************

int isconsonant(char *strptr)
{
	int consonants = 0;
	
	while (*strptr != '\0')	// Loops through the characts until it reaches the end of the string
	{
		if (isalpha(*strptr)) // Loop determines if the character is a letter
		{		
			// Loop determines if letter is a consonant
			
			if (tolower(*strptr) != 'a' && tolower(*strptr) != 'e' && tolower(*strptr) != 'i' && tolower(*strptr) != 'o' && tolower(*strptr) != 'u' && tolower(*strptr) != ' ')
			{
				consonants++;
				*strptr++;
			}
			else
			{
				*strptr++;
			}
		}
		else
		{
			*strptr++;
		}
	}

return consonants;
}
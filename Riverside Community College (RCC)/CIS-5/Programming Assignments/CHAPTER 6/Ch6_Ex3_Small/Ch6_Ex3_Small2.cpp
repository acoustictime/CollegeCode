// James Small

// 4-8-06

// Ch6_Ex3_Small

// This program prompts the user to enter a sentence.  It then counts the number of vowels that
// are in the sentence.  It uses a funtion to determine if a particular letter is a vowel or not. 

#include <iostream>
#include <string>
#include <istream>

using namespace std;

bool isVowel(char x);

int main()
{

	string input;
	int counter = 0;
	cout << "Input string" << flush;

	
	getline(cin, input);
	cout << endl;

	


	cout << "There are " << counter << " Vowels in the sentence provided." << endl;
	return 0;
}

bool isVowel(char x)
{	
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		return true;
	else
		return false;
}

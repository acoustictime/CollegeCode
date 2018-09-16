#include <iostream>
#include <string>
#include <istream>

using namespace std;

bool isVowel(char x);

int main()
{

	string input = "";
	int counter = 0;
	cout << "Input string" << endl;
	getline(cin, input);
	
	
	for(int i = 0; i < input.size(); i++)
	{
		if (isVowel(static_cast<char>(input[i])))
		{
			counter++;
		}
		
	}

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

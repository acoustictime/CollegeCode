// James Small

// Ch2_Ex9_Small

// 3-4-06

// This program prompts the user to enter five 
// decimal numbers, prints the numbers, converts
// each number to the nearst integer, adds the 
// five intergers and prints the sum and averge 
// of the integers.

#include <iostream>

using namespace std;

int main ()
{

	double dec1, dec2, dec3, dec4, dec5;
	int dec1int, dec2int, dec3int, dec4int, dec5int;
	int sum, average;
	
	cout << "Enter five decimal numbers: ";
	cin >> dec1 >> dec2  >> dec3 >> dec4 >> dec5;
	cout << endl;

	cout << "The numbers you entered are:";
	cout << endl;
	cout << dec1 << " " << dec2 << " " << dec3 << " " << dec4 << " " << dec5 << endl;
	
	dec1int = dec1 + .5;
	dec2int = dec2 + .5;
	dec3int = dec3 + .5;
	dec4int = dec4 + .5;
	dec5int = dec5 + .5;

    sum = dec1int + dec2int + dec3int + dec4int + dec5int;
	average = sum/5;

	cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;
	
	return 0;
}




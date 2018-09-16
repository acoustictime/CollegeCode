// Sequential binary search
// Adapted from Budd
// Kay Zemoudeh
// 2/13/2012

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

unsigned int binarySearch(double v[], unsigned int n, double value)
{
	unsigned int low = 0, high = n;

	while (low < high) {
		unsigned int mid = (low + high) / 2;
		if (v[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}

	return low;
}

main()
{
	string file = "binarySearch.input";
	ifstream in(file.c_str());

	double numbers[100];
	int n = 0; // n is number of numbers
	double item; // search item

	while (in >> numbers[n])
		n++;
	// Here in.eof() and/or in.fail() returned true
	
	sort(numbers, numbers+n); // array must be sorted

	cout << "Enter a number to search for: ";
	cin >> item;
	if (cin.fail()) {
		cout << "Enter a number.\n";
		exit(1);
	}
	
	cout << binarySearch(numbers, n, item) << endl;
}

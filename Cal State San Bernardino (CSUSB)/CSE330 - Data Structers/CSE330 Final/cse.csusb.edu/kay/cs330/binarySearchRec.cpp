// Recursive binary search
// Kay Zemoudeh
// 2/13/2012

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

unsigned int binSearch(double v[], int low, int high, double value)
{
	if (low >= high)
		return low;
	unsigned int mid = (low + high)/2;
	if (value == v[mid])
		return mid;
	if (value < v[mid])
		return binSearch(v, low, mid, value);
	else
		return binSearch(v, mid+1, high, value);
}

unsigned int binarySearch(double v[], unsigned int n, double value)
{
	return binSearch(v, 0, n, value);
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

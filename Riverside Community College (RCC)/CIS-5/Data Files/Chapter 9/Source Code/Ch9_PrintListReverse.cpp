// Program to read five numbers, find their sum, and print the
// numbers in reverse order.

#include <iostream>

using namespace std;

int main()
{
	int  item0, item1, item2, item3, item4;
	int sum;

	cout << "Enter five integers: ";
	cin >> item0 >> item1 >> item2 >> item3 >> item4;
	cout << endl;

	sum = item0 + item1 + item2 + item3 + item4;

	cout << "The sum of the numbers = " << sum << endl;
	cout << "The numbers in the reverse order are: ";
	cout << item4 << " " << item3 << " " << item2 << " "
		 << item1 << " " << item0 << endl;
   return 0;
}

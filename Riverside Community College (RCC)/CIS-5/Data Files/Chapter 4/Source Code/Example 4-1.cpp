
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << fixed << showpoint << setprecision(17);

	cout << "3.0 / 7.0 = " << (3.0 / 7.0) << endl;
	cout << "2.0 / 7.0 = " << (2.0 / 7.0) << endl;
	cout << "3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 = "
		 << (3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0) << endl;

	return 0;
}
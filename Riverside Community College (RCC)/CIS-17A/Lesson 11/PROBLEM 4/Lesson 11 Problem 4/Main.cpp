#include <iostream>
#include "TimeClock.h"

using namespace std;

int main()
{
	int h1, s1, h2, s2;
	
	cout << "Please enter the 1st time in military format: ";
	cin >> h1;
	cout << "Please enter the seconds for the 1st time: ";
	cin >> s1;
	cout << "Please enter the 2nd time in military format: ";
	cin >> h2;
	cout << "Please enter the seconds for the 2nd time: ";
	cin >> s2;

	TimeClock object(h1, s1, h2, s2);

	object.TimeDiff();

	cout << "\nTime 1 = " << object.time1.getStandHr() << ":" << object.time1.getMin() << ":" << object.time1.getSec();
	cout << "\n\nTime 2 = " << object.time2.getStandHr() << ":" << object.time2.getMin() << ":" << object.time2.getSec();
	cout << "\n\nTime Difference = " << object.Hour() << " Hours, " << object.Minutes() << " Minutes, and " << object.Seconds() << " seconds\n\n";

return 0;
}
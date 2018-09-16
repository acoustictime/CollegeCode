#include <iostream>
#include "MilTime.h"

using namespace std;

int main()
{

	int time, sec;

	cout << "Please enter the time in military format: ";
	cin >> time;
	
	cout << "Please enter the amount of seconds: ";
	cin >> sec;

	MilTime object(time, sec);

	cout << "\nMilitary Time: " << object.getHour() << ":" << object.getSec();
	cout << "\n\nStandard Time: " << object.getStandHr() << ":" << object.getMin() << ":" << object.getSec() << endl << endl;

return 0;
}
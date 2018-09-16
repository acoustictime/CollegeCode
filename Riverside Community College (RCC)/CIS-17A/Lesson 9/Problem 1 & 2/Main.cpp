
#include <iostream>
#include <cstring>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

const int stringsize = 15;

int main()
{
	char name[stringsize];
	double hours;
	int id;

	cin.getline(name, stringsize);

	cin >> id;
	
	
	
	TimeOff employee(name, id);
	
	
	cin >> hours;

	employee.maxvachours(hours);

	cout << employee.getname() << " " << employee.getiden() << endl;
	
	cout << employee.getmaxvachours() << " " << employee.getmaxvacdays();


return 0;
}
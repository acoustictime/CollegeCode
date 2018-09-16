
#include <iostream>
#include <cstring>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

const int stringsize = 15;
const int vacleave = 12;
const int sickleave = 8;

int main()
{
	char name[stringsize];
	int id;
	double months;

	cout << "Please enter the employee's name: ";
	cin.getline(name, stringsize);

	cout << "\nPlease enter the employee's id: ";
	cin >> id;

	TimeOff employee(name, id);
	
	cout << "\nPlease enter how many months " << name << " has worked here: ";
	cin >> months;

	employee.maxsickhours(months * sickleave);
	employee.maxvachours(months * vacleave);

	cout << "\n*** The Results ***\n\n";
	cout << "Employee Name: " << employee.getname();
	cout << "\nEmployee #: " << employee.getiden();
	cout << "\nMax Sick Days: " << employee.getmaxsickdays();
	cout << "\nMax Sick Hours: " << employee.getmaxsickhours();
	cout << "\nMax Vacation Days: " << employee.getmaxvacdays();
	cout << "\nMax Vacation Hours: " << employee.getmaxvachours();
	cout << endl;

return 0;
}
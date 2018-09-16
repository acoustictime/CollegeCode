// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-11-06															*
// *																	*
// * This program asks for the amount of hours worked, and the pay rate *
// * for each employee number.  It stores these amounts into seperate   *
// * arrays and also calculates their wages based upon their hours      *
// * worked and their pay rate and stores it into another array.        *
// **********************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

const int size = 7;

void initialize(double hours[], double payRate[], double wages[]);
void datainput(long empId[], double hours[], double payRate[], double wages[]);
void display(long empId[], double wages[]);

int main()
{

	long empId[size] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489}; // Sets the employee numbers
	double hours[size];
	double payRate[size];
	double wages[size];
	
	initialize(hours, payRate, wages);
	datainput(empId, hours, payRate, wages);
	display(empId, wages);

return 0;
}

// **********************************************************************
// * Definition of the function: initialize							    *
// * This function takes as it's arguements the hours, payrate, and     *
// * wages arrays, and intializes their values to 0. 				    *
// **********************************************************************

void initialize(double hours[], double payRate[], double wages[])
{
	int count;

	for (count = 0; count < size; count++)
	{
		hours[count] = 0;
		payRate[count] = 0;
		wages[count] = 0;
	}
}

// **********************************************************************
// * Definition of the function: datainput							    *
// * This function takes as it's arguements the empid, hours, payrate,  *
// * and wages arrays and prompts the user for the hours and wages per  *
// * employee id.  It also calculates the payrates per employee.        *
// **********************************************************************

void datainput(long empId[], double hours[], double payRate[], double wages[])
{
	int count;
	double hrs, rate;

	for (count = 0; count < size; count++)
	{
		hrs = 0;
		rate = 0;	

		cout << "Enter the amount of hours worked for employee # " << empId[count] << ": ";
		cin >> hrs;
		cout << endl;

		while (hrs < 0) // Confirms the hrs worked is greater than 0
		{
			cout << "The amount of hours must be greater than 0" << endl;
			cout << "Enter the amount of hours worked for employee # " << empId[count] << ": ";
			cin >> hrs;
			cout << endl;
		}

		hours[count] = hrs;

		cout << "Enter the payrate for employee # " << empId[count] << ": ";
		cin >> rate;
		cout << endl;

		while (rate < 6) // Confirms the pay rate is greater than or equal to 6
		{
			cout << "The payrate must be greater or equal to 6" << endl;
			cout << "Enter the payrate for employee # " << empId[count] << ": ";
			cin >> rate;
			cout << endl;
		}

		payRate[count] = rate;

		wages[count] = hrs * rate;
	}
}

// **********************************************************************
// * Definition of the function: display							    *
// * This function takes as it's arguements the empid and wages arrays  *
// * and displays the values that are in them.                          *
// **********************************************************************

void display(long empId[], double wages[])
{
	int count;

	cout << setw(11) << left << "Employee #" << setw(10) << right << "Wages" << endl << endl;
	cout << setprecision(2) << showpoint << fixed;

	for (count = 0; count < size; count++)
	{
		cout << setw(11) << left << empId[count] << setw(4) << right << "$" << setw(6) << right << wages[count] << endl;		
	}
}







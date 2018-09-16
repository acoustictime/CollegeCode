// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 11-29-06															*
// *																	*
// * This program allows the user to enter the time in military format  *
// * and it will display the time in standard and military format.  	*
// **********************************************************************

#include <iostream>
#include "MilTime.h"

using namespace std;

int main()
{

	int time, sec;
	MilTime object;

	cout << "Please enter the time in military format: ";
	cin >> time;
	
	cout << "Please enter the amount of seconds: ";
	cin >> sec;
	
	try // Used to check if the hour and seconds is valid, if not, an error is thrown
	{
		object.setTime(time, sec);
	}
	catch (MilTime::BadHour) // Thrown if the hours is invalid
	{
		cout << "\nInvalid value entered for the hour, Game Over!!\n\n";
		return -1;
	}
	catch (MilTime::BadSeconds) // Thrown if the seconds is invalid
	{
		cout << "\nInvalid value entered for the seconds, Game Over!!\n\n";
		return -1;
	}

	cout << "\nMilitary Time: " << object.getHour() << ":" << object.getSec();
	cout << "\n\nStandard Time: " << object.getStandHr() << ":" << object.getMin() << ":" << object.getSec() << endl << endl;

return 0;
}
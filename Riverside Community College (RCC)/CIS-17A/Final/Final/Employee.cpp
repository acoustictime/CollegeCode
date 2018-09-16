#include "Employee.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Employee::Employee(char name[],char title[],float rate)
{
	strcpy(MyName,name);
	strcpy(JobTitle,title);
	Employee::setHourlyRate(rate);

	int    HoursWorked = 0;     
	float  GrossPay = 0.0;        
	float  NetPay = 0.0; 
}

double Employee::Tax(float gross)
{
	double taxes = 0;
		
	if (gross < 500)
	{
		taxes = gross * .1;
	}
	else if (gross > 500 && gross <= 1000)
	{
		taxes = (500 * .1) + ((gross -500) * .2);
	}
	else if (gross > 1000)
	{
		taxes = (500 * .1) + (500 * .2) + ((gross - 1000) * .3);
	}
	
	return taxes;
}

float  Employee::CalculatePay(float hours,int rate) //Procedure
{
	return getNetPay(getGrossPay(setHourlyRate(hours),setHoursWorked(rate)));
}

float  Employee::getGrossPay(float rate,int hours)  //Procedure
{
	float gross = 0;
	

	if (hours < 40)
	{
		gross = rate * hours;
	}
	else if (hours > 40 || hours < 50)
	{
		gross = (rate * 40) + ((hours - 40) * (rate * 1.5));
	}
	else if (hours > 50)
	{
		gross = (rate * 40) + (10 * (rate * 1.5)) + ((hours - 50) * (rate * 2));
	}
	
	GrossPay = gross;

	return gross;
}

float  Employee::getNetPay(float)        //Procedure
{
	NetPay = GrossPay - Employee::Tax(GrossPay);
	return NetPay;
}
		
void   Employee::toString()              //Procedure
{
	cout << fixed << setprecision(2);
	cout << "Name = " << MyName << " Job Title = " << JobTitle;
	cout << "\n Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = " << NetPay << endl;
}

int    Employee::setHoursWorked(int hours)     //Procedure
{
	if (hours > 0 && hours < 84)
	{
		HoursWorked = hours;
	}
	else
	{
		cout << "Invalid Hours Entered\n";
		HoursWorked = 0;
		HourlyRate = 0.0;
		GrossPay = 0.0;
		NetPay = 0.0;
	}
	
	return HoursWorked;
}
		
float  Employee::setHourlyRate(float rate)    //Procedure
{
	if (rate > 0 && rate < 200)
	{
		HourlyRate = rate;
	}
	else
	{
		cout << "Invalid Rate Entered\n";
		HoursWorked = 0;
		HourlyRate = 0.0;
		GrossPay = 0.0;
		NetPay = 0.0;
	}
	
	return HourlyRate;
}



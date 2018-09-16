// Employee.h: interface for the Employee class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEE_H__79FD571A_73DD_45FA_BE3B_7AEC8CE96ABC__INCLUDED_)
#define AFX_EMPLOYEE_H__79FD571A_73DD_45FA_BE3B_7AEC8CE96ABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cstring>



class Employee
{
private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property


public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
	
};

#endif // !defined(AFX_EMPLOYEE_H__79FD571A_73DD_45FA_BE3B_7AEC8CE96ABC__INCLUDED_)

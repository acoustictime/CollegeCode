// TimeOff.h: interface for the TimeOff class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMEOFF_H__18DDCAD8_B3A4_4843_8AD8_3C58A657DB29__INCLUDED_)
#define AFX_TIMEOFF_H__18DDCAD8_B3A4_4843_8AD8_3C58A657DB29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "NumDays.h"

class TimeOff  
{
	private:
		
		string employeename;
		int iden;
		
		// NumDays objects
		
		NumDays maxSickDays;
		NumDays sickTaken;
		NumDays maxVacation;
		NumDays vacTaken;
		NumDays maxUnpaid;
		NumDays unpaidTaken;
		
	public:
		
		TimeOff(char name[], int id);

		string getname()
		{	return employeename; };

		int getiden()
		{ return iden; };
				
		void maxsickhours(double hours) // Used to input the max sick hours
		{ maxSickDays.InputHours(hours); };

		void maxsickdays(double days) // Used to input the max sick days
		{	maxSickDays.InputDays(days); };
				
		double getmaxsickhours() // Used to return the max sick hours
		{ return maxSickDays.GetHours(); };
	
		double getmaxsickdays() // Used to return the max sick days
		{ return maxSickDays.GetDays(); };
		
		void sicktakenhours(double hours) // Used to input the sick taken hours
		{ sickTaken.InputHours(hours); };

		void sicktakendays(double days) // Used to input the sick taken days
		{	sickTaken.InputDays(days); };
				
		double getsicktakenhours() // Used to return the sick taken hours
		{ return sickTaken.GetHours(); };
	
		double getsicktakendays() // Used to return the sick taken days
		{ return sickTaken.GetDays(); };
		
		void TimeOff::maxvachours(double hours);

		void TimeOff::maxvacdays(double days);
				
		double getmaxvachours() // Used to return the max vac hours
		{ return maxVacation.GetHours(); };
	
		double getmaxvacdays() // Used to return the max vac days
		{ return maxVacation.GetDays(); };

		void vactakenhours(double hours) // Used to input the vac taken hours
		{ vacTaken.InputHours(hours); };

		void vactakendays(double days) // Used to input the vac taken days
		{	vacTaken.InputDays(days); };
				
		double getvactakenhours() // Used to return the vac taken hours
		{ return vacTaken.GetHours(); };
	
		double getvactakendays() // Used to return the vac taken days
		{ return vacTaken.GetDays(); };

		void maxunpaidhours(double hours) // Used to input the max unpaid hours
		{ maxUnpaid.InputHours(hours); };

		void maxunpaiddays(double days) // Used to input the max unpaid days
		{	maxUnpaid.InputDays(days); };
				
		double getmaxunpaidhours() // Used to return the max unpaid hours
		{ return maxUnpaid.GetHours(); };
	
		double getmaxunpaiddays() // Used to return the max unpaid days
		{ return maxUnpaid.GetDays(); };
		
		void unpaidtakenhours(double hours) // Used to input the unpaid taken hours
		{ unpaidTaken.InputHours(hours); };

		void unpaidtakendays(double days) // Used to input the unpaid taken days
		{	unpaidTaken.InputDays(days); };
				
		double getunpaidtakenhours() // Used to return the unpaid taken hours
		{ return unpaidTaken.GetHours(); };
	
		double getunpaidtakendays() // Used to return the unpaid taken days
		{ return unpaidTaken.GetDays(); };
};

#endif // !defined(AFX_TIMEOFF_H__18DDCAD8_B3A4_4843_8AD8_3C58A657DB29__INCLUDED_)

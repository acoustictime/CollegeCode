// PayRoll.h: interface for the PayRoll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAYROLL_H__21D6F9C9_14AB_4FE1_8896_3CBCC33C78DF__INCLUDED_)
#define AFX_PAYROLL_H__21D6F9C9_14AB_4FE1_8896_3CBCC33C78DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PayRoll  
{
	private:
		double rate, hours, pay;
		void paycalc();
		
	public:
		PayRoll();
		bool input(double hours, double rate);
		void retreive(double &h, double &r, double &p);
		
};

#endif // !defined(AFX_PAYROLL_H__21D6F9C9_14AB_4FE1_8896_3CBCC33C78DF__INCLUDED_)

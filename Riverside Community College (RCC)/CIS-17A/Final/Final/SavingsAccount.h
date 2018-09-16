// SavingsAccount.h: interface for the SavingsAccount class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVINGSACCOUNT_H__9BBB07F4_74D3_44E5_8DB8_686A3FB6D776__INCLUDED_)
#define AFX_SAVINGSACCOUNT_H__9BBB07F4_74D3_44E5_8DB8_686A3FB6D776__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SavingsAccount
{

public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();                    //Output Properties
	private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property
};

#endif // !defined(AFX_SAVINGSACCOUNT_H__9BBB07F4_74D3_44E5_8DB8_686A3FB6D776__INCLUDED_)

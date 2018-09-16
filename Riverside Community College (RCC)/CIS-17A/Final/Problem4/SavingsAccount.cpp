// SavingsAccount.cpp: implementation of the SavingsAccount class.
//
//////////////////////////////////////////////////////////////////////

#include "SavingsAccount.h"
#include <iostream>
#include <cmath>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SavingsAccount::SavingsAccount(float amount)
{
	if (amount > 0)
	{
		Balance = amount;
	}
	else
	{
		Balance = 0.0;
		FreqWithDraw = 0;
		FreqDeposit = 0;
	}
}

void  SavingsAccount::Transaction(float amount)
{
	if (amount > 0)
	{
		SavingsAccount::Deposit(amount);
	}
	else if (amount < 0)
	{
		SavingsAccount::Withdraw(amount);
	}
	else if (amount == 0)
	{
	}

}

float SavingsAccount::Withdraw(float amount)               //Utility Procedure
{
	
	if ((Balance + amount) < 0)
	{
		cout << "WithDraw not Allowed\n";
		FreqWithDraw++;
	}
	else if((Balance + amount) >= 0)
	{
		Balance = Balance + amount;
		FreqWithDraw++;
	}
	
	
	return amount;
}
		
float SavingsAccount::Deposit(float amount)
{
	FreqDeposit++;

	Balance = Balance + amount;

	return amount;
}

float SavingsAccount::Total(float rate,int years)         //Savings Procedure
{
	return Balance * pow((1+rate),years);
}


float SavingsAccount::TotalRecursive(float rate,int years)
{
	// Couldn't figure out the recursive version
	
	return Balance * pow((1+rate),years);
}

void  SavingsAccount::toString()
{
	cout << "Balance = " << Balance;
	cout << "\nWithDraws = " << FreqWithDraw;
	cout << "\nDeposits = " << FreqDeposit;
}

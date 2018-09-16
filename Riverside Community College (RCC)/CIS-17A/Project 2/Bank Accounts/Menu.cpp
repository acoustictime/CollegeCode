// Menu.cpp: implementation of the Menu class.
//
//////////////////////////////////////////////////////////////////////

#include "Menu.h"
#include <iostream>

using namespace std;

// **********************************************************************
// * Definition of member function: Menu::Menu						    *
// * This is the default constructor that doesn't do anything		    *
// **********************************************************************

Menu::Menu()
{

}

// **********************************************************************
// * Definition of member function: Menu::mainmenu					    *
// * This member function displays the main menu					    *
// **********************************************************************

void Menu::mainmenu()
{
	cout << "*** Bank Menu ***\n\n";
	cout << "1. Withdraw\n";
	cout << "2. Deposit\n";
	cout << "3. Transfer\n";
	cout << "4. End Month\n";
	cout << "5. View Transactions\n";
	cout << "6. Quit\n\n";
	cout << "Choice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::withdraw					    *
// * This member function displays the withdraw menu				    *
// **********************************************************************

void Menu::withdraw()
{
	cout << "*** Withdraw Menu ***\n\n";
	cout << "1. Checking\n";
	cout << "2. Savings\n";
	cout << "3. Main Menu\n\n";
	cout << "Choice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::deposit					    *
// * This member function displays the deposit menu					    *
// **********************************************************************

void Menu::deposit()
{
	cout << "*** Deposit Menu **\n\n";
	cout << "1. Checking\n";
	cout << "2. Savings\n";
	cout << "3. Main Menu\n\n";
	cout << "Choice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::endmonth					    *
// * This member function displays the end of month menu			    *
// **********************************************************************

void Menu::endmonth()
{
	cout << "*** End Month Menu ***\n\n";
	cout << "1. Done entering transactions for the month\n";
	cout << "2. Not done, go back to the main menu\n\n";
	cout << "Choice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::transfer					    *
// * This member function displays the transfer menu				    *
// **********************************************************************

void Menu::transfer()
{
	cout << "*** Transfer Menu ***\n\n";
	cout << "1. From Checking to Savings\n";
	cout << "2. From Savings to Checking\n";
	cout << "3. Main Menu\n\n";
	cout << "Choice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::newaccount				    *
// * This member function displays the new account menu				    *
// **********************************************************************

void Menu::newaccount()
{
	cout << "Do you have an account already?";
	cout << "\n\n1. Yes";
	cout << "\n2. No";
	cout << "\n\nChoice Is: ";
}

// **********************************************************************
// * Definition of member function: Menu::transactions				    *
// * This member function displays the transactions menu			    *
// **********************************************************************

void Menu::transactions()
{
	cout << "*** View Transactions **\n\n";
	cout << "1. Checking\n";
	cout << "2. Savings\n";
	cout << "3. Main Menu\n\n";
	cout << "Choice Is: ";
}
		

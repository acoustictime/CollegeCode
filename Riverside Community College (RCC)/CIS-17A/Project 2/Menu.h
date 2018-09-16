// Menu.h: interface for the Menu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU_H__AEAEB101_D4DB_4561_A3CA_F3909DD96FD7__INCLUDED_)
#define AFX_MENU_H__AEAEB101_D4DB_4561_A3CA_F3909DD96FD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Menu  // Class used to display menu
{
	public:
		Menu();
		void mainmenu();
		void withdraw();
		void deposit();
		void transfer();
		void endmonth();
		void newaccount();
		void transactions();
};

#endif // !defined(AFX_MENU_H__AEAEB101_D4DB_4561_A3CA_F3909DD96FD7__INCLUDED_)

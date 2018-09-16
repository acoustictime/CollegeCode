// Nim.h: interface for the Nim class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NIM_H__6F6AABA7_60F4_4C4D_B8F4_F37712AB2E18__INCLUDED_)
#define AFX_NIM_H__6F6AABA7_60F4_4C4D_B8F4_F37712AB2E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>


using namespace std;


class Nim  
{
	
	struct data
	{
		string playername;
		int wins;
		int losses;
		double winpercent;
	};

	private:
		data playerinfo;
		data *ptr;
		
		
		
		


	public:
		Nim(char name[]);
		void random(int &currentvalue, int low, int high);
		void GameMenu();
		void HighScores(int index, string &name, int &wins, int &losses, double &winpercent);
		bool CheckWinner(int currentvalue, int turn);
		


	

};

#endif // !defined(AFX_NIM_H__6F6AABA7_60F4_4C4D_B8F4_F37712AB2E18__INCLUDED_)

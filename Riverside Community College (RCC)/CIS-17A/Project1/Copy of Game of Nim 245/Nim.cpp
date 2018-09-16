// Nim.cpp: implementation of the Nim class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Nim.h"

using namespace std;

const int savesize = 10;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Nim::Nim(char name[])
{
	srand(time(NULL));

	playerinfo.wins = 0;
	playerinfo.losses = 0;
	playerinfo.playername = name;
	
	ptr = new data [savesize];

	ifstream infile;
	infile.open("gamedata.txt");

	if (!infile)
	{
		cout << "No input file was found";
	}
	else
	{
		for (int i = 0; i < savesize; i++)
		{
				infile >> ptr[i].playername >> ptr[i].wins >> ptr[i].losses;
				ptr[i].winpercent = (static_cast<double>(ptr[i].wins) / (static_cast<double>(ptr[i].wins) + static_cast<double>(ptr[i].losses))) * 100;
				cout << ptr[i].playername << " " << ptr[i].wins << " " << ptr[i].losses << " " << ptr[i].winpercent << endl;
			
		}
	
	
	}
}



void Nim::random(int &currentvalue, int low, int high)
{
	currentvalue = low + (high - low) * rand() * (1.0 / RAND_MAX);
}

void Nim::GameMenu()
{
	cout << "Welcome to The Game of Nim " << playerinfo.playername << "\n\n";
	cout << "1. Play Game\n";
	cout << "2. View High Scores\n";
	cout << "3. Quit\n";
	cout << "Your Choice Is: ";
}

bool Nim::CheckWinner(int currentvalue, int turn)
{
	bool status;
	
	if (currentvalue == 1)
	{
		status = false;
		if (turn == 0)
		{
			playerinfo.wins++;
		}
		else
		{
			playerinfo.losses++;
		}
	}
	else
	{
		status = true;
	}
	
	cout << "\n WIns = " << playerinfo.wins << "\n Losses = " << playerinfo.losses;
	cout << endl;
	
return status;
}

void Nim::HighScores(int index, string &name, int &wins, int &losses, double &winpercent)
{

	name = ptr[index].playername;
	wins = ptr[index].wins;
	losses = ptr[index].losses;
	winpercent = ptr[index].winpercent;
}

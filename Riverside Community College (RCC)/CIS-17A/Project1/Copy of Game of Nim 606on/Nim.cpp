// Nim.cpp: implementation of the Nim class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
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
	playerinfo.score = 0;
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
				infile >> ptr[i].playername >> ptr[i].wins >> ptr[i].losses >> ptr[i].score;
				cout << ptr[i].playername << " " << ptr[i].wins << " " << ptr[i].losses << " " << ptr[i].score << endl;
			
		}
	
	
	}

	infile.close();

}

Nim::~Nim()
{
	
	

	ofstream outfile;

	outfile.open("gamedata.txt", ios::out);

	for (int i = 0; i < savesize; i++)
	{
		outfile << ptr[i].playername << " " << ptr[i].wins << " " << ptr[i].losses << " " << ptr[i].score << endl;
	}

	outfile.close();
	
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
			playerinfo.score = playerinfo.score + 100;
		}
		else
		{
			playerinfo.losses++;
			playerinfo.score = playerinfo.score - 50;
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

void Nim::HighScores(int index, string &name, int &wins, int &losses, int &score)
{

	name = ptr[index].playername;
	wins = ptr[index].wins;
	losses = ptr[index].losses;
	score = ptr[index].score;
}

bool Nim::CheckHighScore()
{
	bool status = false;
	int position;

	for (int i = 10; i > 0; i--)
	{
		if (playerinfo.score > ptr[i].score)
		{
			position = i;
			status = true;
		}
		
	}

	if (status)
	{

		for (i = 9; i > position; i--)
		{
			ptr[i].playername = ptr[i - 1].playername;
			ptr[i].losses = ptr[i -1].losses;
			ptr[i].score = ptr[i -1].score;
			ptr[i].wins = ptr[i - 1].wins;
		}
	
		ptr[position].playername = playerinfo.playername;
		ptr[position].losses = playerinfo.losses;
		ptr[position].score = playerinfo.score;
		ptr[position].wins = playerinfo.wins;
	
	}

	

return status;
}


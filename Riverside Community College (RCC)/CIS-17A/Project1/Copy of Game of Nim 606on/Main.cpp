

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include "Nim.h"

using namespace std;

const int lowinitial = 10;
const int highinitial = 100;
const int lowpair = 0;
const int highpair = 10;
const int stringsize = 10;
const int savesize = 10;

void menu1(Nim &Game, int smart);
void menu2(Nim Game);
void menu3(Nim Game);


int main(int argv,char *argc[])
{	
	int winner;  // 0 is user, 1 is computer
	int smart;	
	int menuchoice;
	char name[stringsize];

	









	cout << "Please enter your first name: ";
	cin.getline(name, stringsize);
	cout << endl;

	Nim game(name);

	do
	{
		game.random(smart, lowpair, highpair);

		if (smart <= 5)
		{
			smart = 0;
		}
		else
		{
			smart = 1;
		}

		cout << "\nSmart value is " << smart << endl;

		game.GameMenu();
		cin >> menuchoice;

		switch (menuchoice)
		{
		case 1: menu1(game, smart);
			break;
		case 2: menu2(game);
			break;
		case 3:
			menu3(game);
			break;
		default: cout << "\nInvalid Menuchoice!!\n\n";
		};

	}
	while (menuchoice != 3);

return 1;
}

void menu1(Nim &game, int smart)
{
	int initialvalue;
	int currentvalue;
	int turn; // 0 is user, 1 is computer
	int currentnumber;
	int computercurrentnumber;
	int smartvalue = 11;
	int temppcnum = 101;
	
	game.random(initialvalue, lowinitial, highinitial);
	system("cls");
	cout << "Initial Value = " << initialvalue;
	currentvalue = initialvalue;
	game.random(turn, lowpair, highpair);

	if (turn <= 5)
		{
			turn = 0;
		}
		else
		{
			turn = 1;
		}

	cout << "\nTurn is " << turn << endl;
	while (turn != 3)
	{
		if (turn == 0)
		{
			cout << "\nPlease enter in your guess: ";
			cin >> currentnumber;

			while (currentnumber > currentvalue / 2 || currentnumber < 1)
			{
				cout << "\n\nYour number was not valid, try again\n\n";
				cout << "\nPlease enter in your guess: ";
				cin >> currentnumber;
			}

			currentvalue = currentvalue - currentnumber;

			cout << "\n\n" << currentvalue << "\n\n";

			if (!game.CheckWinner(currentvalue, turn))
			{
				cout << "\n\nYou have won the Game of Nim\n\n";

				turn = 2;
			}

			turn++;
		}
		else if (turn == 1)
		{	
			if (smart == 0)
			{
				game.random(computercurrentnumber, 1, currentvalue / 2);
			}
			else if (smart == 1)
			{
				computercurrentnumber = 101;

				while (computercurrentnumber > currentvalue / 2 || computercurrentnumber < 1)
				{
					if (currentvalue == 3 || currentvalue == 7 || currentvalue == 15 || currentvalue == 31 || currentvalue == 63)
					{
						game.random(computercurrentnumber, 1, currentvalue / 2);
						cout << "entered";
					}
					else
					{
						temppcnum = pow(2, smartvalue) - 1;
						computercurrentnumber = currentvalue - temppcnum;
					}

					smartvalue--;
				}
			}
			
			cout << "\nComputers guess is " << computercurrentnumber;

			currentvalue = currentvalue - computercurrentnumber;

			cout << "\n\n" << currentvalue << "\n\n";

			if (!game.CheckWinner(currentvalue, turn))
			{
				cout << "\n\nYou have lost the Game of Nim\n\n";
				turn = 4;
			}

			turn--;
		}
	}
}

void menu2(Nim Game)
{	
	system("cls");
	string tempname;
	int tempwins, templosses;
	int tempscore;

	cout << fixed << setprecision(2);
	cout << "\n\n\t*** High Scores List ***\n\n";
	cout << left << setw(11) << "Name" << right << setw(5) << "Wins" << right << setw(8) << "Losses" << right << setw(8) << "Score\n\n";
	
	for (int index = 0; index < savesize; index++)
	{
	
	Game.HighScores(index, tempname, tempwins, templosses, tempscore);
	
	cout << left << setw(11) << tempname << right << setw(5) << tempwins << right << setw(8) << templosses << right << setw(8) << tempscore << endl;
	}

	
}

void menu3(Nim Game)
{

	double mypercent;
	string tempname;
	int tempwins, templosses, position;

	if (Game.CheckHighScore())
	{
		cout << "You have a high score.\n";
		


	}
	else
	{
		cout << "You have not gotten a high score";
	}

	

}


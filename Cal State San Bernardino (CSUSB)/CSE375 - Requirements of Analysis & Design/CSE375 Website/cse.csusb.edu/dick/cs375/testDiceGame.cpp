/* Demonstration of coding an Object Oriented Design 
   Implements Pages 8-11 of Larman

   This is a unit test of class DiceGame
*/

#include <iostream>
#include <cassert>

#include "DiceGame.cpp"

int main()
{

	DiceGame g;
	g . play();

	cout << g.getScore()<<endl;
	if( g.getWin() )
		cout << "You Win\n";
	else
		cout << "You Lose\n";
	return 0;
}

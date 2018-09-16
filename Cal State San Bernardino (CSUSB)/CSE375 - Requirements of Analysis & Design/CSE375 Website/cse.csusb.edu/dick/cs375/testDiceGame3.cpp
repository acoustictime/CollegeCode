/* Demo Polymorphic version of Dice Game with Run time choice of Dice
   Demonstration of coding an Object Oriented Design 
   This is a unit test of class DiceGame3
*/

#include <iostream>
#include <cassert>

#include "DiceGame3.cpp"

int main(int argc, char* argv[])/*argc is number args including the command itself*/
{
	// cout << "argc = "<<argc << "\n";
	DiceGame g(argc-1);// evil trick -- number of arguments = number loaded dice

	g . play();

	cout << g.getScore()<<endl;
	if( g.getWin() )
		cout << "You Win\n";
	else
		cout << "You Lose\n";
	return 0;
}

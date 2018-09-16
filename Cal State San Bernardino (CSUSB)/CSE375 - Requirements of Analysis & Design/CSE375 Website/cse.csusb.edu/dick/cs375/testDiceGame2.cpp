/* Demo Polymorphic version od Dice Game
   Demonstration of coding an Object Oriented Design 
   Implements Pages 8-11 of Larman

   This is a unit test of class DiceGame
*/

#include <iostream>
#include <cassert>

#include "DiceGame2.cpp"
#include "LoadedDie.cpp"

int main()
{
	Die * d1 = new LoadedDie();
	//cerr << "Die * d1 =...OK\n";
	Die * d2 = new Die();
	//cerr << "LoadedDie * d2=... OK\n";
	DiceGame g(d1,d2);
	//cerr << "DiceGame g(d1,d2); OK\n";
	g . play();
	//cerr << "g.play() OK\n";

	cout << g.getScore()<<endl;
	if( g.getWin() )
		cout << "You Win\n";
	else
		cout << "You Lose\n";
	return 0;
}

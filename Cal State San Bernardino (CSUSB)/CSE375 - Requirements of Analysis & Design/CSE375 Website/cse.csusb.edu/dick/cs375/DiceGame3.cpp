/* Chooses the number of loaded dice when the program runs */
#include <iostream>
using namespace std;
#include "LoadedDie.cpp"

class DiceGame
{
	Die * die1;
	Die * die2;
  public:
	DiceGame(){die1 = new Die(); die2 = new Die(); }
	DiceGame(int n)/* n is the number of loaded dice: 0,1,or 2 */
	{
	   if(n<=0){die1 = new Die(); die2 = new Die(); }
	   else if(n==1){die1 = new Die(); die2 = new LoadedDie(); }
	   else/*n>1*/ {die1 = new LoadedDie(); die2 = new LoadedDie(); }
	}

	virtual void play()
	{
		die1->roll();
		int fv1=die1->getFaceValue();

		die2->roll();
		int fv2=die2->getFaceValue();

		score = fv1+fv2;
	}

// following not in book... but DiceGame can't be tested without them
private:
	int score;
public:
	virtual int getScore(){return score;}
	virtual bool getWin(){return score==7;}
};


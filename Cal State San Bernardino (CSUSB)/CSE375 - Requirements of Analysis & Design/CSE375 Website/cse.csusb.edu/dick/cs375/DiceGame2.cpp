/* Declares a class in Page 10 of Larman */
#include <iostream>
using namespace std;
#include "Die2.cpp"

class DiceGame
{
	Die * die1;
	Die * die2;
  public:
	DiceGame(){die1 = new Die(); die2 = new Die2(); }
	DiceGame(Die * d1, Die * d2){die1 = d1; die2 = d2; }

	virtual void play()
	{
		die1->roll();
		//cerr << "die1->roll()\n";
		int fv1=die1->getFaceValue();
		//cerr << "die1->getFaceValue()\n";

		die2->roll();
		//cerr << "die2->roll()\n";
		int fv2=die2->getFaceValue();
		//cerr << "die2->getFaceValue()\n";

		score = fv1+fv2;
	}

// following not in book... but DiceGame can't be tested without them
private:
	int score;
public:
	virtual int getScore(){return score;}
	virtual bool getWin(){return score==7;}
};

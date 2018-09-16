/* Declares a class in Page 10 of Larman */
#include <iostream>
using namespace std;
#include "Die.cpp"

class DiceGame
{
	Die * die1;
	Die * die2;
  public:
	DiceGame(){die1 = new Die(); die2 = new Die(); }
	DiceGame(Die * d1, Die * d2){die1 = d1; die2 = d2; }

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

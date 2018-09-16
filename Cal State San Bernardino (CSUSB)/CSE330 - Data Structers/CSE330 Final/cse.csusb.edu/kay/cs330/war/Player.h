#ifndef PLAYER_H
#define PLAYER_H

/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Player.h

description:    this module is the definition of the class Player

implementation: only interface of a class is given in a header file.
		idealy even the implementation of in-line functions must
		reside in the corresponding *.cpp file.
**********************************************************************/

#include "Card.h"
#include "Deck.h"

class Player {
protected:    	       // kay 8/20/98, was private
    Card myCards[3];
    int myScore;
    int removedCard;
public:
    Player(Deck &);
    Card draw();       // another draw()!
    void addPoints(int howMany) { myScore += howMany; }
    int score() { return myScore; }
    void replaceCard(Deck &aDeck) { myCards[removedCard] = aDeck.draw(); }
}; // Player

#endif

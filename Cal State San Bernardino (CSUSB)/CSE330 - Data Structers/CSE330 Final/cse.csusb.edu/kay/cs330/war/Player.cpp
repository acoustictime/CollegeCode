/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Player.cpp

description:    this module is the implementation of the class Player.

implementation: the constructor resets the score, and picks three cards.
		the draw() method randomly chooses one of the three cards.
**********************************************************************/

#include "Player.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

extern RandomInteger randomizer;

Player::Player(Deck & aDeck)
{
    myScore = 0;
    for (int i = 0; i < 3; i++)
        myCards[i] = aDeck.draw();
    removedCard = 0;
} // constructor

Card Player::draw()
{
    removedCard = randomizer(3);
    return myCards[removedCard];
} // draw


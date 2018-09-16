#ifndef CARD_H
#define CARD_H

/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Card.h

description:    this module is the interface definition of the Card class.

implementation: some in-line methods are given here, idealy they should
		must reside in Card.cpp
**********************************************************************/

#include <iostream>

using namespace std;

enum suits { diamond, club, heart, spade };

class Card {
    // private by default
    int      rank;        // rank of card
    suits    suit;        // suit of card
public:
    // constructors
    Card();               // initialize a card with default values
    Card(suits, int);     // initialize a card with given values
    // accessors
    int getRank() { return rank; } // an in-line function
    suits getSuit() { return suit; }
    // mutators
    void setRank(int rv) { rank = rv; }
    void setSuit(suits sv) { suit = sv; }
}; // Card
 
ostream & operator<<(ostream &, Card );

#endif

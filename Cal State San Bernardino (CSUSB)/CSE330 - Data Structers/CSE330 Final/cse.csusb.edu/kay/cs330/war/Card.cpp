/**********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Card.cpp

description:    this module is the implementation of the class Card.
		it represents a single playing card.

implementation: only two constructors are given.
                the rest are in-line methods given in Card.h
		also the operator << is overloaded to output a Card
		note this operator is a non-member function.
**********************************************************************/

#include "Card.h"

using namespace std;

Card::Card()
{
    rank = 1;
    suit = spade;
} // constructor

Card::Card(suits sv, int rv)
{
    rank = rv;
    suit = sv;
} // constructor

// output a textual presentation of a Card
ostream & operator<<(ostream & out, Card aCard)
{
    switch (int rank = aCard.getRank()) {
        case 1:  out << "Ace"; break;
        case 11: out << "Jack"; break;
        case 12: out << "Queen"; break;
        case 13: out << "King"; break;
        default: out << rank;
    }

    switch (suits suit = aCard.getSuit()) {
        case diamond: out << " of Diamonds"; break;
        case spade:   out << " of spades"; break;
        case heart:   out << " of hearts"; break;
        case club:    out << " of clubs"; break;
    }
    return out;
} // operator<<


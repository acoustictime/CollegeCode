/**************************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Deck.cpp

description:    this module is the implementation of the class Deck.
		it represents a deck of playing cards.

implementation: based on Card class, uses STL random_shuffle to shuffle
		the cards.
***************************************************************************/

#include <algorithm>

#include "Card.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

extern RandomInteger randomizer;

Deck::Deck()
{
    topCard = 0;
    for (int i = 1; i <= 13; i++) {
        Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
        cards[topCard++] = c1;
        cards[topCard++] = c2;
        cards[topCard++] = c3;
        cards[topCard++] = c4;
    }
} // constructor

Card Deck::draw()
{
    if (!isEmpty())
        return cards[--topCard];
    else { 
        Card spadeAce(spade, 1);
        return spadeAce;
    }
} // draw

void Deck::shuffle()
{
    random_shuffle(cards, cards+52, randomizer);
} // shuffle

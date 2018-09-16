#ifndef DECK_H
#define DECK_H

/**************************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Card.cpp

description:    this module is the dfeinition of the class Deck.

implementation: as an include file, it provides the interface definition.
***************************************************************************/

#include "Card.h"

class Deck {
    Card cards[52];       // deck of 52 cards
    int topCard;          // 1 + index of next available card
public:
    Deck();
    // shuffle uses the generic algorithm random_shuffle from STL
    void shuffle();
    bool isEmpty() { return topCard <= 0; }
    Card draw();          // return next card
}; // Deck

#endif

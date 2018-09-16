#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           HumanPlayer.h

description:    this module is the definition of class HumanPlayer

implementation: it is derived from class Player
		note the base class constructor invocation.
**********************************************************************/

#include "Player.h"
#include "Card.h"
#include "Deck.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(Deck &deck): Player(deck) {} // kay 8/20/98
                                             // calls base constructor
    Card draw(); // another draw()!
}; // HumanPlayer

#endif

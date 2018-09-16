/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Deck.h
 Description: This class header file was taken directly from the war program with
              no modification to it.   
 *******************************************************************************/

#ifndef _Deck_h
#define _Deck_h

#include "Card.h"
#include "Random.h"
#include <stdlib.h>       
#include <algorithm>      

class Deck {
    Card cards[52];    // deck of 52 cards
    int topCard;       // size of deck
public:
    Deck();
    void shuffle();
    bool isEmpty() { return topCard <= 0; } 
    Card draw();    
}; // Deck

#endif

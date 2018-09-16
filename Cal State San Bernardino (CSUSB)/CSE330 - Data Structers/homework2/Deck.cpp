/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Deck.cpp
 Description: This class header file was taken directly from the war program with
              slight modification to it.  Since ace is highest value, started
              for loop that generates the cards at the lowest value of 2 to 14   
 *******************************************************************************/

#include "Deck.h"
#include "Random.h"
#include <algorithm>

using namespace std;

extern Random randomizer;

Deck::Deck() {
    topCard = 0;
    for (int i = 2; i <= 14; i++) { // loop now accounts for 2 through 14
        Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
        cards[topCard++] = c1;
        cards[topCard++] = c2;
        cards[topCard++] = c3;
        cards[topCard++] = c4;
    }
} 

Card Deck::draw() {
    if (!isEmpty())
        return cards[--topCard];
    else { 
        Card spadeAce(spade, 1);
        return spadeAce;
    }
} 

void Deck::shuffle()
{
    random_shuffle(cards, cards+52, randomizer);
} // shuffle

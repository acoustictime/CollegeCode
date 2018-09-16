/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Card.cpp
 Description: This class file was taken directly from the war program with
              slight modification.  It now has ace = 14 instead of 1.
 *******************************************************************************/

#include <iostream>
#include <algorithm>
#include "Card.h"

using namespace std;

Card::Card() {
    rank = 1;
    suit = spade;
}

Card::Card(suits sv, int rv) {
    rank = rv;
    suit = sv;
}

ostream & operator<<(ostream & out, Card aCard) {
    switch (int rank = aCard.getRank()) {
        case 11: out << "Jack"; break;
        case 12: out << "Queen"; break;
        case 13: out << "King"; break;
        case 14:  out << "Ace"; break; // ace now highest value

        default: out << rank;
    }
    
    switch (suits suit = aCard.getSuit()) {
        case diamond: out << " Diamonds"; break;
        case spade:   out << " Spades"; break;
        case heart:   out << " Hearts"; break;
        case club:    out << " Clubs "; break;
    }
    return out;
} // operator<< 

/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Card.h
 Description: This class header file was taken directly from the war program with
              no modification to it.   
 *******************************************************************************/

#ifndef _Card_h
#define _Card_h

#include <iostream>

using namespace std;

enum suits { diamond, club, heart, spade };

class Card {
    int rank;
    suits suit;
public:
    Card();
    Card(suits, int);
    int getRank() { return rank; }
    suits getSuit() { return suit; };
    void setRank(int rv) { rank = rv; };
    void setSuit(suits sv) { suit = sv; };
};

ostream & operator<<(ostream &, Card );

#endif

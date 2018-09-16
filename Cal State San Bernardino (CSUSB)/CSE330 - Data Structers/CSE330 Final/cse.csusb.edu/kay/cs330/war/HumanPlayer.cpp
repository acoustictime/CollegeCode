/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           HumanPlayer.cpp

description:    this module is the implementation of the class HumanPlayer.

implementation: class HumanPlayer is inherited from Player
		only method draw() is different from that of Player
		it gives the human player a choice among the cards to play.
**********************************************************************/

#include <iostream>

#include "HumanPlayer.h"
#include "Card.h"

using namespace std;

Card HumanPlayer::draw()
{
    cout << "You currently hold in your hand:" << endl;
    cout << "a) " << myCards[0] << endl;
    cout << "b) " << myCards[1] << endl;
    cout << "c) " << myCards[2] << endl;
    cout << "Which one do you want to play? ";

    char answer[80];
    removedCard = -1;
    while (removedCard == -1) {
        cin >> answer;
        if (answer[0] == 'a')
            removedCard = 0;
        else if (answer[0] == 'b')
            removedCard = 1;
        else if (answer[0] == 'c')
            removedCard = 2;
        if (removedCard != -1)
            return myCards[removedCard];
        cout << "Please specify a, b, or c\n";
    }
} // draw

/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-5-12
 Filename: Game.cpp
 Description: This is the main program for the game.  Creates the deck and player
              objects and then loops until the deck is empty.  Calls functions 
              mainily from the player class to play the game.  After out of cards,
              checks if the player is a winner or not.
 *******************************************************************************/

#include <iostream>
#include "Deck.h"
#include "Player.h"

int main()
{
    Deck theDeck;
    theDeck.shuffle();
    Player player1;
    int choice = 0;

    while (!theDeck.isEmpty()) {
        
        player1.draw(theDeck);
        choice = player1.play();
        
        while (choice != 0) {
            
            if (player1.selectedCard(choice).getRank() == 14) {
                player1.moveAce();
            }
            else {
                player1.compare();
            }
            choice = player1.play();
        }
    }
    
    int winner = 0;
    
    for (int i = 1; i < 5; i++) {
        if (player1.selectedCard(i).getRank() == 14)
            winner++;
    }
    
    if (winner == 4) {
        cout << "\nYou are a winner!!!!\n\n";
    }
    else {
        cout << "\nYou are out of cards and didn't win\n\n";
    }
} // main


/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-5-12
 Filename: Player.cpp
 Description: This class file started at with the one from the war program
              but was modified to fit the solitaire game vs war.  A couple of 
              functions were deleted and added.  A vector of vector's with cards
              in them stores the playing table.   
 *******************************************************************************/

#include <vector>
#include <iostream>
#include "Player.h"
#include "Random.h"
#include "Card.h"

extern Random randomizer;

/**************************************************************************
 Function Name: Player()
 Description: Default constructor that sets variables and 4 columns
 **************************************************************************/

Player::Player() {
    column.resize(4);
    removedCard = 0;
}

/**************************************************************************
 Function Name: draw(Deck & aDeck)
 Description: draws four cards and places them at the end of each column
 **************************************************************************/

void Player::draw(Deck &aDeck) {
    for (int i = 0; i < 4; i++) 
        column[i].push_back(aDeck.draw());
} // draw()

/**************************************************************************
 Function Name: play()
 Description: Uses display() to show card configuration, allows user to input
              column choice, checks if valid choice.  Return column choice
              if not 1-4 selected.  Returns 0 if 0 selected.
 **************************************************************************/

int Player::play() {
    display();
    char answer[80];
    cout << "Enter a column number (0 to draw four new cards): ";
    cin >> answer;
    bool ValidChoice = false;
    
    while (!ValidChoice) {
        
        removedCard = choiceNum(answer[0]);
        
        if (removedCard >= 0 && removedCard <= 4) {
            if (removedCard == 0)
                return 0;
    
            if (!column[removedCard - 1].empty()) {
                ValidChoice = true;
                continue;
            }
        }
        cout << "Invalid Choice: ";
        cin >> answer;
    }
    return removedCard--;
} // play()

/**************************************************************************
 Function Name: moveAce()
 Description: If ace can be moved, prompts user to select column to move to.
              If ace can't be moved anywhere, informs user that.
 **************************************************************************/

void Player::moveAce() {
    bool canMoveAce = false;
    
    for (int i = 0; i < 4; i++) { // check if ace can be moved anywhere
        if (i != removedCard) {
            if (column[i].back().getRank() == 14 || column[i].empty()) {
                canMoveAce = true;
                break;
            }
        }
    }
    
    if (canMoveAce) {
        char answer[80];
        int choice;
        cout << "Ace to where?: ";
        cin >> answer;
        bool ValidChoice = false;
        
        while (!ValidChoice) {
            choice = choiceNum(answer[0]);
            
            if (choice > 0 && choice < 5) 
                if (column[choice - 1].back().getRank() == 14 || column[choice - 1].empty()) {
                    column[choice - 1].push_back(column[removedCard].back());
                    column[removedCard].pop_back(); 
                    ValidChoice = true;
                    continue;
                }
            
            cout << "Invalid Choice: ";
            cin >> answer;    
        }   
    }
    else
        cout << "\nYou can't move the ace anywhere\n";
} // moveAce()

/**************************************************************************
 Function Name: compare()
 Description: Checks if selected card is same suit and smaller than other
              cards.  If so, it removes the card from the vector.
 **************************************************************************/

void Player::compare() {
    for (int i = 0; i < 4; i++) {
        if (column[removedCard].back().getRank() < column[i].back().getRank()) 
            if (column[removedCard].back().getSuit() == column[i].back().getSuit()) {
                column[removedCard].pop_back();
                break;
            }
        } 
} // compare()

/**************************************************************************
 Function Name: selectedCard(int i)
 Description: Returns Card object at parameter position.  If empty, returns
              empty Card object.
 **************************************************************************/

Card Player::selectedCard(int i) {
    if (column[i - 1].empty())
        return Card();
    
    return column[i - 1].back(); 
} // selectedCard()

/**************************************************************************
 Function Name: choiceNum(cosnt char & c)
 Description: converts char input by user into acceptable values
 **************************************************************************/

int Player::choiceNum(const char & c) {
    switch (c) {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        default:
            return -1;
            break;
    }
} // choiceNum()

/**************************************************************************
 Function Name: display()
 Description: Displays the configuration of the cards
 **************************************************************************/

void Player::display() {
    cout << endl;
    
    int allDisplayed = 0;
    
    for (int i = 0; i < 4; i++) {
        cout << "Column " << i + 1 << "\t";
    }
    
    cout << endl;
    
    for (int i = 0; allDisplayed < 4; i++) { // rows
        allDisplayed = 0;
        for (int j = 0; j < 4; j++) { // columns
            if (column[j].size() > i) {
                cout << column[j][i] << "\t";
            }
            else {
                ++allDisplayed;
                cout << "                ";
            }
        }
        cout << endl;
    }
} // display()


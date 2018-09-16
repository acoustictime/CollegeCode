/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-5-12
 Filename: Player.h
 Description: This class header file started at with the one from the war program
              but was modified to fit the solitaire game vs war.  A couple of 
              functions were deleted and added.  A vector of vector's with cards
              in them stores the playing table.   
 *******************************************************************************/

#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Player {
private:
    vector<vector<Card> > column;
    int removedCard;
public:
    Player();
    void draw(Deck & aDeck);
    int play();
    void moveAce();
    void compare();
    Card selectedCard(int i);
    int choiceNum(const char & c);
    void display();
};

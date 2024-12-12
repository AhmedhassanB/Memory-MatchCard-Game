
#ifndef MEMORY_MATCHCARD_GAME_DECK_H
#define MEMORY_MATCHCARD_GAME_DECK_H
#include "Card.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Deck{
private:

    // Card** cards;
    // int size;
    Card** grid;
    Card**deck;

public:
    Deck();
    Deck(Card ** grid,Card*deck);
    ~Deck();
    void shuffle();
    void displayGrid();
    void resetGrid();
    void removeCard(int row, int col);
    void flipCard(int row, int col, bool faceUp);
    Card *getCard(int row, int col);
};

#endif

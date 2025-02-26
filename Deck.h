#ifndef MEMORY_MATCHCARD_GAME_DECK_H
#define MEMORY_MATCHCARD_GAME_DECK_H
#include "Card.h"
#include <ctime>
using namespace std;
class Deck{
    Card** grid;
    Card**deck;

public:
    Deck();
    Deck(Card ** grid,Card*deck);
    ~Deck();
    void shuffle();
    void displayGrid();
    void displayAllFaceUp();
    void flipCard(int row, int col, bool faceUp);
    Card *getCard(int row, int col);

    void removeoneCard(int row, int col);

    bool allCardsFlipped();

    void removeCards(Card *c1 , Card *c2);
};

#endif

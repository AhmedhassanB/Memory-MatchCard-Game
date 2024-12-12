
#ifndef MEMORY_MATCHCARD_GAME_GAME_H
#define MEMORY_MATCHCARD_GAME_GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;
class Game {
public:
    Game();  // Add this constructor declaration
    ~Game();
    void initializeGame();
    void playTurn();
    void displayScores();
    void start();

private:
    Deck deck;
    Player player1;
    Player player2;
    int currentPlayer = 1;
};


#endif //MEMORY_MATCHCARD_GAME_GAME_H

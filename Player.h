#ifndef MEMORY_MATCHCARD_GAME_PLAYER_H
#define MEMORY_MATCHCARD_GAME_PLAYER_H

#include <string>
using namespace std;
class Player {

    string name;
    int score;

public:
    Player();
    Player( string &name, int score);
    ~Player();

    void setName( string &name);
    void setScore(int score);
    string getName() ;
    int getScore() ;
    void displayScore() ;

    void addScore(int points);
    void deduceScore(int points);
};

#endif //MEMORY_MATCHCARD_GAME_PLAYER_H





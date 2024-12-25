#ifndef MEMORY_MATCHCARD_GAME_BONUSCARD_H
#define MEMORY_MATCHCARD_GAME_BONUSCARD_H
#include <bits/stdc++.h>
#include "Card.h"
using namespace std;
class BonusCard: public  Card{
private:
    int bonusPoints;
public:

    BonusCard();
    BonusCard(int value,bool isFaceUp,int bonusPoints);
    ~BonusCard();
    void setBonusPoints(int points);
    int getBonusPoints();
    void display() override;
};

#endif

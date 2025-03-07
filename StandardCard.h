//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_STANDARDCARD_H
#define MEMORY_MATCHCARD_GAME_STANDARDCARD_H

#include <bits/stdc++.h>
#include "Card.h"
#include "StandardCard.h"
using namespace std;
class StandardCard:public Card{
public:
    StandardCard();

    StandardCard(int value, bool isFaceUp);

    StandardCard(int value,bool isFaceUp, int bonusPoints);
    virtual  ~StandardCard();
    void display() override;
};


#endif //MEMORY_MATCHCARD_GAME_STANDARDCARD_H

//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_PENALTYCARD_H
#define MEMORY_MATCHCARD_GAME_PENALTYCARD_H
#include <bits/stdc++.h>
#include "Card.h"
using namespace std;
class PenaltyCard:Card{

private:
    int penaltyPoints;
public:
    PenaltyCard();
    PenaltyCard(int penaltyPoints);
    ~PenaltyCard();
    void display();



};
#endif //MEMORY_MATCHCARD_GAME_PENALTYCARD_H

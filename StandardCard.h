//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_STANDARDCARD_H
#define MEMORY_MATCHCARD_GAME_STANDARDCARD_H

#include <bits/stdc++.h>
#include "Card.h"
using namespace std;
class StandardCard:public Card{
public:
    StandardCard();
    StandardCard(int value,bool isFaceUp);
   ~StandardCard();
   virtual  void display() ;
};

#endif //MEMORY_MATCHCARD_GAME_STANDARDCARD_H

//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_CARD_H
#define MEMORY_MATCHCARD_GAME_CARD_H
#include <bits/stdc++.h>
using namespace std;
class Card{
private:
    int value;
    bool isfaceUp;

public:
    Card();
    Card(int value,bool isfaceUp);
    ~Card();

    int getValue();
    void setValue();
    bool isFaceUp();


    void display();


};
#endif //MEMORY_MATCHCARD_GAME_CARD_H

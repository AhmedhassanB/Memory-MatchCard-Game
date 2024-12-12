// PenaltyCard.h
#ifndef PENALTYCARD_H
#define PENALTYCARD_H

#include "Card.h"

class PenaltyCard : public Card {

    int penaltyPoints;

public:
    PenaltyCard(int value, bool isFaceUp, int penaltyPoints);
    int getPenaltyPoints();
    void display() override;
};

#endif
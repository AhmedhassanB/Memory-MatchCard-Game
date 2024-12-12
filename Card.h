// Card.h
#ifndef CARD_H
#define CARD_H

class Card {
protected:
    int value;
    bool isFaceUp;

public:
    Card();
    Card(int value, bool isFaceUp);
    virtual ~Card();

    void setValue(int v);
    void setIsfaceUp(bool f);
    int getValue();
    bool getIsfaceUp();

    void reveal();
    void hide();
    virtual void display();
};

#endif

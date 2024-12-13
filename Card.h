#ifndef CARD_H
#define CARD_H
class Card {
public:
    int value;
    bool isFaceUp;

    Card();
    Card(int value, bool isFaceUp);
    virtual ~Card();
    void setValue(int v);
    void setIsfaceUp(bool f);
    int getValue();
    bool getIsfaceUp();
    virtual void display();

    void reveal() { isFaceUp = true; }
    void hide() { isFaceUp = false; }
    bool getIsFaceUp() const { return isFaceUp; }
    int getValue() const { return value; }


    Card &operator=(nullptr_t null);

    bool operator!=(nullptr_t null) const;
};

#endif

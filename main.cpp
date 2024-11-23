#include <bits/stdc++.h>
using namespace std;

#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Player.h"
#include "Deck.h"
#include "Game.h"

Card::Card() : value(0), isFaceUp(false) {

}
Card::Card(int value, bool isFaceUp) : value(value), isFaceUp(isFaceUp) {

}
Card::~Card() {

}

void Card:: setValue(int v) { value = v; }
void Card:: setIsfaceUp(bool f) { isFaceUp = f; }
int Card::getValue() { return value; }
bool Card::getIsfaceUp() { return isFaceUp; }
void Card::display() {
if (isFaceUp) {
    cout<< value;
}
    else{
        cout<< '*';
    }
}

// StandardCard

StandardCard::StandardCard() : Card() {}

StandardCard::StandardCard(int value, bool isFaceUp) : Card(value, isFaceUp) {}

StandardCard::~StandardCard() {}
void StandardCard::display() {
    Card::display();
}

// BonusCard Implementation
BonusCard::BonusCard() : Card(), bonusPoints(0) {}
BonusCard::BonusCard(int value,bool isFaceUp,  int  bonusPoints) : Card(value,isFaceUp), bonusPoints( bonusPoints ) {}

BonusCard::~BonusCard() {}

void BonusCard::setBonusPoints(int points) { bonusPoints = points; }
int BonusCard::getBonusPoints() { return bonusPoints; }
// BonusCard display method
void BonusCard::display() {
    if (getIsfaceUp()) {
        std::cout << "B" << getValue() << "(+" << bonusPoints << ")";
    } else {
        std::cout << "*";
    }
}

PenaltyCard::PenaltyCard() : Card(), penaltyPoints(0) {}

// PenaltyCard constructor
PenaltyCard::PenaltyCard(int value, bool isFaceUp, int penaltyPoints)
    : Card(value, isFaceUp), penaltyPoints(penaltyPoints) {}

PenaltyCard::~PenaltyCard() {}
void PenaltyCard::setPenaltyPoints(int points) { penaltyPoints = points; }
int PenaltyCard::getPenaltyPoints() { return penaltyPoints; }


// PenaltyCard display method
void PenaltyCard::display() {
    if (getIsfaceUp()) {
        std::cout << "P" << getValue() << "(-" << penaltyPoints << ")";
    } else {
        std::cout << "*";
    }
}

Player::Player() : name("Player"), score(0) {}
Player::Player(string Pname,int s) : name(Pname), score(s) {}
Player::~Player() {}
void Player::setName(string Pname) { name = Pname; }
void Player::setScore(int s) { score = s; }
string Player::getName() { return name; }
int Player::getScore() { return score; }
void Player::displayScore() { cout << "Player: " <<name << "Score: " << score << endl; }
void Player::addScore(int points) { score += points; }
void Player::deduceScore(int points) { score -= points; }

// Deck Implementation
// Deck constructor
Deck::Deck() {
    grid = new Card*[4];
    for (int i = 0; i < 4; i++) {
        grid[i] = new Card[4];
    }
    deck = new Card*[16];
    for (int i = 0; i < 16; i++) {
        if (i < 12) {
            deck[i] = new StandardCard((i % 6) + 1, false);
        } else if (i == 12 || i == 13) {
            deck[i] = new BonusCard((i % 6) + 1, false, 2);
        } else {
            deck[i] = new PenaltyCard((i % 6) + 1, false, 2);
        }
    }

    // Initialize the grid with the deck cards
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = *deck[index++];
        }
    }
}


Deck::~Deck() {
    for (int i = 0; i < 4; i++) delete
    grid[i];
    delete[] deck;
}

void Deck::shuffle() {
    srand(static_cast<unsigned>(time(0)));

    // Flatten the grid into a 1D array
    Card temp[16];
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[index++] = grid[i][j];
        }
    }

    // Shuffle the 1D array
    for (int i = 15; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tempCard = temp[i];
        temp[i] = temp[j];
        temp[j] = tempCard;
    }

    // Place shuffled cards back into the grid
    index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = temp[index++];
        }
    }
}

void Deck::displayGrid() {
    std::cout << "-----------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "|";  // Left border for each row
        for (int j = 0; j < 4; j++) {
            if (grid[i][j].getIsfaceUp()) {
                std::cout << " " << grid[i][j].getValue() << " ";
            } else {

                std::cout << " * ";
            }
            std::cout << "|";
        }
        std::cout << std::endl;
        std::cout << "-----------------" << std::endl;
    }
}



void Deck::flipCard(int row, int col, bool IsfaceUp ) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4 ) {
        grid[row][col].setIsfaceUp(IsfaceUp);
    }

}

Card *Deck::getCard(int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        return &grid[row][col];
    }
    return nullptr;
}


// Default Constructor


// Destructor
Game::~Game() {}

// Initialize the game
void Game::initializeGame() {
    std::cout << "Welcome to the 2D Card Matching Game!" << std::endl;

    std::cout << "Shuffling cards..." << std::endl;
    deck.shuffle();

    std::cout << "\nInitial Card Grid:" << std::endl;
    deck.displayGrid();
}

void Game::playTurn() {
    Player& current = (currentPlayer == 1) ? player1 : player2;

    std::cout << "\n" << current.getName() << "'s turn!" << std::endl;

    int row1, col1;
    int row2, col2;
    std::cout << "Enter row and column for the first card: ";
    std::cin >> row1 >> col1;
    std::cout << "Enter row and column for the second card: ";
    std::cin >> row2 >> col2;

    // Flip the first and second cards face-up
    deck.flipCard(row1, col1, true);
    deck.flipCard(row2, col2, true);
    deck.displayGrid();

    Card* card1 = deck.getCard(row1, col1);
    Card* card2 = deck.getCard(row2, col2);

    if (card1 && card2 && card1->getValue() == card2->getValue()) {
        std::cout << "It's a match!" << std::endl;

        // Handle special cards
        if (auto* bonusCard = dynamic_cast<BonusCard*>(card1)) {
            current.addScore(bonusCard->getBonusPoints());
            std::cout << "Bonus! +" << bonusCard->getBonusPoints() << " points." << std::endl;
        } else if (auto* penaltyCard = dynamic_cast<PenaltyCard*>(card1)) {
            current.deduceScore(penaltyCard->getPenaltyPoints());
            std::cout << "Penalty! -" << penaltyCard->getPenaltyPoints() << " points." << std::endl;
        } else {
            current.addScore(10);  // Standard card match, add 10 points
            std::cout << "Standard match! +10 points." << std::endl;
        }
    } else {
        std::cout << "Not a match!" << std::endl;

        // Flip the cards back face-down
        deck.flipCard(row1, col1, false);
        deck.flipCard(row2, col2, false);
    }

    // Display the grid after updating the face-up status
    deck.displayGrid();

    // Switch to the other player
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void Game::displayScores() {
    player1.displayScore();
    player2.displayScore();
}
// Game.cpp
Game::Game() : player1("Player 1", 0), player2("Player 2", 0) {
    // Initialize any other members if needed
}

void Game::start() {

    initializeGame();

    // Game loop: Continue until all cards are face up (matched)
    while (true) {
        playTurn();
        displayScores();

        // Check if all cards are face up
        bool allCardsFaceUp = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!deck.getCard(i, j)->getIsfaceUp()) {
                    allCardsFaceUp = false; // Found at least one card that is face down
                    break;
                }
            }
            if (!allCardsFaceUp) {
                break;
            }
        }

        if (allCardsFaceUp) {
            std::cout << "\nAll cards have been matched!" << std::endl;
            break; // Exit the game loop when all cards are matched
        }
    }

    // Display final scores and the winner
    std::cout << "\nGame Over!" << std::endl;
    displayScores(); // Display scores for both players
    if (player1.getScore() > player2.getScore()) {
        std::cout << player1.getName() << " wins!" << std::endl;
    } else if (player1.getScore() < player2.getScore()) {
        std::cout << player2.getName() << " wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}


int main() {

    Game game;
    game.start();

    return 0;
}


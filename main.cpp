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
        if (value != 7 && value != 8)
            std::cout << value;
        else if (value == 7) {
            dynamic_cast<BonusCard*>(this)->display();
        } else if (value == 8) {
            dynamic_cast<PenaltyCard*>(this)->display();
        }
    } else {
        std::cout << "*";
    }
}

StandardCard::StandardCard() : Card() {}
StandardCard::StandardCard(int value, bool isFaceUp) : Card(value, isFaceUp) {}
StandardCard::~StandardCard() {}
void StandardCard::display() {
    if (getIsFaceUp()) {
        std::cout << "StandardCard: " << getValue() << std::endl;
    } else {
        std::cout << "StandardCard: Face down" << std::endl;
    }
}

BonusCard::BonusCard() : Card(), bonusPoints(0) {}
BonusCard::BonusCard(int value,bool isFaceUp,  int  bonusPoints) : Card(value,isFaceUp), bonusPoints( bonusPoints ) {}

BonusCard::~BonusCard() {}

void BonusCard::setBonusPoints(int points) { bonusPoints ; }
int BonusCard::getBonusPoints() { return bonusPoints; }

void BonusCard::display() {
    if (getIsfaceUp()) {
        std::cout << "B" << getValue() << "(+" << bonusPoints << ")";
    } else {
        std::cout << "*";
    }
}




PenaltyCard::PenaltyCard(int value, bool isFaceUp, int penaltyPoints)
    : Card(value, isFaceUp), penaltyPoints(penaltyPoints) {}

PenaltyCard::~PenaltyCard() {}
void PenaltyCard::setPenaltyPoints(int points) { penaltyPoints; }
int PenaltyCard::getPenaltyPoints() { return penaltyPoints; }



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
void Player::displayScore() { cout << "Player: " <<name << " Score: " << score << endl; }
void Player::addScore(int points) { score += points; }
void Player::deduceScore(int points) { score -= points; }
Deck::Deck() {
    grid = new Card*[4];
    for (int i = 0; i < 4; i++) {
        grid[i] = new Card[4];
    }
    deck = new Card*[16];

    for (int i = 0; i < 16; i++) {
        if (i !=7&&i!=8) {
            deck[i] = new StandardCard((i % 6) + 1, false);
        }  if (i == 7) {
            deck[i] = new BonusCard(7, false, 2);
        }  if (i == 8){
            deck[i] = new PenaltyCard(8, false, 2);
        }
    }


    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = *deck[index++];
        }
    }
}
Card& Card::operator=(std::nullptr_t null) {
    value = 0;
    isFaceUp = false;
    return *this;
}
void Deck::removeCards(Card* c1, Card* c2) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (&grid[i][j] == c1 || &grid[i][j] == c2) {
                grid[i][j] = nullptr; // Set the matched card to nullptr
            }
        }
    }
}
bool Card::operator!=(std::nullptr_t null) const {
    return value != 0 || isFaceUp != false;
}

Deck::~Deck() {
    for (int i = 0; i < 4; i++) delete[] grid[i];
    delete[] grid;
    delete[] deck;
}

void Deck::shuffle() {
    srand(static_cast<unsigned>(time(0)));


    Card temp[16];
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[index++] = grid[i][j];
        }
    }


    for (int i = 15; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tempCard = temp[i];
        temp[i] = temp[j];
        temp[j] = tempCard;
    }


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
        std::cout << " | ";
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j].display();
            } else {
                std::cout << " "; // Display an empty space for removed cards
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
        std::cout << "-----------------" << std::endl;
    }
}



void Deck::flipCard(int row, int col, bool faceUp) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4 && grid[row][col] != nullptr) {
        if (faceUp) {
            grid[row][col].reveal();
        } else {
            grid[row][col].hide();
        }
    }
}

Card* Deck::getCard(int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        return &grid[row][col];
    }
    return nullptr;
}


Game::~Game() {
}
void Game::playTurn() {
    displayPlayerInfo(); // Display the current player's name and score
    Player& current = (currentPlayer == 1) ? player1 : player2;
    std::cout << "\n" << current.getName() << "'s turn!" << std::endl;
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// void Game::scoring() {
//     Player& current = (currentPlayer == 1) ? player1 : player2;
//     int row1, col1;
//     int row2, col2;
//
//     while (true) {
//         try {
//             std::cout << "Enter row and column for the first card: ";
//             std::cin >> row1 >> col1;
//             if (row1 < 1 || row1 > 4 || col1 < 1 || col1 > 4) {
//                 throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
//             }
//
//             std::cout << "Enter row and column for the second card: ";
//             std::cin >> row2 >> col2;
//             if (row2 < 1 || row2 > 4 || col2 < 1 || col2 > 4) {
//                 throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
//             }
//
//             Card* card1 = deck.getCard(row1 - 1, col1 - 1);
//             Card* card2 = deck.getCard(row2 - 1, col2 - 1);
//
//             if (card1 == nullptr || card2 == nullptr) {
//                 std::cout << "One or both of the selected cards have been removed. Please try again." << std::endl;
//                 continue;
//             }
//
//             if (card1->getIsfaceUp()) {
//                 std::cout << "The first card is already face up. Please try again." << std::endl;
//                 continue;
//             }
//
//             if (card2->getIsfaceUp()) {
//                 std::cout << "The second card is already face up. Please try again." << std::endl;
//                 continue;
//             }
//
//             if (row1 == row2 && col1 == col2) {
//                 std::cout << "You have selected the same card twice. Please try again." << std::endl;
//                 continue;
//             }
//
//             break; // Valid input, exit the loop
//         } catch (const std::out_of_range& e) {
//             std::cout << e.what() << std::endl;
//         } catch (const std::exception& e) {
//             std::cout << "An error occurred: " << e.what() << std::endl;
//         }
//     }
//
//     // Flip the first and second cards face-up
//     deck.flipCard(row1 - 1, col1 - 1, true);
//     deck.flipCard(row2 - 1, col2 - 1, true);
//     deck.displayGrid();
//
//     Card* card1 = deck.getCard(row1 - 1, col1 - 1);
//     Card* card2 = deck.getCard(row2 - 1, col2 - 1);
//
//     if (card1->getValue() == card2->getValue()) {
//         std::cout << "It's a match!" << std::endl;
//
//         if (dynamic_cast<BonusCard*>(card1) && dynamic_cast<BonusCard*>(card2)) {
//             int choice;
//             std::cout << "You have two bonus cards! Choose an option:\n1. +2 points\n2. +1 point and take another turn\n";
//             std::cin >> choice;
//             if (choice == 1) {
//                 current.addScore(2);
//                 std::cout << "Bonus! +2 points." << std::endl;
//             } else {
//                 current.addScore(1);
//                 std::cout << "Bonus! +1 point. Take another turn." << std::endl;
//                 playTurn();
//                 return;
//             }
//         } else if (dynamic_cast<PenaltyCard*>(card1) && dynamic_cast<PenaltyCard*>(card2)) {
//             int choice;
//             std::cout << "You have two penalty cards! Choose an option:\n1. Lose 2 points\n2. Lose 1 point and skip the next turn\n";
//             std::cin >> choice;
//             if (choice == 1) {
//                 current.deduceScore(2);
//                 std::cout << "Penalty! -2 points." << std::endl;
//             } else {
//                 current.deduceScore(1);
//                 std::cout << "Penalty! -1 point. Skip the next turn." << std::endl;
//                 currentPlayer = (currentPlayer == 1) ? 2 : 1;
//                 return;
//             }
//         } else if (dynamic_cast<BonusCard*>(card1) || dynamic_cast<BonusCard*>(card2)) {
//             current.addScore(1);
//             std::cout << "Bonus! +1 point." << std::endl;
//             deck.removeCards(dynamic_cast<BonusCard*>(card1) ? card1 : card2, nullptr);
//         } else if (dynamic_cast<PenaltyCard*>(card1) || dynamic_cast<PenaltyCard*>(card2)) {
//             current.deduceScore(1);
//             std::cout << "Penalty! -1 point." << std::endl;
//         } else {
//             current.addScore(1);  // Standard card match, add 1 point
//             std::cout << "Standard match! +1 point." << std::endl;
//         }
//         deck.flipCard(row1 - 1, col1 - 1, true);
//         deck.flipCard(row2 - 1, col2 - 1, true);
//         deck.removeCards(card1, card2);
//     } else {
//         std::cout << "Not a match!" << std::endl;
//
//         // Flip the cards back face-down
//         deck.flipCard(row1 - 1, col1 - 1, false);
//         deck.flipCard(row2 - 1, col2 - 1, false);
//     }
//     deck.displayGrid();
//     playTurn();
// }
void Game::scoring() {
    Player& current = (currentPlayer == 1) ? player1 : player2;
    int row1, col1;
    int row2, col2;

    while (true) {
        try {
            std::cout << "Enter row and column for the first card: ";
            std::cin >> row1 >> col1;
            if (row1 < 1 || row1 > 4 || col1 < 1 || col1 > 4) {
                throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
            }

            std::cout << "Enter row and column for the second card: ";
            std::cin >> row2 >> col2;
            if (row2 < 1 || row2 > 4 || col2 < 1 || col2 > 4) {
                throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
            }

            Card* card1 = deck.getCard(row1 - 1, col1 - 1);
            Card* card2 = deck.getCard(row2 - 1, col2 - 1);

            if (card1 == nullptr || card2 == nullptr) {
                std::cout << "One or both of the selected cards have been removed. Please try again." << std::endl;
                continue;
            }

            if (card1->getIsFaceUp()) {
                std::cout << "The first card is already face up. Please try again." << std::endl;
                continue;
            }

            if (card2->getIsFaceUp()) {
                std::cout << "The second card is already face up. Please try again." << std::endl;
                continue;
            }

            if (row1 == row2 && col1 == col2) {
                std::cout << "You have selected the same card twice. Please try again." << std::endl;
                continue;
            }

            break; // Valid input, exit the loop
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "An error occurred: " << e.what() << std::endl;
        }
    }

    // Flip the first and second cards face-up
    deck.flipCard(row1 - 1, col1 - 1, true);
    deck.flipCard(row2 - 1, col2 - 1, true);
    deck.displayGrid();

    Card* card1 = deck.getCard(row1 - 1, col1 - 1);
    Card* card2 = deck.getCard(row2 - 1, col2 - 1);

    if (card1->getValue() == card2->getValue()) {
        std::cout << "It's a match!" << std::endl;
        current.addScore(1);  // Standard card match, add 1 point
    } else {
        std::cout << "Not a match!" << std::endl;
    }

    // Prompt the current player to press Enter to hide the cards again
    std::cout << "Press Enter to hide the cards and switch turns...";
    std::cin.ignore();
    std::cin.get();

    // Flip the cards back face-down
    deck.flipCard(row1 - 1, col1 - 1, false);
    deck.flipCard(row2 - 1, col2 - 1, false);
    deck.displayGrid();

    // Switch turns between the two players
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}



void Game::initializeGame() {
    std::cout << "Welcome to the 2D Card Matching Game!" << std::endl;

    std::cout << "Shuffling cards..." << std::endl;
    deck.shuffle();

    std::cout << "\nInitial Card Grid:" << std::endl;
    deck.displayGrid();

}


void Game::displayScores() {
    player1.displayScore();
    player2.displayScore();
}

Game::Game() {
   string x,y;
    cout<<"Enter the name of the first player: ";
    cin>>x;
    player1.setName(x);
    player1.setScore(0);
    cout<<"Enter the name of the second player: ";
    cin>>y;
    player2.setName(y);
    player2.setScore(0);
}
bool Deck::allCardsFlipped() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!grid[i][j].getIsfaceUp()) {
                return false;
            }
        }
    }
    return true;
}
void Game::start() {
    initializeGame();
    while (true) {
        displayScores();
        scoring();
        if (deck.allCardsFlipped()) {
            break;
        }
    }
        displayScores();
        if (player1.getScore() > player2.getScore()) {
            std::cout << player1.getName() << " wins!" << std::endl;
        } else if (player1.getScore() < player2.getScore()) {
            std::cout << player2.getName() << " wins!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }

    }

void Game::displayPlayerInfo() {
    std::cout << "Player 1: " << player1.getName() << " - Score: " << player1.getScore() << std::endl;
    std::cout << "Player 2: " << player2.getName() << " - Score: " << player2.getScore() << std::endl;
    std::cout << "Current turn: " << (currentPlayer == 1 ? player1.getName() : player2.getName()) << std::endl;
}




int main() {

    Game game;
    game.start();
    return 0;
}


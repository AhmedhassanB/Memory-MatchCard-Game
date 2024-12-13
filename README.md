Memory-MatchCard-Game
The Memory Match Card Game is a console-based, turn-based game developed as part of the Programming III - Winter Semester 2024/2025 course at the German International University. Players take turns revealing cards from a grid to match pairs and score points. The game includes special card rules, turn-based logic, and dynamic scoring mechanics.
Features
Turn-Based Gameplay: Two players take alternating turns revealing cards.
Special Card Rules:
Bonus Card: Provides scoring opportunities and additional turns.
Penalty Card: Deducts points or skips turns.
Dynamic Scoring: Points are awarded or deducted based on the type and match of revealed cards.
Interactive Console Output: The game visually updates the grid and displays player scores.
Endgame Conditions: Determines the winner based on the highest score or announces a tie.
Gameplay
General Flow
Grid Visualization: The grid is displayed with all cards hidden (*).
Player Information: Displays player names and scores, indicating whose turn it is.
Player Move:
Players input the coordinates of two cards to reveal.
The selected cards are flipped, and any score updates are applied.
Turn Switching:
Players press Enter to proceed after their turn.
The grid hides unmatched cards, and the next player takes their turn.
Game End:
The game ends when all pairs of cards are matched and removed.
Scores are compared, and the winner is announced (or a tie is declared).
Scoring Rules
Standard Cards:
Match: +1 point, player takes another turn, and matched cards are removed.
No Match: Cards are flipped back, and the turn changes.
Bonus Cards (7):
One Bonus Card:
+1 point, Bonus Card is removed, and the standard card is hidden.
Two Bonus Cards:
Player chooses between:
+2 points, or
+1 point and an additional turn.
Both cards are removed.
Penalty Cards (8):
One Penalty Card:
-1 point, no further effects.
Two Penalty Cards:
Player chooses between:
-2 points, or
-1 point and skipping the next turn.
Both cards are removed.
Bonus & Penalty Combination:
Both cards are removed with no effect on the score.
Class Structure
1. Card Class and Subclasses
StandardCard, BonusCard, PenaltyCard:
Methods: reveal(), hide(), display().
Implements specific scoring and behavior for each card type.
2. Player Class
Manages player information: name, score.
Methods to update scores based on card effects.
3. Deck Class
Responsible for:
Initializing and shuffling the grid.
Displaying and updating the grid state.
Removing matched or special cards as per rules.
4. Game Class
Implements game mechanics:
Alternating turns.
Card flipping and scoring.
Special card effects.
Determining game end and winner.
Special Card Behaviors
Bonus Card: Rewards players with extra points or turns.
Penalty Card: Deducts points or forces players to skip turns.
Combination Rules: Neutralize each other's effects when paired.
Memory Management
The game dynamically allocates memory for cards and ensures proper cleanup after each game session.

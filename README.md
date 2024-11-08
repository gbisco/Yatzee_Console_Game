# Yatzee_Console_Game
This project is a console-based dice game where multiple players compete by rolling dice and scoring points across various categories, similar to Yahtzee. The goal is to calculate the total score for each player and determine the winner based on the highest score.

Features

Multiple Players: The game supports multiple players, allowing them to roll dice and accumulate points.
Score Categories: Players can score points in various categories, including "Aces", "Threes of a Kind", "Four of a Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", and "Chance".

Rolling Dice: Players roll 5 dice per round and choose which dice to keep.
Score Calculation: Points are calculated based on the category the player selects, and the best possible score is determined for each category.

Winner Determination: After all players finish, the game determines the winner based on the highest total score.

Getting Started
Prerequisites:
Make sure you have the following installed:

A C compiler (e.g., GCC)
Compilation and Running
To compile and run the project, follow these steps:

Clone the repository (if applicable):

bash
Copy code
git clone https://github.com/yourusername/dice-game.git
cd dice-game
Compile the code:

bash
Copy code
gcc -o dice_game main.c
Run the game:

bash
Copy code
./dice_game
Gameplay
Setting Up Players: You can specify the number of players at the beginning of the game.
Rolling Dice: Players roll five dice per round and are presented with the option to keep or re-roll specific dice.
Choosing Categories: After rolling, players can assign their dice results to one of the score categories (e.g., "Aces", "Threes of a Kind", etc.).
Score Calculation: After each player’s turn, the score for the selected category is calculated based on the dice rolled.
Winner: After all players have completed their turns, the game calculates the total score for each player and determines the winner with the highest score.
Code Structure
main.c: Contains the main function to run the game, handle user input, and call various game functions.
score.c: Handles score calculations, including checking if a player can score in a given category and calculating their score.
player.c: Defines the Player structure and associated functions for managing player data (name, score card, dice rolls).
utils.c: Contains utility functions, such as rolling dice and updating the player's score card.
Functions Overview
determine_winner(Player* players, int num_players): Calculates the total score for each player and determines the winner.
print_score_card(Player* player): Displays the score card for a player.
calculate_score(int dice[], Category category): Calculates the score for a given set of dice based on the selected category.
roll_dice(Player* player): Rolls the dice for a player and updates their dice array.
update_keep(Player* player): Updates the dice a player wishes to keep for the next roll.
Contributing
If you’d like to contribute to this project, please fork the repository, make your changes, and submit a pull request. We welcome bug fixes, feature improvements, and general contributions to improve the project.

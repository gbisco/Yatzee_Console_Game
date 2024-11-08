# Yahtzee Game Project

This project is a console-based Yahtzee game where multiple players compete by rolling dice and scoring points across various categories. The goal is to calculate the total score for each player and determine the winner based on the highest score.

## Features

- **Multiple Players**: The game supports multiple players, allowing them to roll dice and accumulate points.
- **Score Categories**: Players can score points in various categories, including "Aces", "Threes of a Kind", "Four of a Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", and "Chance".
- **Rolling Dice**: Players roll 5 dice per round and choose which dice to keep.
- **Score Calculation**: Points are calculated based on the category the player selects, and the best possible score is determined for each category.
- **Winner Determination**: After all players finish, the game determines the winner based on the highest total score.
- **Output File**: The game outputs the results, including player names, their scores, and the winner, to a file for record-keeping and review.

## Getting Started

### Prerequisites

Make sure you have the following installed:
- A C compiler (e.g., GCC)

### Compilation and Running

To compile and run the project, follow these steps:

1. Clone the repository (if applicable):
    ```bash
    git clone https://github.com/yourusername/yahtzee-game.git
    cd yahtzee-game
    ```

2. Compile the code:
    ```bash
    gcc -o yahtzee_game main.c
    ```

3. Run the game:
    ```bash
    ./yahtzee_game
    ```

4. The game will prompt for the number of players, and after gameplay, the results will be written to an output file.

## Gameplay

1. **Setting Up Players**: You can specify the number of players at the beginning of the game.
2. **Rolling Dice**: Players roll five dice per round and are presented with the option to keep or re-roll specific dice.
3. **Choosing Categories**: After rolling, players can assign their dice results to one of the score categories (e.g., "Aces", "Threes of a Kind", etc.).
4. **Score Calculation**: After each player’s turn, the score for the selected category is calculated based on the dice rolled.
5. **Winner**: After all players have completed their turns, the game calculates the total score for each player and determines the winner with the highest score.
6. **Output File**: After the winner is determined, the game will write the results to an output file, including player names, their scores, and the winner's name.

## Code Structure

- **main.c**: Contains the main function to run the game, handle user input, and call various game functions.
- **score.c**: Handles score calculations, including checking if a player can score in a given category and calculating their score.
- **player.c**: Defines the `Player` structure and associated functions for managing player data (name, score card, dice rolls).
- **utils.c**: Contains utility functions, such as rolling dice and updating the player's score card.

## Functions Overview

- `determine_winner(Player* players, int num_players)`: Calculates the total score for each player and determines the winner.
- `print_score_card(Player* player)`: Displays the score card for a player.
- `calculate_score(int dice[], Category category)`: Calculates the score for a given set of dice based on the selected category.
- `roll_dice(Player* player)`: Rolls the dice for a player and updates their dice array.
- `update_keep(Player* player)`: Updates the dice a player wishes to keep for the next roll.

## Contributing

This project is open for anyone to use, modify, and distribute. Feel free to fork the repository, make your changes, and submit a pull request. We welcome bug fixes, feature improvements, and general contributions to improve the project.

## License

This project is open for anyone to use, modify, and distribute. No specific license is required. Feel free to contribute, and enjoy the game!

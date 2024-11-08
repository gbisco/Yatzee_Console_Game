/*
Gabriel Bisco Reinato
CptS121 section 8
February 14th 2019
"Program designed to emulate Yahtzee game"
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// Global definitions
// Constant to define player name max size
#define NAME_LENGTH 50
// Constant to define the number of dice
#define NUM_DICE 5
// Define number of categories
#define NUM_SCORE_CATEGORIES 13
// Defining Maximum number of players 
#define PLAYER_MAX_COUNT 4

// Define enum for Yahtzee scoring categories
typedef enum {
    ACES = 1,       // Aces: sum of all 1s
    TWOS,           // Twos: sum of all 2s
    THREES,         // Threes: sum of all 3s
    FOURS,          // Fours: sum of all 4s
    FIVES,          // Fives: sum of all 5s
    SIXES,          // Sixes: sum of all 6s
    THREE_OF_A_KIND, // Three of a kind: sum of all dice
    FOUR_OF_A_KIND,  // Four of a kind: sum of all dice
    FULL_HOUSE,      // Full house: 3 of one kind, 2 of another (25 points)
    SMALL_STRAIGHT,  // Small straight: four consecutive numbers (30 points)
    LARGE_STRAIGHT,  // Large straight: five consecutive numbers (40 points)
    YAHTZEE,         // Yahtzee: five of the same die (50 points)
    CHANCE           // Chance: sum of all dice
} Category;

// Struct to hold player information
typedef struct {
    char name[NAME_LENGTH];      // Player's name
    int score_card[NUM_SCORE_CATEGORIES];          // Player's score card
    int dice[NUM_DICE];         // Array to hold dice values
    bool keep[NUM_DICE];        // Array to indicate which dice to keep
} Player;

// Functions related to user interface and mechanics of the game

/*
 * Function: print_game_rules
 * --------------------------
 * Displays the rules and objectives of the Yahtzee game to the player in the console window.
 */
void print_game_rules(void);

/*
 * Function: initialize_players
 * ----------------------------
 * Initializes an array of players for the Yahtzee game. All array parameters are initialize to 0
 *
 * Parameters:
 *   A pointer to the pointer of an array of Player structs.
 *   The number of players to initialize.
 */
void initialize_players(Player** players, int num_players);

/*
 * Function: roll_dice
 * ----------------------------
 * Rolls the dice for a player and updates the player's dice array.
 *
 * Parameters:
 *   Player *player: Pointer to the Player struct containing the player's information.
 */
void roll_dice(Player* player);

/*
 * Function: print_score_card
 * ----------------------------
 * Displays the player's name and score card.
 *
 * Parameters:
 *   Player *player: Pointer to the Player struct containing the player's information.
 */
void print_score_card(Player* player);

/*
 * Function: print_dice_roll
 * ----------------------------
 * Displays the player's dice combination
 *
 * Parameters:
 *   Player *player: Pointer to the Player struct containing the player's information.
 */
void print_dice_roll(Player* player);

/*
 * Function: check_score_assignment
 * ----------------------------
 * This function verifies whether the player's dice combination satisfies the conditions
 * for the selected scoring category.
 *
 * Parameters: 
 *  dice - An array of dice values.
 *  category - The category that the player is trying to score
 * 
 * Returns:
 *  bool value
 */
bool check_score_assignment(int dice[], Category category);

/*
 * Function: update_keep
 * ----------------------------
 * Displays the player's name and score card.
 *
 * Parameters:
 *   Player *player: Pointer to the Player struct containing the player's information.
 */
void update_keep(Player* player);

/*
 * Function: update_category
 * --------------------------
 * Updates the player's score card with the score for the selected category if the score assignment is valid.
 *
 * Parameters:
 *   Player *player: Pointer to the Player struct containing the player's information.
 *   Category category: The category that the player is trying to score.
 *   int score: The score to be assigned to the selected category.
 */
void update_category(Player* player, Category category, int score);

/*
 * Function: handle_player_turn
 * ----------------------------
 * This function manages the turn of a single player by rolling dice, selecting a scoring category,
 * and updating their score card.
 *
 * Parameters:
 *   Player* player: Pointer to the Player struct containing the player's information.
 *
 * Returns:
 *   void
 */
void take_turn(Player* player);

/*
 * Function: calculate_score
 * ----------------------------
 * Calculates the score for a given dice combination based on the selected category.
 *
 * Parameters:
 *   int dice[]: An array of integers representing the values of the dice rolled.
 *   Category category: The selected scoring category.
 *
 * Returns:
 *   int: The calculated score for the specified category.
 */
int calculate_score(int dice[], Category category);

/*
 * Function: determine_winner
 * --------------------------
 * Determines the winner of the game by calculating the total score for each player
 *
 * Parameters:
 *   players - An array of Player structs.
 *   num_players - The number of players in the game.
 *
 * Returns:
 *   void.
 */
void determine_winner(Player* players, int num_players);

/*
 * Function: save_scorecards_to_file
 * ----------------------------
 * This function outputs the players' card to a txt file
 *
 * Parameters:
 *   Player* player: Pointer to the Player struct containing the player's information.
 *   num_players variable with the number of players
 *
 * Returns:
 *   void
 */
void save_scorecards_to_file(Player* players, int num_players);


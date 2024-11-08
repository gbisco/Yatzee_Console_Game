/*
Gabriel Bisco Reinato
CptS121 section 8
February 14th 2019
"Program designed to emulate Yahtzee game"
*/
#include "Header.h"

// Prints game details
void print_game_rules(void) {
    // Initializing character input
    char input[10];// Input buffer

    // Display game rules input is not exit
    do {
        // Display welcome message
        printf("Welcome to Yahtzee!\n\n");

        // Display objective
        printf("OBJECTIVE:\n");
        printf("* The objective is to score points by rolling dice to make specific combinations.\n\n");

        // Display game rules
        printf("RULES:\n");
        printf("* The game consists of 13 rounds, in which each player gets 3 rolls of 5 dice.\n");
        printf("* After each roll, players can choose whether to keep playing and which dice to keep.\n");
        printf("* At the end of the turn, players will assign the dice combination to 1 of 13 scoring categories.\n");
        printf("* Each category is worth a certain amount of points.\n");
        printf("* Players that cannot assign their combination to a category are awarded 0 points.\n\n");

        // Display scoring system 
        printf("SCORING CATEGORIES:\n");
        printf("* Aces: Having at least one 1 dice (point value: the sum of all your 1s)\n");
        printf("* Twos: Having at least one 2 dice (point value: the sum of all your 2s)\n");
        printf("* Threes: Having at least one 3 dice (point value: the sum of all your 3s)\n");
        printf("* Fours: Having at least one 4 dice (point value: the sum of all your 4s)\n");
        printf("* Fives: Having at least one 5 dice (point value: the sum of all your 5s)\n");
        printf("* Sixes: Having at least one 6 dice (point value: the sum of all your 6s)\n");
        printf("* 3 of a kind: Three identical dice (point value: the sum of all your dice)\n");
        printf("* 4 of a kind: Four identical dice (point value: the sum of all your dice)\n");
        printf("* Full House: A pair of identical dice and a trio of identical dice (worth 25 points)\n");
        printf("* Small Straight: A 1, 2, 3, and 4; a 2, 3, 4, and 5; or a 3, 4, 5, and 6 (worth 30 points)\n");
        printf("* Large Straight: A 1, 2, 3, 4, and 5 or a 2, 3, 4, 5, and 6 (worth 40 points)\n");
        printf("* Yahtzee: Five identical dice (worth 50 points)\n");
        printf("* Chance: Any assortment of 5 dice (point value: the sum of all your dice)\n");

        //Display and get exit input
        printf("\nType 'e' to stop viewing the rules, or press Enter to view again: ");
        fgets(input, sizeof(input), stdin);// Get standard input size of local input variable
    } while (input[0] != 'e');
}

// Rolls specified number of dice and fills the array with random values between 1 and 6
void roll_dice(Player* player) {
    for (int i = 0; i < NUM_DICE; i++) {
        if (!player->keep[i]) { // Roll only the dice not marked to keep
            player->dice[i] = rand()%6 + 1; // Generate a random number between 1 and 6
        }
    }
}

// Function to initialize players
void initialize_players(Player** players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        // Initialize player name
        printf("\nEnter the name for player %d: ", i + 1);
        scanf("%s", (*players)[i].name);

        // Initialize score card to -1
        for (int j = 0; j < 13; j++) {
            (*players)[i].score_card[j] = -1;
        }

        // Initialize dice to 0
        for (int j = 0; j < 5; j++) {
            (*players)[i].dice[j] = 0;
        }

        // Initialize keep array to 0
        for (int j = 0; j < 5; j++) {
            (*players)[i].keep[j] = 0;
        }
    }
}

// Prints a player card
void print_score_card(Player* player) {

    // Print player's name and score card
    printf("Score Card for %s:\n", player->name);
    printf("---------------------------------------\n");
    printf("Category         | Score\n");
    printf("---------------------------------------\n");

    // Display score categories
    const char* categories[] = {
   "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes",
   "Three of a Kind", "Four of a Kind", "Full House",
   "Small Straight", "Large Straight", "Yahtzee", "Chance"
    };

    for (int i = 0; i < 13; i++) {
        printf("%-16s | %d\n", categories[i], player->score_card[i]);
    }
    printf("---------------------------------------\n");

    // Print dice combination
    printf("\nCurrent Dice Combination:\n");
    for (int i = 0; i < 5; i++) {
        printf("Die %d: %d\n", i + 1, player->dice[i]);
    }
    printf("---------------------------------------\n");
}

//checks if its a valid input category
bool check_score_assignment(int dice[], Category category) {
    // Array to hold the frequency of each number
    int num_count[7] = { 0 };

    // Count the frequency
    for (int i = 0; i < NUM_DICE; i++) {
        num_count[dice[i]]++;
    }

    // Change check depending on selected category
    switch (category) {
    case ACES:
        return num_count[1] > 0; // True if there's at least one '1'
    case TWOS:
        return num_count[2] > 0; // True if there's at least one '2'
    case THREES:
        return num_count[3] > 0; // True if there's at least one '3'
    case FOURS:
        return num_count[4] > 0; // True if there's at least one '4'
    case FIVES:
        return num_count[5] > 0; // True if there's at least one '5'
    case SIXES:
        return num_count[6] > 0; // True if there's at least one '6'
    case THREE_OF_A_KIND:
        // Check frequency array
        for (int i = 1; i <= 6; i++) {
            if (num_count[i] >= 3) {
                return 1; // True if there's at least three of the same die
            }
        }
        return 0; // Invalid if no die has a count of at least 3
    case FOUR_OF_A_KIND:
        // Check frequency array
        for (int i = 1; i <= 6; i++) {
            if (num_count[i] >= 4) {
                return 1; // Valid if there's at least four of the same die
            }
        }
        return 0; // Invalid if no die has a count of at least 4
    case FULL_HOUSE: {
        // valid for any 3 - 2 frequency combination
        bool has_three = false;
        bool has_two = false;
        for (int k = 1; k <= 6; k++) {
            if (num_count[k] == 3) {
                has_three = true;
                break;
            }
        }

        for (int k = 1; k <= 6; k++) {
            if (num_count[k] == 2) {
                has_two = true;
            }
        }
        return (has_two && has_three);
    }
    case SMALL_STRAIGHT:
        // 3 possible cases
        return (num_count[1] && num_count[2] && num_count[3] && num_count[4]) || // 1,2,3,4
            (num_count[2] && num_count[3] && num_count[4] && num_count[5]) || // 2,3,4,5
            (num_count[3] && num_count[4] && num_count[5] && num_count[6]);   // 3,4,5,6
    case LARGE_STRAIGHT:
        // 2 possible cases 
        return ((num_count[1] && num_count[2] && num_count[3] && num_count[4] && num_count[5]) || // 1,2,3,4,5
            (num_count[2] && num_count[3] && num_count[4] && num_count[5] && num_count[6]));   // 2,3,4,5,6
    case YAHTZEE: {
        for (int i = 1; i <= 6; i++) {
            if (num_count[i] == 5) {
                return true;  // Valid if all five dice are the same
            }
        }
        return false;  // Explicit return if no Yahtzee found
    }
    case CHANCE:
        return 1; // Always valid as chance can take any combination
    default:
        return 0; // Invalid if category is not recognized
    }
}

// Function to update the 'keep' array after player rolls dice
void update_keep(Player* player) {
    // reset keep
    for (int j = 0; j < NUM_DICE; j++) {
        player->keep[j] = 0;
    }
    // Loop through each die and ask if the player wants to keep it
    for (int i = 0; i < NUM_DICE; i++) {
        char input;

        // Display current dice roll and ask the player if they want to keep it
        printf("\nDie %d: %d. Do you want to keep this die? (y for yes): ", i + 1, player->dice[i]);
        scanf(" %c", &input);  // Space before %c to avoid issues with leftover newline character

        // Update the keep array based on player's choice
        if (input == 'y' || input == 'Y') {
            player->keep[i] = 1;  // Keep
        }
        else {
            player->keep[i] = 0;  // Don't keep
        }
    }
}

// Function to update category score
void update_category(Player* player, Category cat, int score) {
    const char* category_names[] = {
    "Aces", "Twos", "Threes", "Fours", "Fives", "Sixes",
    "Three of a Kind", "Four of a Kind", "Full House",
    "Small Straight", "Large Straight", "Yahtzee", "Chance"
    };

    player->score_card[cat] = score;  // Assign the calculated score to the category
    printf("\nCategory % s assigned % d points.\n", category_names[cat], player->score_card[cat]);
}

// Function to print dice combination
void print_dice_roll(Player* player) {

    // Print the dice combination
    printf("\nCurrent Dice Combination: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", player->dice[i]);
    }
    printf("\n");

}

// Function for a single player turn
void take_turn(Player* player) {

    // Initializing integers to hold roll count and selected category
    int roll_count = 0;
    int valid_category_selected = 0;
    const char* categories[] = {
   "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes",
   "Three of a Kind", "Four of a Kind", "Full House",
   "Small Straight", "Large Straight", "Yahtzee", "Chance"
    };

    // player selected category
    Category selected_category;

    // Show the player's score card and current dice roll at the start of the turn
    print_score_card(player);


    // reset keep between rounds
    for (int j = 0; j < NUM_DICE; j++) {
        player->keep[j] = 0;
    }

    // Loop throught 3 rolls
    while (roll_count < 3) {
        printf("\nRolling dice... (Roll %d of 3)\n", roll_count + 1);
        roll_dice(player);  // Roll the dice for the player

        // Print dice combination
        print_dice_roll(player);

        if (roll_count != 2) {
            // Ask the player which dice they want to keep
            update_keep(player);
        }

        if (roll_count < 1) {
            // Ask if the player wants to roll again
            printf("\nDo you want to roll again (1 for yes, 0 for no)? ");
            int roll_again;
            scanf("%d", &roll_again);

            // Case player wants to stop
            if (!roll_again) {
                system("cls");
                break;  // Stop rolling if the player doesn't want to roll again
            }
        }

        roll_count++;
    }

    system("cls");

    // Show the player's score card and current dice roll
    print_score_card(player);

    // Ask the player to choose a category to assign their dice combination to
    while (!valid_category_selected) {
        printf("\nAvailable categories to score (-1 means unfilled):\n");

        // Loop through available categories and check which ones are not filled
        for (int i = 0; i < NUM_SCORE_CATEGORIES; i++) {
            if (player->score_card[i] == -1) {  // Only show unfilled categories
                printf("%d. %s\n", i + 1, categories[i]);  // Display the category
                valid_category_selected = 1;  // A valid category is available
            }
        }
        printf("\nDo you want to skip your turn? (1 for Yes, 0 for No): ");
        int skip_turn;
        scanf("%d", &skip_turn);

        if (skip_turn == 1) {
            printf("You skipped your turn.\n");
            valid_category_selected = true;  // Exit the loop, as the player chose to skip
            break;  // Skip turn
        }
        else {


            // prompt the player to select one
            printf("\nSelect a category (1-13) to assign your score: ");
            int category_choice;
            scanf("%d", &category_choice);

            // Check if the selected category has not been filled
            if (category_choice >= 1 && category_choice <= NUM_SCORE_CATEGORIES && player->score_card[category_choice - 1] == -1) {
                // Map to the Category enum
                selected_category = (Category)(category_choice - 1);

                // Check if it is a valid category 
                if (check_score_assignment(player->dice, (Category)(category_choice))) {
                    // Assign the score to the selected category using the new update_category function
                    int score = calculate_score(player->dice, (Category)(category_choice));
                    update_category(player, selected_category, score);
                    valid_category_selected = true;  // Valid score assigned flag
                }
                else {
                    printf("Invalid dice combination for the selected category.\n");
                }
            }
            else {
                printf("Invalid category selection. Try again.\n");
            }
        }
    }

    // Print the updated score card after the turn
    print_score_card(player);
    printf("\n");
    system("pause");
}

// Function to calculate score that will be mapped to the score card
int calculate_score(int dice[], Category category) {
    int score = 0;
    int counts[7] = { 0 };  // Array to store the count of each die face (1-6)

    // Count occurrences of each die value
    for (int i = 0; i < NUM_DICE; i++) {
        counts[dice[i]]++;
    }

    switch (category) {
    case ACES:
        score = counts[1] * 1;
        break;
    case TWOS:
        score = counts[2] * 2;
        break;
    case THREES:
        score = counts[3] * 3;
        break;
    case FOURS:
        score = counts[4] * 4;
        break;
    case FIVES:
        score = counts[5] * 5;
        break;
    case SIXES:
        score = counts[6] * 6;
        break;
    case THREE_OF_A_KIND:
        for (int i = 1; i <= 6; i++) {
            if (counts[i] >= 3) {
                for (int j = 0; j < NUM_DICE; j++) {
                    score += dice[j];
                }
                break;
            }
        }
        break;
    case FOUR_OF_A_KIND:{
        for (int i = 1; i <= 6; i++) {
            if (counts[i] >= 4) {
                    score = counts[i]*i;
                break;
            }
        }
        break;
    }
        break;
    case FULL_HOUSE:
        score = 25;
        break;
    case SMALL_STRAIGHT:
        score = 30;
        break;
    case LARGE_STRAIGHT:
        score = 40;
        break;
    case YAHTZEE:
        score = 50;
        break;
    case CHANCE:
        for (int i = 0; i < NUM_DICE; i++) {
            score += dice[i];
        }
        break;
    default:
        printf("Invalid category\n");
        break;
    }

    return score;
}

void determine_winner(Player* players, int num_players) {
    int max_score = 0;
    int winner_index = 0;

    // Loop through each player to calculate their total score
    for (int i = 0; i < num_players; i++) {
        int total_score = 0;

        // Sum all the scores in the player's score card
        for (int j = 0; j < NUM_SCORE_CATEGORIES; j++) {
            if (players[i].score_card[j] != -1) {  // Make sure the category has been filled
                total_score += players[i].score_card[j];
            }
        }

        // Update max_score and winner_index if this player has a higher score
        if (total_score > max_score) {
            max_score = total_score;
            winner_index = i;
        }
    }

    // Print winner details
    printf("\nThe winner is %s ! with a score of %d!\n", players[winner_index].name, max_score);
}

// Function to save player scorecards to a text file
void save_scorecards_to_file(Player* players, int num_players) {
    FILE* file = fopen("scorecards.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    const char* categories[] = {
       "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes",
       "Three of a Kind", "Four of a Kind", "Full House",
       "Small Straight", "Large Straight", "Yahtzee", "Chance"
    };

    for (int i = 0; i < num_players; i++) {
        fprintf(file, "Score Card for %s:\n", players[i].name);
        fprintf(file, "---------------------------------------\n");
        fprintf(file, "Category         | Score\n");
        fprintf(file, "---------------------------------------\n");

        // Write each category score
        for (int j = 0; j < NUM_SCORE_CATEGORIES; j++) {
            fprintf(file, "%-16s | %d\n", categories[j], players[i].score_card[j]);
        }
        fprintf(file, "---------------------------------------\n\n");
    }

    fclose(file);
    printf("Player scorecards have been saved to scorecards.txt\n");
}

#include"Header.h"


int main(void)
{
    Player* players = NULL;
    int num_players = 0;
    // Array to hold user input
    char user_input[10];
    // Seed the random number generator
    srand(time(NULL));

    do {
        // clear prior window
        system("cls");

        // Display menu options
        printf("------Yahtzee!------\n");
        printf("Please select an option:\n");
        printf("1. Display Game Rules\n");
        printf("2. Play the Game\n");
        printf("3. Exit\n");
        printf("Enter your choice (1, 2, or 3): ");

        // Get user input
        scanf("%s", user_input);

        // Menu switch cases
        switch (user_input[0]) {
        case '1':

            print_game_rules();
            system("pause");
            break;

        case '2':

            // Clear menu screen
            system("cls");
            // Ask for number of players
            printf("\n\nEnter the number of players (1-4): ");

            scanf("%d", &num_players);

            // Case player number greater than max
            if (num_players > PLAYER_MAX_COUNT) {
                printf("\nSetting players to 4...\n");
                num_players = PLAYER_MAX_COUNT;
            }

            // Dynamically allocate memory for players
            players = (Player*)malloc(num_players * sizeof(Player));
            if (players == NULL) {
                printf("Memory allocation failed. Exiting game.\n");
                return 1;  // Exit if memory allocation fails
            }


                // Initialize player data
                initialize_players(&players, num_players);

                // Start game
                printf("Starting the game...\n\n");
                system("pause");

                // Play the game for 13 rounds
                for (int round = 1; round <= 13; round++) {
                    printf("\n--- Round %d ---\n", round);
                    for (int i = 0; i < num_players; i++) {
                        // Clear prior screen and display player turn
                        system("cls");
                        printf("\n--- Player %d's Turn ---\n", i + 1);

                        // Handle the player's turn (rolling dice, choosing a category, etc.)
                        take_turn(&players[i]);
                    }
                }

                // Find winner
                determine_winner(players, num_players);

                // Save results to file
                save_scorecards_to_file(players, num_players);

                //End game message
                printf("\nthanks for playing!\n");
                system("pause");
                system("cls");
            break;

        case '3':
            printf("Exiting the game. Goodbye!\n");
            system("pause");
            break;

        default:
            printf("Invalid key. Please try again.\n");
            break;

         }
     } while (user_input[0] != '3'); // Exit if user enters '3'

   return 0;
}
#include <stdio.h>
#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>

int main() {

    twitter twitter_system;

    create_twitter_system(&twitter_system);    // Function call, creates the twitter system and adds users
    printUsers(&twitter_system);     // Function call, prints out all users created

    // Menu of functions start, loops through all users
    for (int i = 0; i < filledUsers; i++) {
        // Variable to check whether a user has passed
        int userPass = 0;

        printf("\nCurrent user is: %s\n\n", twitter_system.userlist[i].username);

        // Loop runs until the user passes their turn to the next user, or the program is ended
        while (userPass == 0) {
            // Requesting user input from a selection of options
            printf("Enter 1 to write a tweet, 2 to get your news feed, 3 to follow a user, \n"
                   "4 to unfollow a user, 5 to end your turn or 6 to end the program: \n");

            // Variable for storing the users input on the menu selection
            int menuSelection;
            // fgets(&menuSelection, 2, stdin);
            scanf("%d", &menuSelection);

            // Switch statement to work through different menu options
            switch (menuSelection) {
                case 1: // Allows user to post a tweet
                    postTweet(twitter_system.userlist[i].username);
                    break;

                case 2: // Prints news feed (currently prints out all tweets)
                    tempTweetPrint();
                    break;

                case 3: // Function not yet written
                    followUser(&twitter_system.userlist[i], &twitter_system);
                    break;

                case 4: // Function not yet written
                    unfollowUser(&twitter_system.userlist[i], &twitter_system);
                    break;

                case 5:
                    userPass = 1;
                    printf("Turn ended \n");
                    break;

                case 6: // Ends the program
                    printf("Ending program");
                    exit(0);

                default: // Informs the user of invalid input
                    printf("Invalid input\n");
            }
        }
    }
}

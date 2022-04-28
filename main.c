// Created by Mynah Bhattacharyya and Fionn Murray. COMP 10050 Assignment 2.
// Main file calls create_twitter_system function, generates users
// Then executes a switch in a while loops for user choice for various functionalities.

#ifndef twitter_create
#include "twitter_create.h"
#endif

int tweetCount; //total number of tweets
tweet tweetList[MAX_TWEETS]; //array of structs for storing tweets

int main() {

    twitter twitter_system;

    create_twitter_system(&twitter_system);    // Function call, creates the twitter system and adds users
    printf("%s", "\n");
    printUsers(&twitter_system);     // Function call, prints out all users created

    // Menu of functions, loops through all users
    for (int i = 0; i < twitter_system.filledusers; i++) {
        // Variable to check whether a user has passed
        int userPass = 0;



        // Loop runs until the user passes their turn to the next user, or the program is ended
        while (userPass == 0) {
            // Prints current user
            printf("\nCurrent user is: %s\n\n", twitter_system.userlist[i].username);

            // Requesting user input from a selection of options
            printf("Enter 1 to write a tweet, 2 to get your news feed, 3 to follow a user, \n"
                   "4 to unfollow a user, 5 to delete your account, 6 to end your turn or \n"
                   "7 to end the program: \n");

            // Variable for storing the users input on the menu selection
            int menuSelection;

            // Requesting user input
            scanf("%d", &menuSelection);
            printf("%s", "\n");

            // Switch statement to work through different menu options
            switch (menuSelection) {
                case 1: // Allows user to post a tweet
                    postTweet(&twitter_system.userlist[i], &twitter_system);
                    break;

                case 2: // Prints news feed (currently prints out all tweets)
                    printf("%s", "Printing news feed: \n \n");
                    newsFeed (&twitter_system.userlist[i], &twitter_system);
                    break;

                case 3: // User follows other users
                    followUser(&twitter_system.userlist[i], &twitter_system);
                    break;

                case 4: // User unfollows other users
                    unfollowUser(&twitter_system.userlist[i], &twitter_system);
                    break;

                case 5: //User deletes their account
                    deleteUser (&twitter_system.userlist[i], &twitter_system);
                    userPass = 1;
                    i--; // Decrementing variable representing the current user to prevent a user being skipped
                    printf("Account deleted, passing to next user");
                    break;

                case 6: // User chooses to end their turn
                    userPass = 1;
                    printf("Turn ended \n");
                    break;

                case 7: // Ends the program
                    printf("Ending program");
                    exit(0);

                default: // Informs the user of invalid input
                    printf("Invalid input\n");
            }
        }
    }
} // End main loop

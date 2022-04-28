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

    printf("\nWelcome to Twitter! Please make a series of users within this current system.\n");
    create_twitter_system(&twitter_system);    // Function call, creates the twitter system and adds users
    printf("The list of users now is: \n");
    printUsers(&twitter_system);
    printf("\n-------------------------------------\n");

    // Menu of functions, loops through all users
    for (int i = 0; i < twitter_system.filledusers; i++) {
        // Variable to check whether a user has passed
        int userPass = 0;

        // Loop runs until the user passes their turn to the next user, or the program is ended
        while (userPass == 0) {
            if (strcmp(twitter_system.userlist[i].username, "exit") == 0)
            {
                printf("%s", "No more users, program ending \n");
                exit(0);
            }
            // Prints current user
            printf("\nCurrent user is: %s\n\n", twitter_system.userlist[i].username);

            // Requesting user input from a selection of options
            printf("Enter 1 to write a tweet, 2 to get your news feed, 3 to follow a user, \n"
                   "4 to unfollow a user, 5 to print out all the users in the current system, \n"
                   "6 to delete your account, 7 to end your turn or 8 to end the program: \n");

            // Variable for storing the users input on the menu selection
            //char menuSelection;
            int menuSelection;

            // Requesting user input
            fflush(stdin);
            //fgets(&menuSelection, 2, stdin);
            scanf("%d", &menuSelection);
            printf("%s", "\n");

            // Switch statement to work through different menu options
            switch (menuSelection) {
                case 1: // Allows user to post a tweet
                    postTweet(&twitter_system.userlist[i], &twitter_system);
                    printf("\n-------------------------------------\n");
                    break;

                case 2: // Prints news feed (currently prints out all tweets)
                    printf("%s", "Printing news feed: \n \n");
                    newsFeed (&twitter_system.userlist[i], &twitter_system);
                    printf("\n-------------------------------------\n");
                    break;

                case 3: // User follows other users
                    followUser(&twitter_system.userlist[i], &twitter_system);
                    printf("\n-------------------------------------\n");
                    break;

                case 4: // User unfollows other users
                    unfollowUser(&twitter_system.userlist[i], &twitter_system);
                    printf("\n-------------------------------------\n");
                    break;

                case 5: // Prints whole user list
                    printf("The list of users now is: \n");
                    printUsers(&twitter_system);
                    printf("\n-------------------------------------\n");
                    break;

                case 6: //User deletes their account
                    deleteUser (&twitter_system.userlist[i], &twitter_system);
                    userPass = 1;
                    i--; // Decrementing variable representing the current user to prevent a user being skipped
                    printf("Account deleted, passing to next user.\n");
                    printf("\n-------------------------------------\n");
                    break;

                case 7: // User chooses to end their turn
                    userPass = 1;
                    printf("Turn ended.\n");
                    printf("\n-------------------------------------\n");
                    break;

                case 8: // Ends the program
                    printf("Ending program.\n");
                    printf("\n-------------------------------------\n");
                    exit(0);

                default: // Informs the user of invalid input
                    printf("Invalid input.\n");
                    printf("\n-------------------------------------\n");
                    fflush(stdin);
            }
            if ((i == twitter_system.filledusers-1) && userPass !=0) i = -1; //Returns to first user if the final passes or is deleted
        }
    }
} // End main loop

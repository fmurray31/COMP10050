#include <stdio.h>
#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>

// Array of structs for storing tweets
struct tweet tweetList[MAX_TWEETS];

// Global variable for total number of tweets
int tweetCount = 0;

int main() {

    twitter twitter_system;
    // Creates the twitter system and adds users
    create_twitter_system(&twitter_system);


    // Prints all users
    for (int i = 0; i < twitter_system.filledusers; i++) {
        printf("User name is: ");
        printf("%s, ", twitter_system.userlist[i].username);
        printf("with %d followers and %d following.\n", twitter_system.userlist[i].num_followers,
               twitter_system.userlist[i].num_following);
    }

    // Main loop through all users
    for (int i = 0; i < twitter_system.filledusers; i++) {
        // Variable to check whether a user has passed
        int userPass = 0;

        printf("\nCurrent user is: %s\n\n", twitter_system.userlist[i].username);

        // Loop runs until the user passes or the program is ended
        while (userPass == 0) {
            // Requesting user input from a selection of options
            printf("Enter 1 to write a tweet, 2 to get your news feed, 3 to follow a user, \n"
                   "4 to unfollow a user, 5 to end your turn or 6 to end the program: \n");

            // Variable for storing the users input on the menu selection
            int menuSelection;
            //fgets(&menuSelection, 2, stdin);
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
                    //followUser;
                    break;

                case 4: // Function not yet written
                    //unfollowUser;
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

// Function to request and store tweets from a user
void postTweet (char *currentUser) {
    tweetList[tweetCount].id = tweetCount;
    printf("Write up to 270 characters for your tweet: \n");
    //fgets(tweetList[tweetCount].msg, TWEET_LENGTH, stdin);
    scanf("%s", tweetList[tweetCount].msg);
    strcpy(tweetList[tweetCount].user, currentUser);
    tweetCount++;
    printf("\n");
}

// Temp tweet print function
void tempTweetPrint (void)
{
    // Iterates through every tweet, printing each one and the relevant user
    for (int i=0; i<tweetCount; i++)
    {
        printf("%s \n", tweetList[i].user);
        printf("%s \n\n", tweetList[i].msg);
    }
}
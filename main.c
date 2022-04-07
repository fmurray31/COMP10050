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
    for (int i=0; i<twitter_system.filledusers; i++)
    {
        printf("User name is: ");
        printf("%s, ", twitter_system.userlist[i].username);
        printf("with %d followers and %d following.\n", twitter_system.userlist[i].num_followers, twitter_system.userlist[i].num_following);
    }

    /*
    // Main loop through all users
    for (int i=0; i<twitter_system.filledusers; i++)
    {
        // Variable to check whether a user has passed
        int userPass = 0;

        // Loop runs until the user passes or the program is ended
        while (userPass == 0)
        {
            // Requesting user input from a selection of options
            printf("Enter 1 to write a tweet, 2 to follow a user, 3 to unfollow a user, 4 to end your turn \n"
                   "or 5 to end the program: \n");

            // Variable for storing the users input on the menu selection
            int menuSelection;
            fgets(menuSelection, 1, stdin);

            // Switch statement to work through different menu options
            switch (menuSelection)
            {
                case 1:
                    requestTweets(twitter_system.userlist[i].username);
                    break;

                case 2: // Function not yet written
                    followUser;
                    break;

                case 3: // Function not yet written
                    unfollowUser;
                    break;

                case 4:
                    userPass = 1;
                    break;

                case 5: // Functionality not yet decided
                    endprogram;
                    break;

                default:
                    printf("Invalid input\n");
            }
        }
*/
    }






    //implement here the code to print the users
    // for each user you need to print the username, the number of followers and the number of users that the current user is following

/*
// Function to request and store tweets from a user
void requestTweets (char *currentUser)
{
    char userInput;

    while (strcasecmp(userInput, "y") == 0)
    {
        tweetList[tweetCount].id = tweetCount;
        printf("Write up to 270 characters for your tweet: \n");
        fgets(tweetList[tweetCount].msg, TWEET_LENGTH, stdin);
        strcpy(tweetList[tweetCount].user, currentUser);
        printf("\n");

        // *** Needs error checking for user input ***
        printf("Enter y to write another tweet, or n to finish: \n");
        fgets(userInput, 1, stdin);
    }
}
  */
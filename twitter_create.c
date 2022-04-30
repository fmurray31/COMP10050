// Created by Mynah Bhattacharyya and Fionn Murray. COMP 10050 Assignment 2.
// Contains function to create twitter system and generate users.
// Also contains a helper function to print out existing user list.

#ifndef twitter_create
#include "twitter_create.h"
#endif

// Function to take input of usernames and generate users based on them
void create_twitter_system(twitter *twitter_system)
{
    int i; //no. of users filled
    int j; //no. of followers
    int k; //no. of following
    char escapeinput[10] = "exit"; //type this to exit function

    for (i = 0; i < MAX_USERS; i++)
    {
        // take in username
        printf("Enter a unique username, or enter exit to end input:\n");
        fgets(twitter_system->userlist[i].username, USR_LENGTH, stdin);

        // error handling for replacing newline with null string terminator
        if (twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username)-1] == '\n')
        { twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username)-1] = '\0'; }

        // if the user gives a valid username that isn't exit
        if (strcasecmp(twitter_system->userlist[i].username, escapeinput) != 0)
        {
            // populate the struct with empty values
            twitter_system->userlist[i].num_followers = 0;
            twitter_system->userlist[i].num_following = 0;

            for (j = 0; j < MAX_FOLLOWERS; j++)
            { strcpy(twitter_system->userlist[i].followers[j], "");}

            for (k = 0; k < MAX_FOLLOWING; k++)
            {strcpy(twitter_system->userlist[i].following[k], "");}
        }

        else // if user puts in the phrase "exit"
        {
            twitter_system->userlist[i] = twitter_system->userlist[i+1];
            break;
        }
    }

    // other initialisers
    twitter_system->filledusers = i; // store number of users in array inside struct twitter system
    twitter_system->tweetcount = 0; // initialises tweet count to 0 inside struct twitter system
    twitter_system->mostrecenttwt = NULL; // initialises start of tweet stack to NULL (no tweets yet)
} // end create twitter function

// whole user list print function
void printUsers (twitter * twitter_system)
{
    // iterate through all existing users
    for (int i = 0; i < twitter_system->filledusers; i++)
    {
        printf("User name is: ");
        printf("%s, ", twitter_system->userlist[i].username);
        printf("with %d followers and %d following.\n", twitter_system->userlist[i].num_followers,
               twitter_system->userlist[i].num_following);
    }
} //end print users function

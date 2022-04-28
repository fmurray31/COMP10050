// Created by Mynah Bhattacharyya and Fionn Murray. COMP 10050 Assignment 2.
// Contains deleteUser function.
// Allows user to delete account, tweets and instances in following/follower lists.

#ifndef twitter_create
#include "twitter_create.h"
#endif

// Function to delete a user, remove them from all follower/following lists, and delete all the user's tweets
void deleteUser (user *currentUser, twitter *twitter_system) {
    int i, j, k;

    // Deleting currentUser from all other user's following lists
    for (i = 0; i < twitter_system->filledusers; i++) // Iterate through all users
    {
        for (j = 0; j < twitter_system->userlist[i].num_following; j++) // Iterate through user followers
        {
            // Checks name of user to be deleted against each user's following lists
            if (strcmp(currentUser->username, twitter_system->userlist[i].following[j]) == 0) {
                // If a match is found, moves the deleted user to the end of the following array
                for (k = j; k < twitter_system->userlist[i].num_following; k++) {
                    twitter_system->userlist[i].following[k] = twitter_system->userlist[i].following[k + 1];
                }

                twitter_system->userlist[i].following[k] = NULL; // Sets the pointer to the deleted username to NULL

                --twitter_system->userlist[i].num_following; // Decrementing following count
            }
        }
    } // End loop through users for following users


    // Deleting currentUser from all other user's followed lists
    for (i = 0; i < twitter_system->filledusers; i++) // Iterate through all users
    {
        for (j = 0; j < currentUser->num_followers; j++) // Iterate through user followers
        {
            // Checks name of user to be deleted against each user's follower lists
            if (strcmp(currentUser->username, twitter_system->userlist[i].followers[j]) == 0) {

                // If a match is found, moves the deleted user to the end of the following array
                for (k = j; k < twitter_system->userlist[i].num_followers; k++) {
                    twitter_system->userlist[i].followers[k] = twitter_system->userlist[i].followers[k + 1];
                }

                twitter_system->userlist[i].followers[k] = NULL; // Sets the pointer to the deleted username to NULL

                --twitter_system->userlist[i].num_followers; // Decrementing followers count
            }
        }
    }

    // Pointer to the first entry in the list of tweets
    tweet *tweetPtr = twitter_system->mostrecenttwt;
    tweet *prevTweetPtr = NULL;

    while (tweetPtr != NULL)
    {
        if (strcmp(tweetPtr->user, currentUser->username) == 0)
        {
            tweet *temp = tweetPtr;
            tweetPtr = tweetPtr->previoustwt;
            free (temp);
            --twitter_system->tweetcount;
            if (prevTweetPtr != NULL) prevTweetPtr->previoustwt = tweetPtr;
        }

        prevTweetPtr = tweetPtr;
        if (tweetPtr != NULL) tweetPtr = tweetPtr->previoustwt;
    }


    // Deleting currentUser from the list of users
    for (i=0; i<twitter_system->filledusers; i++)
    {
        // Searches for currentUser in the list of users
        if (strcmp(currentUser->username, twitter_system->userlist[i].username) == 0)
        {
            // Moves deleted user to the end of the array of users
            for (j=i; j<twitter_system->filledusers; j++)
            {
                twitter_system->userlist[j] = twitter_system->userlist[j+1];
            }

            user *deletedUser = &twitter_system->userlist[j];

            twitter_system->userlist[j-1].nextUserPtr = twitter_system->userlist[j].nextUserPtr;

            twitter_system->userlist[j].nextUserPtr = NULL;


            //free (deletedUser);

            --twitter_system->filledusers; // Decrements filledusers
        }

    } // End loop through users for following lists
} // End deleteUser function

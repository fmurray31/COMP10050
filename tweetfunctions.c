// Created by Mynah Bhattacharyya and Fionn Murray. COMP 10050 Assignment 2.
// Contains functions postTweet and newsFeed.
// postTweet: Allows a user to post a tweet and store it in a stack of tweets.
// newsFeed: Allows a user to get 10 most recent tweets of their own and those they follow.

#ifndef twitter_create
#include "twitter_create.h"
#endif

extern int filledUsers; //no of total users filled in (for general use in loops)
extern int tweetCount; //total number of tweets
extern tweet tweetList[MAX_TWEETS]; //array of structs for storing tweets

// Function to request and store tweets from a user
// LIFO stack of tweets, mostrecenttwt is pointer to top of stack, passed to this function
void postTweet(user *currentUser, twitter *twitter_system)
{
    tweet * mostrecent = twitter_system->mostrecenttwt;
    tweet * newtweet = (tweet * ) malloc(sizeof(tweet)); // create node

    if (newtweet != NULL)
    {   //populate node
        twitter_system->tweetcount++; // increment global tweet count by 1
        newtweet->id = twitter_system->tweetcount;
        strcpy(newtweet->user, currentUser->username);
        newtweet->previoustwt = NULL; // currently pointing to nothing else
        printf("Enter your tweet (max 270 characters): \n");
        fflush(stdin);
        fgets(newtweet->msg, TWEET_LENGTH, stdin);
        //population done

        if (mostrecent == NULL) // if there are no tweets
        {   // make most recent tweet be the newly created tweet
            twitter_system->mostrecenttwt = newtweet;
        }

        else // if there are preexisting tweets
        {
            newtweet->previoustwt = twitter_system->mostrecenttwt;
            twitter_system->mostrecenttwt = newtweet;
        }

        // error checking printf's
        printf("You have successfully posted your tweet:\n");
        printf("%s\n", twitter_system->mostrecenttwt->msg);
        printf("There are currently %d tweets.\n\n", twitter_system->tweetcount);
    }

    else // if malloc fails and tweet not created
    { printf("There was an issue with making space for your tweet. Please try again.\n"); }
} // end of postTweet function


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

// News feed function, prints the 10 most recent tweets from the current user and any users they re following
void newsFeed (user *currentUser, twitter *twitter_system)
{
    int found10 = 0; // Variable to check whether 10 valid tweets have been found
    int j;

    // Pointer to the beginning of the list of tweets
    tweet *tweetPtr = twitter_system->mostrecenttwt;

    // Loops through the list of tweets until either 10 tweets have been found or the end of the list is reached
    while (tweetPtr != NULL && found10 < 10)
    {
        // Checks the author of the current tweet against the current user
        if (strcmp(tweetPtr->user, currentUser->username) == 0)
        {
            // If there is a match, increments the counter of printed tweets and prints the username and contents of the current tweet
            found10++;
            printf("%s \n", tweetPtr->user);
            printf("%s \n\n", tweetPtr->msg);
        }

        // If the current tweet was not written by the current user, this loop checks to see if it was written by any of the users
        // the current user follows
        else {
            for (j = 0; j < currentUser->num_following; j++) {
                // Checks each user the current user is following against the current user
                if (strcmp(currentUser->following[j], tweetPtr->user) == 0) {
                    // If there is a match, increments the counter of printed tweets and prints the username and contents of the current tweet
                    found10++;
                    printf("%s \n", tweetPtr->user);
                    printf("%s \n", tweetPtr->msg);
                }
            }
        }
        // Increments the tweet pointer to the next most recent tweet
        tweetPtr = tweetPtr->previoustwt;
    } // End while loop
} // End newsFeed function
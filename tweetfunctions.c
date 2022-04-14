//
// Created by mynah on 11/04/22.
//
#include <stdio.h>
#include <string.h>
#ifndef twitter_func
#include "twitter_create.h"
#endif

extern int filledUsers; //no of total users filled in (for general use in loops)
extern int tweetCount; //total number of tweets
extern tweet tweetList[MAX_TWEETS]; //array of structs for storing tweets
// Function to request and store tweets from a user

void postTweet (char *currentUser) {
    tweetList[tweetCount].id = tweetCount;
    printf("Write up to 270 characters for your tweet: \n");
    fflush(stdin);
    fgets(tweetList[tweetCount].msg, TWEET_LENGTH, stdin);
    //scanf("%s", tweetList[tweetCount].msg);
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
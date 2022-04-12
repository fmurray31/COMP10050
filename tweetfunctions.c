//
// Created by mynah on 11/04/22.
//
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

// Function to request and store tweets from a user
void postTweet (user *currentUser) {
    tweetList[tweetCount].id = tweetCount;
    printf("Write up to 270 characters for your tweet: \n");
    fgets(tweetList[tweetCount].msg, TWEET_LENGTH, stdin);
    //scanf("%s", tweetList[tweetCount].msg);
    strcpy(tweetList[tweetCount].user, currentUser->username);
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
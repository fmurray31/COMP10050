//
// Created by mynah on 11/04/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef twitter_create
#include "twitter_create.h"
#endif

//LIFO stack of tweets, mostrecenttwt is top of stack
void postTweet(user *currentUser, twitter *twitter_system)
{
    tweet * mostrecent = twitter_system->mostrecenttwt;
    tweet * newtweet = (tweet * ) malloc(sizeof(tweet)); //create node

    if (newtweet != NULL)
    {   //populate node
        twitter_system->tweetcount++; //increment global tweet count by 1
        newtweet->id = twitter_system->tweetcount;
        strcpy(newtweet->user, currentUser->username);
        newtweet->previoustwt = NULL; //currently pointing to nothing else
        printf("Enter your tweet (max 270 characters): \n");
        fflush(stdin);
        fgets(newtweet->msg, TWEET_LENGTH, stdin);
        //population done

        if (mostrecent == NULL) //if there are no tweets
        {   //make most recent tweet be the newly created tweet
            twitter_system->mostrecenttwt = newtweet;
        }

        else //if there are preexisting tweets
        {
            newtweet->previoustwt = twitter_system->mostrecenttwt;
            twitter_system->mostrecenttwt = newtweet;
        }
        printf("You have successfully posted your tweet!:\n");
        printf("%s\n", twitter_system->mostrecenttwt->msg); //error checking
        printf("There are currently %d tweets.\n\n", twitter_system->tweetcount); //error checking
    }

    else //if malloc fails
    { printf("There was an issue with making space for your tweet. Please try again.\n"); }
}


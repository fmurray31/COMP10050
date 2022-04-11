//
// Created by Lili on 30/03/2022.
//

#ifndef ASSIGNMENT2_TWITTER_CREATE_H
#define ASSIGNMENT2_TWITTER_CREATE_H

#endif //ASSIGNMENT2_TWITTER_CREATE_H

//DEFINITIONS HERE:

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGTH 100

//Max num of a followers
#define MAX_FOLLOWERS 30

//Max num of following users
#define MAX_FOLLOWING 30

//Max num of tweets in the news feed
#define MAX_TWEETS 100

//Max num of users
#define MAX_USERS 100

// STRUCTS AND POINTER TYPES HERE:

typedef struct tweet
{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGTH];

}tweet;

typedef struct user
{
    char username[USR_LENGTH];

    char *followers[MAX_FOLLOWERS];
    int num_followers;

    char *following[MAX_FOLLOWING];
    int num_following;

    struct user *nextUserPtr;
}user;

//typedef user *userPtr;

typedef struct twitter
{
    int filledusers; //number of users filled in
    user userlist[MAX_USERS]; //array of structures for users
    tweet tweetname;
}twitter;

// FUNCTIONS HERE:

void create_twitter_system(twitter * twitter_system);

// void createUser(userPtr *mainUserPtr, char name[USR_LENGTH]);
// void printUsers(userPtr currentUserPtr);
// int isEmpty(userPtr ptr);

// Function to request and store tweets from the user
void postTweet (char *currentUser);

// Temporary function to print out all tweets
void tempTweetPrint (void);

//GLOBAL VARIABLES HERE:

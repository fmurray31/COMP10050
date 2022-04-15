//
// Created by Lili on 30/03/2022.
//

#ifndef ASSIGNMENT2_TWITTER_CREATE_H
#define ASSIGNMENT2_TWITTER_CREATE_H

#endif //ASSIGNMENT2_TWITTER_CREATE_H

//DEFINITIONS HERE:

#define TWEET_LENGTH 270 //Max length of a tweet

#define USR_LENGTH 100 //Max length of a username

#define MAX_FOLLOWERS 30 //Max num of a followers

#define MAX_FOLLOWING 30 //Max num of following users

#define MAX_TWEETS 100 //Max num of tweets in the news feed

#define MAX_USERS 100 //Max num of users

// STRUCTS AND POINTER TYPES HERE:

// TWEET STRUCT TYPE: id number, string with tweet, username of tweet author
typedef struct tweet
{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGTH];
    struct tweet *previoustwt;

}tweet;

// USER STRUCT TYPE: username, list and number of followers, list and number of following, pointer to next user
typedef struct user
{
    char username[USR_LENGTH];
    char *followers[MAX_FOLLOWERS]; //array of strings
    int num_followers;
    char *following[MAX_FOLLOWING]; //array of strings
    int num_following;
    struct user *nextUserPtr;
}user;

//POINTER TO A DATA TYPE OF STRUCT USER
typedef user *userPtr;

// TWITTER USER GENERATION STRUCT TYPE:
// number of users, array of users,
typedef struct twitter
{
    int filledusers; //number of users filled in
    user userlist[MAX_USERS]; //array of structs containing users
    tweet * mostrecenttwt; //start pointer to linked list of all tweets
    int tweetcount; //no. of tweets, used for tweet id.
}twitter;

//POINTER TO A DATA TYPE OF STRUCT TWITTER
typedef twitter *twitterPtr;

// FUNCTIONS HERE:

// Function to create a twitter system of generated users, stored in an array
void create_twitter_system(twitter * twitter_system);

// Helper function to print all users
void printUsers (twitter * twitter_system);

// Function to let user tweet and store tweet in LIFO stack
void postTweet(user *currentUser, twitter *twitter_system);

//Function to let a user follow other users
void followUser (userPtr currentUser, twitterPtr twitter_system);

//Function to let a user unfollow other users
void unfollowUser (user *currentUser, twitter *twitter_system);

// Function to delete user, including deleting old tweets and removing them from follower lists
void deleteUser (user *currentUser, twitter *twitter_system);

// void createUser(userPtr *mainUserPtr, char name[USR_LENGTH]);
// void printUsers(userPtr currentUserPtr);
// int isEmpty(userPtr ptr);

//GLOBAL VARIABLES HERE:



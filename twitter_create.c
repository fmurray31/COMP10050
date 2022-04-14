//
// Created by Lili on 30/03/2022.
//

#include <stdio.h>
#include <string.h>
#ifndef twitter_create
#include "twitter_create.h"
#endif
void create_twitter_system(twitter *twitter_system)
{
    int i; //no. of users filled
    int j; //no. of followers
    int k; //no. of following
    char escapeinput[10] = "exit"; //type this to exit function

    for (i = 0; i < MAX_USERS; i++)
    {
        printf("Enter a unique username, or enter exit to end input.\n");
        fgets(twitter_system->userlist[i].username, USR_LENGTH, stdin); //take in username

        //error handling for replacing newline with null string terminator
        if (twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username)-1] == '\n')
        { twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username)-1] = '\0'; }

        //if there is a valid name given
        if (strcasecmp(twitter_system->userlist[i].username, escapeinput) != 0)
        {
            //populate the struct with empty values
            twitter_system->userlist[i].num_followers = 0;
            twitter_system->userlist[i].num_following = 0;

            for (j = 0; j < MAX_FOLLOWERS; j++)
            { twitter_system->userlist[i].followers[j] = NULL; }

            for (k = 0; k < MAX_FOLLOWING; k++)
            { twitter_system->userlist[i].following[k] = NULL; }
        }

        else
        { break; }
    }

    twitter_system->filledusers = i; //store number of users in struct
    twitter_system->filledusers = i; //store number of users in global variable (for general use in main)
}

//Whole userlist print function
void printUsers (twitter * twitter_system)
{
    for (int i = 0; i < twitter_system->filledusers; i++)
    {
        printf("User name is: ");
        printf("%s, ", twitter_system->userlist[i].username);
        printf("with %d followers and %d following.\n", twitter_system->userlist[i].num_followers,
               twitter_system->userlist[i].num_following);
    }
}

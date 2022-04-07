//
// Created by Lili on 30/03/2022.
//
/*
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

void create_twitter_system(twitter *twitter_system)
{
    int i; //no. of users filled
    int j; //no. of followers
    int k; //no. of following
    char escapeinput[10] = "exit";

    for (i = 0; i < MAX_USERS; i++)
    {
        puts("Enter a unique username, or enter exit to end input.");
        fscanf(stdin, "%s", twitter_system->userlist[i].username);

        if (twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username-1)] == '\n')
        { twitter_system->userlist[i].username[strlen(twitter_system->userlist[i].username-1)] = '\0'; }

        if (strcasecmp(twitter_system->userlist[i].username, escapeinput) != 0)
        {
            twitter_system->userlist[i].num_followers = 0;
            twitter_system->userlist[i].num_following = 0;

            for (j = 0; j < MAX_FOLLOWERS; j++)
            { twitter_system->userlist[i].followers[j] = ""; }

            for (k = 0; k < MAX_FOLLOWING; k++)
            { twitter_system->userlist[i].followers[k] = ""; }
        }

        else
        { break; }
    }
    twitter_system->filledusers = i;
}

*/
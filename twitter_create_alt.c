

//
// Created by Lili on 30/03/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * #include "twitter_create.h"
void create_twitter_system(twitter *twitter_system)
{
    char name[USR_LENGTH];
    char escape[10] = "exit";
    userPtr startPtr = NULL;

    while (strcasecmp(name, escape) != 0)
    {
        printf("Please enter the user's name or type exit to terminate: \n");
        fgets(name, USR_LENGTH, stdin);

        if (name[strlen(name) - 1] == '\n')
        { name[strlen(name) - 1] = '\0'; }

        if (strcmp(name, escape) != 0)

            createUser(&startPtr, name);

    }

    if (strcmp(name, escape) == 0 )
    {
        puts("You are finished entering users.");
    }

    printUsers(startPtr);
}

void createUser (userPtr *uPtr, char name[USR_LENGTH])
{
    userPtr newUserPtr = malloc (sizeof (user));

    if (newUserPtr != NULL){
        strcpy(newUserPtr->username, name);
        // Setting followers and following to 0
        newUserPtr->num_following = 0;
        newUserPtr->num_followers = 0;

        newUserPtr->nextUserPtr = NULL;

        userPtr previousUserPtr = NULL;
        userPtr currentUserPtr = *uPtr;

        while ((currentUserPtr != NULL) && (strcasecmp(name, currentUserPtr->username)) > 0)
        {
            previousUserPtr = currentUserPtr;
            currentUserPtr = currentUserPtr->nextUserPtr;
        }

        if (previousUserPtr == NULL)
        {
            newUserPtr->nextUserPtr = *uPtr;
            *uPtr = newUserPtr;
        }

        else {
            previousUserPtr->nextUserPtr = newUserPtr;
            newUserPtr->nextUserPtr = currentUserPtr;
        }
    }
    else puts("No memory");
}


int isEmpty(userPtr ptr)
{ return ptr == NULL; }

void printUsers(userPtr currentUser)
{
    if (isEmpty(currentUser))
    { puts("List is empty.\n"); }

    else
    {
        puts("All the users are: ");

        while (currentUser != NULL)
        {
            printf("?: %s, with %d followers and %d following.\n",
                   currentUser->username, currentUser->num_followers, currentUser->num_following);

            currentUser = currentUser->nextUserPtr;
        }
    }
}*/
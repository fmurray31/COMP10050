//
// Created by mynah on 11/04/22.
// file for follow users / unfollow users / delete users

#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

void followUser (user *currentUser, twitter *twitter_system)
{
    int userChoice;
    char followname[USR_LENGTH];

    printf("Enter 1 to follow a specific user, 2 for the list of users, or any other number to exit: \n");
    scanf("%d", &userChoice);

    while (userChoice == 1 || userChoice == 2)
    {
        if (userChoice == 1) //follow someone choice
        {
            printf("Enter the name of the user you would like to follow: \n");
            fscanf(stdin, "%s", followname); //user input for name of person they want to follow

            //error handling for adding string null terminator
            if ( followname[strlen(followname)-1] == '\n')
            { followname[strlen(followname)-1] = '\0'; }

            int i = 0;
            int found = 0; //bool to see if there is a matching user in userlist
            while (i < filledUsers && found == 0)//iterate through all existing users
            {
                //if you find a username in the userlist that matches input
                if ( strcmp(twitter_system->userlist[i].username, followname) == 0 )
                {
                    //store matching name in string array of following, at location indexed by number of followers
                    int location1 = currentUser->num_following;
                    currentUser->following[location1] = twitter_system->userlist[i].username;
                    currentUser->num_following++; //increment their following count (useful to place next follower into follower array)

                    //error checking
                    printf("Your following count is now: %d.\n", currentUser->num_following);
                    printf("You now follow: ");
                    printf("%s\n", currentUser->following[location1] );

                    //implement having the other person's follower count and follower list increase
                    int location2 = twitter_system->userlist[i].num_followers; //initially 0
                    twitter_system->userlist[i].followers[location2] = currentUser->username;
                    twitter_system->userlist[i].num_followers++; //increment follower count

                    //error checking
                    printf("Your follower count is now: %d.\n", twitter_system->userlist[i].num_followers);
                    printf("You are now followed by: ");
                    printf("%s\n", twitter_system->userlist[i].followers[location2]);

                    found = 1; //switch bool to jump out of while loop
                }
                i++; //increment while loop to next in userist
            }
        }

        else if (userChoice == 2) //print users choice
        { printUsers(twitter_system); }

        //next round of choices for follow or exit
        printf("Enter 1 to follow a specific user, 2 for the list of users, or any other number to exit.\n");
        scanf("%d", &userChoice);
    }
}

void unfollowUser (user *currentUser, twitter *twitter_system)
{
    int userChoice;
    char unfollowname[USR_LENGTH];

    printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
    scanf("%d", &userChoice);

    while (userChoice == 1 || userChoice == 2)
    {
        if (userChoice == 1)
        {
            printf("Enter the name of the user you would like to unfollow: \n");
            fscanf(stdin, "%s", unfollowname); //user input for name of person they want to follow

            //error handling for adding string null terminator
            if ( unfollowname[strlen(unfollowname)-1] == '\n')
            { unfollowname[strlen(unfollowname)-1] = '\0'; }
        }

        else if (userChoice == 2)
        {
            int i = 0;
            int found = 0; //bool to see if there is a matching user in userlist
            while (i < currentUser->num_following && found == 0)//iterate through all existing users
            {

            }
        }

        //next round of choices for follow or exit
        printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
        scanf("%d", &userChoice);
    }

}
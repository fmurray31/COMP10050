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
                i++; //increment while loop to next in userlist
            }
            if (found == 0) //if person is not found in userlist
            { printf("This user doesn't exist.\n"); }
        } //end user choice 1

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
        if (userChoice == 1) //if user wants to unfollow someone
        {
            printf("Enter the name of the user you would like to unfollow: \n");
            fscanf(stdin, "%s", unfollowname); //user input for name of person they want to follow

            //error handling for adding string null terminator
            if ( unfollowname[strlen(unfollowname)-1] == '\n')
            { unfollowname[strlen(unfollowname)-1] = '\0'; }

            int i = 0;
            int found = 0; //bool to see if there is a matching user in your following list
            while (i < currentUser->num_following && found == 0)//iterate through whole following list
            {
                if ( strcmp(currentUser->following[i], unfollowname) == 0 ) //if a matching user is found
                {
                    int numfollowing = currentUser->num_following; //no. of users in the following list
                    for (int j = i; j < numfollowing; j++) //starting from place we found user to be unfollowed
                    {
                        strcpy(currentUser->following[j], ""); //empty the spot
                        strcpy(currentUser->following[j], currentUser->following[j+1]); //copy over next following user, to fill spot
                    }
                    strcpy(currentUser->following[numfollowing], ""); //place an empty in the last location after carry-overs of following done

                    currentUser->num_following--; //decrement number of following
                    found = 1; //switch bool to jump out of while loop
                }
                i++; //increment while loop to next in userlist
            }
            if (found == 0) //if user doesnt exist in following list
            { printf("You are not currently following this user. You are unable to unfollow them.\n"); }
        }

        else if (userChoice == 2) //if user wants to print their following list
        {
            printf("You are currently following: \n");
           for (int i = 0; i < currentUser->num_following; i++)
           {
               printf("%d: %s\n", i+1, currentUser->following[i]); //just prints their names stored in array as strings
           }
        }

        //next round of choices for follow or exit
        printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
        scanf("%d", &userChoice);
    }

}
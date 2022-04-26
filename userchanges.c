//
// Created by mynah on 11/04/22.
// file for follow users / unfollow users / delete users

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
            while (i < twitter_system->filledusers && found == 0)//iterate through all existing users
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
            int numfollowing = currentUser->num_following; //no. of users in the following list

            while (i < numfollowing && found == 0)//iterate through whole following list
            {
                if ( strcmp(currentUser->following[i], unfollowname) == 0 ) //if a matching user is found in following list
                {
                    int j = i;
                    printf("Found in following list: %s, at position: %d\n\n", currentUser->following[i], i); //error checking
                    while ( (j < numfollowing) && (currentUser->following[j] != NULL) ) //starting from place we found user to be unfollowed
                    {
                        currentUser->following[j] =  currentUser->following[j+1]; //make string pointer point to next user
                        printf("Current user is now: %s\n", currentUser->following[j]); //error checking
                        j++;
                    }
                    currentUser->following[j] = NULL; //place an empty in the last location after carry-overs of following done
                    currentUser->num_following--; //decrement number of following
                    printf("Current no of following is: %d\n", currentUser->num_following);

                    //implement having the other person's follower count and follower list decrease
                    int k = 0;
                    int found2 = 0; //bool to find user in twitter list of users
                    while (k < twitter_system->filledusers && found2 == 0) //iterate through twitter list
                    {
                        if ( strcmp(twitter_system->userlist[k].username, unfollowname) == 0 ) //if unfollowed user found
                        {
                            int l = 0;
                            int numfollowers = twitter_system->userlist[k].num_followers;

                            while ((l < numfollowers) &&  (twitter_system->userlist[k].followers[l] != NULL) ) //iterate through unfollowed user's followers list
                            {   //if current user's name is found
                                twitter_system->userlist[k].followers[l] = twitter_system->userlist[k].followers[l+1];
                                l++;
                            }
                            twitter_system->userlist[k].followers[l] = NULL;
                            twitter_system->userlist[k].num_followers--; //decrement unfollowed user's follower count
                            printf("Current no of followers is: %d\n", twitter_system->userlist[k].num_followers);
                            found2 = 1; //current user found
                        }
                        k++; //increment through twitter userlist
                    }

                    found = 1; //switch bool to jump out of main unfollow while loop
                }
                i++; //increment while loop to next in userlist
            }

            if (found == 0) //if user doesnt exist in following list
            { printf("You are not currently following this user. You are unable to unfollow them.\n"); }
        } //end user choice 1

        else if (userChoice == 2) //if user wants to print their following list
        {
            printf("You are currently following: \n");
            for (int i = 0; i < currentUser->num_following; i++)
            {
                printf("%d: %s\n", i+1, currentUser->following[i]); //just prints their names stored in array as strings
            }
        } //end user choice 2

        //next round of choices for follow or exit
        printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
        scanf("%d", &userChoice);
    } //end while loop

} //end unfollow funct


// Function to delete a user, remove them from all follower/following lists, and delete all the user's tweets
void deleteUser (user *currentUser, twitter *twitter_system) {
    int i, j, k;

    // Deleting currentUser from all other user's following lists
    for (i = 0; i < twitter_system->filledusers; i++) // Iterate through all users
    {
        for (j = 0; j < twitter_system->userlist[i].num_following; j++) // Iterate through user followers
        {
            // Checks name of user to be deleted against each user's following lists
            if (strcmp(currentUser->username, twitter_system->userlist[i].following[j]) == 0) {
                // If a match is found, moves the deleted user to the end of the following array
                for (k = j; k < twitter_system->userlist[i].num_following; k++) {
                    twitter_system->userlist[i].following[k] = twitter_system->userlist[i].following[k + 1];
                }

                twitter_system->userlist[i].following[k] = NULL; // Sets the pointer to the deleted username to NULL

                --twitter_system->userlist[i].num_following; // Decrementing following count
            }
        }
    } // End loop through users for following users


    // Deleting currentUser from all other user's followed lists
    for (i = 0; i < twitter_system->filledusers; i++) // Iterate through all users
    {
        for (j = 0; j < currentUser->num_followers; j++) // Iterate through user followers
        {
            // Checks name of user to be deleted against each user's follower lists
            if (strcmp(currentUser->username, twitter_system->userlist[i].followers[j]) == 0) {

                // If a match is found, moves the deleted user to the end of the following array
                for (k = j; k < twitter_system->userlist[i].num_followers; k++) {
                    twitter_system->userlist[i].followers[k] = twitter_system->userlist[i].followers[k + 1];
                }

                twitter_system->userlist[i].followers[k] = NULL; // Sets the pointer to the deleted username to NULL

                --twitter_system->userlist[i].num_followers; // Decrementing followers count
            }
        }
    }

    // Pointer to the first entry in the list of tweets
    tweet *tweetPtr = twitter_system->mostrecenttwt;
    tweet *prevTweetPtr = NULL;

    while (tweetPtr != NULL)
    {
        if (strcmp(tweetPtr->user, currentUser->username) == 0)
        {
            tweet *temp = tweetPtr;
            tweetPtr = tweetPtr->previoustwt;
            free (temp);
            --twitter_system->tweetcount;
            if (prevTweetPtr != NULL) prevTweetPtr->previoustwt = tweetPtr;
        }

        prevTweetPtr = tweetPtr;
        if (tweetPtr != NULL) tweetPtr = tweetPtr->previoustwt;
    }


    // Deleting currentUser from the list of users
    for (i=0; i<twitter_system->filledusers; i++)
    {
        // Searches for currentUser in the list of users
        if (strcmp(currentUser->username, twitter_system->userlist[i].username) == 0)
        {
            // Moves deleted user to the end of the array of users
            for (j=i; j<twitter_system->filledusers; j++)
            {
                twitter_system->userlist[j] = twitter_system->userlist[j+1];
            }

            user *deletedUser = &twitter_system->userlist[j];

            twitter_system->userlist[j-1].nextUserPtr = twitter_system->userlist[j].nextUserPtr;

            twitter_system->userlist[j].nextUserPtr = NULL;


            //free (deletedUser);

            --twitter_system->filledusers; // Decrements filledusers
        }

    } // End loop through users for following lists
} // End deleteUser function
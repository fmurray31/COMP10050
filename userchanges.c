// Created by Mynah Bhattacharyya and Fionn Murray. COMP 10050 Assignment 2.
// Contains function definitions for functions that change the user list somehow.
// Contains followUser, unfollowUser.

#ifndef twitter_create
#include "twitter_create.h"
#endif

// function to follow some other existing user
void followUser (user *currentUser, twitter *twitter_system)
{
    int userChoice;
    char followname[USR_LENGTH];

    printf("Enter 1 to follow a specific user, 2 for the list of users, or any other number to exit: \n");
    scanf("%d", &userChoice);

    while (userChoice == 1 || userChoice == 2)
    {
        if (userChoice == 1) // user chooses to follow someone
        {
            printf("Enter the name of the user you would like to follow: \n");
            fflush(stdin);
            fgets(followname, USR_LENGTH, stdin); // user input for name of person they want to follow

            // error handling for adding string null terminator
            if ( followname[strlen(followname)-1] == '\n')
            { followname[strlen(followname)-1] = '\0'; }

            // check if you already follow the user or are trying to follow yourself
            int m = 0;
            int alreadyfollow = 0;

            // if you are trying to follow yourself
            if ( strcmp(currentUser->username, followname) == 0 )
            {
                printf("You cannot follow yourself.\n");
                alreadyfollow = 1; // switch bool
            }

            // if you find the user you are trying to follow in your following list
            while ( alreadyfollow == 0 && m < currentUser->num_following )
            {
                if ( strcmp(currentUser->following[m], followname) == 0 )
                {
                    printf("You already follow this user. You cannot follow them again.\n");
                    alreadyfollow = 1; // switch bool
                }
                m++; // increment through current user's following list
            }

            // now check if the given user exists, given that you don't already follow them
            int i = 0;
            int found = 0; // bool to see if there is a matching user in userlist
            while (alreadyfollow == 0 && found == 0 && i < twitter_system->filledusers ) // iterate through all existing users
            {
                // if you find a username in the userlist that matches input
                if ( strcmp(twitter_system->userlist[i].username, followname) == 0 )
                {
                    // store matching name in string array of following, at location indexed by number of followers
                    int location1 = currentUser->num_following;
                    strcpy(currentUser->following[location1], twitter_system->userlist[i].username);
                    currentUser->num_following++; //increment their following count (useful to place next follower into follower array)

                    // implement having the other person's follower count and follower list increase
                    int location2 = twitter_system->userlist[i].num_followers; //initially 0
                    strcpy(twitter_system->userlist[i].followers[location2], currentUser->username);
                    twitter_system->userlist[i].num_followers++; //increment follower count

                    printf("You have successfully followed user %s.\n\n", followname);
                    found = 1; // switch bool to jump out of while loop
                }
                i++; // increment while loop to next user in userlist to be checked
            } // exit while loop to check users

            if (alreadyfollow == 0 && found == 0) // if given username is not found in the whole userlist
            { printf("This user doesn't exist. Please try again.\n"); }
        } //end user choice 1

        else if (userChoice == 2) // user wants to print out whole user list
        {
            printf("\n");
            printUsers(twitter_system); // call helper function
            printf("\n");
        }

        // next round of choices in while loop for follow or exit
        printf("Enter 1 to follow a specific user, 2 for the list of users, or any other number to exit.\n");
        scanf("%d", &userChoice);
    }
} //end followUser function

// function to unfollow some other existing user in your following list
void unfollowUser (user *currentUser, twitter *twitter_system)
{
    int userChoice;
    char unfollowname[USR_LENGTH];

    printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
    scanf("%d", &userChoice);

    while (userChoice == 1 || userChoice == 2)
    {
        if (userChoice == 1) // user chooses to unfollow someone
        {
            printf("Enter the name of the user you would like to unfollow: \n");
            fflush(stdin);
            fgets(unfollowname, USR_LENGTH, stdin); // user input for name of person they want to follow

            // error handling for adding string null terminator
            if ( unfollowname[strlen(unfollowname)-1] == '\n')
            { unfollowname[strlen(unfollowname)-1] = '\0'; }

            // now check if the given user exists in the current user's following list
            int i = 0;
            int found = 0; // bool to see if there is a matching user in your following list
            int numfollowing = currentUser->num_following; // no. of users in the following list

            while (i < numfollowing && found == 0) // iterate through whole following list
            {
                if ( strcmp(currentUser->following[i], unfollowname) == 0 ) // if a matching user is found in following list
                {
                    int j = i;
                    while ( (j < numfollowing) && (currentUser->following[j] != NULL) ) // starting from place we found user to be unfollowed
                    {
                        strcpy(currentUser->following[j], currentUser->following[j+1]); // incrementing to next user
                        j++;
                    }
                    strcpy(currentUser->following[j], ""); // place an empty in the last location after carry-overs of following done
                    currentUser->num_following--; // decrement number of following

                    // implement having the other person's follower count and follower list decrease
                    int k = 0;
                    int found2 = 0; // bool to find user in twitter list of users
                    while (k < twitter_system->filledusers && found2 == 0) // iterate through twitter list of users
                    {
                        if ( strcmp(twitter_system->userlist[k].username, unfollowname) == 0 ) // if unfollowed user found
                        {
                            int l = 0;
                            int numfollowers = twitter_system->userlist[k].num_followers; // no. of followers of unfollowed user
                            //iterate through unfollowed user's followers list
                            while ((l < numfollowers) &&  (twitter_system->userlist[k].followers[l] != NULL) )
                            {   //if current user's name is found
                                strcpy(twitter_system->userlist[k].followers[l], twitter_system->userlist[k].followers[l+1]); // overwrite their name
                                l++; // do this for rest of array
                            }
                            strcpy(twitter_system->userlist[k].followers[l], ""); // at the last position of follower list, overwrite extra
                            twitter_system->userlist[k].num_followers--; // decrement unfollowed user's follower count
                            found2 = 1; // bool switch, jump out of inner while loop
                        }
                        k++; // increment inner while loop to next in twitter userlist
                    }

                    found = 1; // bool switch, jump out of outer unfollow while loop
                }
                i++; //increment outer while loop to next in userlist
            }

            if (found == 0) //if user doesnt exist in following list
            { printf("You are not currently following this user. You are unable to unfollow them.\n"); }

            else
            { printf("You have successfully unfollowed user %s.\n\n", unfollowname); }
        } //end user choice 1

        else if (userChoice == 2) //if user wants to print their following list
        {
            printf("\n");
            printf("You are currently following: \n");
            for (int i = 0; i < currentUser->num_following; i++)
            {
                printf("%d: %s\n", i+1, currentUser->following[i]); //just prints their names stored in array as strings
            }
            printf("\n");
        } //end user choice 2

        //next round of choices for follow or exit
        printf("Enter 1 to unfollow a specific user, 2 for the list of your followers, or any other number to exit: \n");
        scanf("%d", &userChoice);
    } //end while loop
} //end unfollow funct

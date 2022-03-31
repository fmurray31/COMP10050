#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);

    for (int i=0; i<twitter_system.filledusers; i++)
    {
        printf("User name is: ");
        printf("%s, ", twitter_system.userlist[i].username);
        printf("with %d followers and %d following\n", twitter_system.userlist[i].num_followers, twitter_system.userlist[i].num_following);
    }

    //implement here the code to print the users
    // for each user you need to print the username, the number of followers and the number of users that the current user is following
    



}

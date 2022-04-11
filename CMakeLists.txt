cmake_minimum_required(VERSION 3.21)
project(twitternick C)

set(CMAKE_C_STANDARD 99)

add_executable(twitternick main.c twitter_create.c twitter_create.h twitter_create_alt.c userchanges.c tweetfunctions.c)

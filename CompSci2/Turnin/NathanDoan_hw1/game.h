/**
 * file:                game.h
 * date modified:       15 August 2024
 * author:              Bryan Fischer, Gonzaga University
 * Description:         Header file for homework one. Contains all function
 *                      definitions for the assignment.
 * 
 *                      ###############################
 *                      ### DO NOT MODIFY THIS FILE ###
 *                      ###############################
*/

#ifndef GAME_H
#define GAME_H

#include<iostream>

using namespace std;

/**
 * Function:        playGame
 * Parameters:      none
 * Return:          none
 * Description:     Contains the main game. Calling this function
 *                  will begin a game, when this function returns
 *                  the game will be over. This function makes calls
 *                  to other functions from this header file.
*/
void playGame();

/**
 * Function:        generateSecretNumber        
 * Parameters:      int min, representing the lower bound
 *                  int max, representing the upper bound
 * Return:          random integer between the min and max parameters
 * Description:     Uses the rand function to generate and return a random number
 *                  between the lower bound and upperbound parameter values.
 *                  E.g. if min is 0, and max is 5, it potentially could return
 *                  0, 1, 2, 3, 4, or 5.
 *                  The random number generater is seeded before this function is called
*/
int generateSecretNumber(int min, int max);

/**
 * Function:        getUserGuess
 * Parameters:      none
 * Return:          int - representing the input guess from the user
 * Description:     This function gets the user's guess as an integer
*/
int getUserGuess();

/**
 * Function:        checkForMatch
 * Parameters:      int userGuess - the guess from the user
 *                  int secretNumber - the number the user is trying to guess
 * Return:          bool 
 *                  - returns true if the user's guess is the same as the
 *                  secret number. 
 *                  - returns false if the user's guess is not the same as the
 *                  secret number.
 * Description:     Checks to see if the user guessed the secret number correctly.
*/
bool checkForMatch(int userGuess, int secretNumber);

#endif
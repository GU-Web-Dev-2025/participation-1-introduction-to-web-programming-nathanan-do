/**
 * file:        arrayProgram.h
 * author:      Bryan Fischer, Gonzaga University CS
 * date:        2024-09-16
 * description: Header file for homework 2
 * 
 */

#ifndef POINTERS_H
#define POINTERS_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/* DO NO MODIFY THIS FILE */

/**
 * function:    runProgram
 * params:      None    
 * returns:     void
 * description: primary program logic. reads data from the "data.dat" file into an int array,
 *              prints the menu, get user input, and continually loops printing the menu
 *              after each user selection is processed. makes appropriate function calls
 *              to other functions. This function is called from main() to begin the program.
 */
void runProgram();

/**
 * function:    printMenu
 * params:      none
 * returns:     void    
 * description: prints the menu of choices to the user, and prompts them to enter a choice.
 *              This function does not get user input, it only prints the menu and asks
 *              for user input. There are 4 choices presented to the user:
 *              1. print the array, 2. print the array as chars, 3. print memory map, and
 *              4. exit. Refer to the homework prompt for an example of how this should look.
 * 
 */
void printMenu();

/**
 * function:    getUserChoice
 * params:      none
 * returns:     void
 * description: gets input from the user. There is not print outs in this function,
 *              it's sole job is to get input from the user. Note: the input buffer
 *              should be cleared when this function is done (no garbage leftover)
 *              hint: getline()
 */
int getUserChoice();

/**
 * function:    readFromFile
 * params:      const string FILE_NAME - representing the name of the file we are reading from
 *              int arr[] - representing the integer array we are storing our values in
 *              const int ARRAY_LENGTH - representing the number of elements in the array
 * returns:     void
 * description: reads integers from a file named FILE_NAME and stores them into an int array.
 *              Each number in the file is expected to be on seperate lines.
 * 
 */
void readFromFile(const string FILE_NAME, int arr[], const int ARRAY_LENGTH);

/**
 * function:    printArray
 * params:      int * arr - a pointer to an integer array containing our values
 *              const int ARRAY_LENGTH - the number of elements in the array
 * returns:     void
 * description: prints the contents of the array arr to the terminal.
 *              Output should be printed on one horizontal line with a space between each value.
 * 
 */
void printArray(int * arr, const int ARRAY_LENGTH);

/**
 * function:    printArrayChars
 * params:      int * arr - a pointer to an integer array containing our values
 *              const int ARRAY_LENGTH - the number of elements in our array
 * returns:     void
 * description: similar to printArray, printArrayChars prints the values of the array
 *              as chars. Output should be printed in one horizontal line with a space between
 *              each char. integers are cast as chars when printing, effectively showing their ASCII
 *              values.
 * 
 */
void printArrayChars(int * arr, const int ARRAY_LENGTH);

/**
 * function:    printMemoryMap
 * params:      int * arr - an int pointer to our integer array
 *              const int ARRAY_LENGTH - the number of elements in the array
 * returns:     void
 * description: Iterates through the array, printing each element of the array to the
 *              terminal, as well as the starting address of the array, and the address
 *              of each element.
 * 
 *              each line prints three things:
 *              ptr address --> address of value | value
 * 
 *              "ptr address" is the memory address of arr, printed in hex
 *              "address of value" is the memory address of the current 
 *                  element we are looking at in the array
 *              "value" is the integer value of the current element we are looking
 *                  at in the array.
 * 
 *              See the homework prompt for an example of how this should look.
 *              Note: your hex values will likely be different than mine.
 * 
 */
void printMemoryMap(int * arr, const int ARRAY_LENGTH);

#endif
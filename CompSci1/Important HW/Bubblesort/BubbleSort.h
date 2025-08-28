#ifndef ARRAY_ASSIGNMENT_H
#define ARRAY_ASSIGNMENT_H

/**
 *  function:       fillArray
 *  params:         array - an interger array
 *                  size - the size of the array
 *                  lowerBound - lowerBound for random number generator
 *                  upperBound - upperBound for random number generator
 *                               Note: [lowerBound, upperBound)
 *  return:         void
 *  description:    function takes an array and fills it with random numbers
 *                  between lowerBound (inclusive) and upperBound (exclusive)
 *                  !Max and min!
 */
void fillArray(int array[], int size, int lowerBound, int upperBound);

/**
 *  function:       doSort  
 *  params:         array - an unsorted integer array
 *                  size - an integer representing the length of the array
 *  return:         void
 *  description:    doSort calls the bubbleSort function
 */
void doSort(int array[], int size);

/**
 *  function:       printArray
 *  params:         array - an integer array
 *                  size - an integer representing the length of the array
 *  return:         void
 *  description:    prints the contents of the array to the terminal.
 *                  Each value should be seperated by a space.
 *                  There should be an opening square bracket at the beginning,
 *                  and a closing square bracket at the end.
 *                  e.g. "[ 4 53 40 58 2 90 65 55 2 69 ]"
 */
void printArray(int array[], int size);

/**
 *  function:       bubbleSort
 *  params:         array - an unsorted integer array
 *                  size - an integer representing the length of the array
 *  return:         void
 *  description:    sort the array from smallest to largest using bubble sort
 *                  Bubble sort must be implemented by hand. When a swap needs
 *                  to occur, make a function call to the swap function.
 */
void bubbleSort(int array[], int size);

/**
 *  function:       swap
 *  params:         array - an integer array
 *                  index1 - an integer representing the first number to swap
 *                  index2 - an integer representing the second number to swap
 *  return:         void
 *  description:    swaps two values in the array by index
 *                  e.g. if index1 is 3, and index2 is 5, and array is:
 *                  [ 4 53 40 58 2 90 65 55 2 69 ]
 *                  swap the numbers 58 and 90
 *                  [ 4 53 40 90 2 58 65 55 2 69 ]
 */
void swap(int array[], int index1, int index2);

#endif
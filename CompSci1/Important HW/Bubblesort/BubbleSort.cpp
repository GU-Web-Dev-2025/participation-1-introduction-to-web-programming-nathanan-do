/**
 * file:            BubbleSort.cpp
 * author:          Nathan Doan
 * date modified:   25 April 2024
 * description:     This program will generate 10 values 0-100 in an array size 10. It will then sort them smallest to largest in value using the bubblesort algorithm
 * 
 */

/*  NOTE:   Do not modify main.
 *          You are not allowed any additional #includes.
 *          You are not allowed to write any additional functions
 *              that are not specified in the .h file.
 *          The only outside function you're allowed to use is rand()
 *              within the fillArray function.
 */

#include<iostream>
#include "BubbleSort.h"

using namespace std;


int main(){

    srand(time(NULL));
  // By seeding this every run, we have a higher chance to generate random numbers

    int myArray[10];
  // Creates an array of "size 10" but can hold 11 different values;

    fillArray(myArray, 10, 0, 100);

    cout << "~~~~~Before Sorting~~~~~" << endl;
    printArray(myArray, 10);
    doSort(myArray, 10);

    cout << "~~~~~After Sorting~~~~~" << endl;
    printArray(myArray, 10);
  
    return 0;
}

// Add functions below
void fillArray(int array[10], int size, int lowerBound, int upperBound){
  for (int i = 0; i < size; i++) {
    array[i] = rand() % upperBound;
}
}


void doSort(int array[10], int size){
  
  for (int i = 0; i < size; i++){ // Runs until reaches 'size'
    // Checks to see if the array needs to be sorted
    if (array[0] < array[1] || array[1] < array[2] || array[2] < array[3] || array[3] < array[4] || array[4] < array[5] || array[5] < array[6] || array[6] < array[7] || array[7] < array[8] || array[8] < array[9]){
      bubbleSort(array, size);
    }
    // If no sorting is needed, function will return to main
    else {
      break;
    } 
  }
}



void printArray(int array[10], int size){
  cout << "The array: ";
  for (int i = 0; i < size; i++){ // Gets the max size of the array, then prints the array's indexies starting from 0 to the max size
    cout << array[i] << " ";
  }
  cout << endl;
}



void bubbleSort(int array[], int size){
  for (int i = 0; i < size - 1; i++){
    for (int j = 0; j < size - i - 1; j++){
      if(array[j] > array[j + 1]){ // if current > next
        int hold = array[j + 1]; // Grabs value of next element
        array[j + 1] = array[j]; // Changes next element to current
        array[j] = hold; // Changes current to next
      }
    }
  }
}




void swap(int array[], int index1, int index2){
  int temp = array[index1]; // Grabs value of next element
  array[index1] = array[index2]; // Changes current to next element 
  array[index2] = temp; // Changes next to current
}
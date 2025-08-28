/*
Name:         Nathan Doan
Date:         2 May 2024
Description:  This program reads numbers from a file, puts them into a vector, and outputs the following information about it: 
  -mean
  -min
  -max
  -count (number of numbers)
*/  
  
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
vector<int> file;
int number, totalnums = 0, min, max;
double mean, totalval = 0;
fstream myFile; // Declare myFile as keyword

myFile.open("numbers.txt"); // Opens the numbers.txt file 
ifstream inputfile("numbers.txt"); // inputfile allows us to recieve the numbers in the file
min = number; // Sets min to first value of vector
  
  // Writing file number's to vector 1 at a time
  while(inputfile >> number){
      
    file.push_back(number); // Adds number to vector while also increasing the index
      
    if (number < min){ // Finds the minimum value of the vector
      min = number;
    }
    if (number > max){ // Finds the maximum value of the vector
        max = number;
    }
      
    totalval += number; // Adds numbers together
    totalnums++; // Counts total numbers
  }
  
  // mean
  mean = totalval / totalnums;
  printf("The mean value of the numbers are: %.2f\n", mean);
  
  // min
  cout << "The minimum value of all the numbers is: " << min << endl;
  
  // max
  cout << "The maximum value of all the numbers is: " << max << endl;
  
  // count (number of numbers)
  cout << "The total amount of numbers are: " << totalnums << endl;

  
  myFile.close();

}
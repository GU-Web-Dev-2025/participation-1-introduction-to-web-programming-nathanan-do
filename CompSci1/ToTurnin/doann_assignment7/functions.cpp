/**
 * file:            Functions.cpp
 * author:          Nathan Doan
 * date:            1 April 2024
 * description:     This code offers 3 options it can do reversing the order of an integer, manually calculate the value of e, and manually raise a base to a power
 */

#include<iostream>
#include "functions.h"

using namespace std;

int main(){

  // Program will not run when switched to false
    bool runProgram = true;
    string menuChoice;

    do{
      // Always will print the menu first
        printMenu();
        getline(cin, menuChoice);
        int choice = stoi(menuChoice);

      // Options to ask the user
        switch(choice){
            case 1:
            {
                string str;
                cout << "Enter a number to reverse:" << endl;
                getline(cin, str);
                int n = stoi(str);
                printReverse(n);
                break;
            }
            case 2:
            {
                string iter;
                double ans;
              
                cout << "Enter a number for iterations:" << endl;
                getline(cin, iter);
                double m = stod(iter);
                ans = calculateE(m);
                cout << "The value of E based on iterations: " << ans << endl;
                break;
            }
            case 3:
            {  
                string base, power;
                int answer;
              
                cout << "Type base value: ";
                  getline(cin, base);
                  int b = stoi(base);
                cout << "(Positive Integers Only) Raised to a power of: ";
                 getline(cin, power);
                 int p = stoi(power);
              answer = calculateExponent(b, p);
              cout << "The calculated value: " << answer << endl;
                break;
            }
            case 4:
            {
              // Will end the program
                runProgram = false;
                cout << "The Program has ended." << endl;
                break;
            }
            default:
            {
                cout << "Please enter a valid menu choice... try again" << endl;
                break;
            }
        }
    }while(runProgram);

    return 0;
}

// Prints menu
void printMenu(){
    string menuPrompt = "";
    menuPrompt += "\n-------------------------------------\n";
    menuPrompt += "1. Print Reverse\n";
    menuPrompt += "2. Calculate E\n";
    menuPrompt += "3. Calculate exponent\n";
    menuPrompt += "4. Quit program\n";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "Enter your choice: ";
    cout << menuPrompt << endl;
}

// Reverses order of integer
void printReverse(int number){
  cout << "Reversified number: ";
  while (number > 0){ 
    int num = number % 10; // extracts ones value
    cout << num; // prints one value
  number = number / 10; // Shifts entire number down by 1 place
  }
  cout << endl;
}

// Manually calculates e
double calculateE(int iterations){
  double iterations2 = iterations;
  int powr = iterations;
  iterations2 = ( 1 + (1 / iterations2));
  double orin = iterations2;
  while (powr > 1){
   iterations2 = iterations2 * orin;
    powr--;
  }
  return iterations2;
}

// Calculates a value with base and exponent
int calculateExponent(int base, int power){
  int original = base;
  while (power > 1){
    base = base * original;  
    power--;
  }
  return base;
}



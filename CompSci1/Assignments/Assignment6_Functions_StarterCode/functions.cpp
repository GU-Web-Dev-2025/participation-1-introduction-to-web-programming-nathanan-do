/**
 * file:            Functions.cpp
 * author:          your name 
 * date:            date you last modified this code
 * description:     write your description here
 */

#include<iostream>
#include "functions.h"

using namespace std;

int main(){

    bool runProgram = true;
    string menuChoice;

    do{
        printMenu();
        getline(cin, menuChoice);
        int choice = stoi(menuChoice);

        switch(choice){
            case 1:
            {
                string str;
                cout << "enter a number to reverse:" << endl;
                getline(cin, str);
                int n = stoi(str);
                printReverse(n);
                break;
            }
            case 2:
            {
                //you implement
                break;
            }
            case 3:
            {
                //you implement
                break;
            }
            case 4:
            {
                //you implement
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

void printMenu(){
    string menuPrompt = "";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "1. Print Reverse\n";
    menuPrompt += "2. Calculate e\n";
    menuPrompt += "3. Calculate exponent\n";
    menuPrompt += "4. Quit program\n";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "Enter your choice: ";
    cout << menuPrompt << endl;
}

void printReverse(int number){
    // you write
    cout << "TODO: Implement printReverse function..." << endl;
}

//write the remaining function implementations here


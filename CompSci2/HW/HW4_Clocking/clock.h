/*
Assignment title:   Homework 4 - Clock Object
Author:             Nathan Doan
Due Date:           28 October, 2024
Last Worked:        28 October, 2024
Class:              CPSC-122-01
*/

#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <iostream>

using namespace std;

class Clock{

    public: 
        
        int hour;
        int minute;
        int second;
        string meridiem;    

        // Default constructor, initiallizes the clock's values
        Clock();

        // Parameterized constructor
        Clock(int hour, int minute, int second, string meridiem);

        // Function to print the time
        void printClock();

        // Used specifically to get a value from the user, check the value, then change the 'hour'
        void getHour(string hour);
        // Used specifically to get a value from the user, check the value, then change the 'minute'
        void getMinute(string minute);
        // Used specifically to get a value from the user, check the value, then change the 'second'
        void getSecond(string second);
        // Calling this function toggles the value of 'meridiem' in the class
        void changeMeridiem();

        // Used specifically to grab any positive integer value
        // Checks the following: is it a string, is the string a char of digits, change to int, is digit between 1-12
        // then adds the amount to the 'hour' adjusting for rollover
        void addhour(string add);

        // Used specifically to grab any positive integer value
        // Checks the following: is it a string, is the string a char of digits, change to int, is digit between 1-60
        // then adds the amount to the 'minute' adjusting for rollover
        void addminute(string add);
        
        // Used specifically to grab any positive integer value
        // Checks the following: is it a string, is the string a char of digits, change to int, is digit between 1-60
        // then adds the amount to the 'second' adjusting for rollover
        void addsecond(string add);

};

// Function to print out a basic menu
void menu();

// Checks user input for the menu, should be between 1-9
int menucheck(string menuchoice);

#endif
/**
 * file:            Assignment2.cpp
 * author:          Nathan Doan
 * date modified:   27 Jan 2024
 * description:     This code calulates the distance a certain percentage of speed from the speed of light can travel in one day
 * 
 */

#include<iostream>
using namespace std;

int main(){

/*
Declaring variables
sol = speed of light (miles/sec)
  */
float 
  sol_100 = 186000,
  sol_1,
  sol_10,
  sol_50,
// 3600 Seconds in an hour, times 24 is seconds per day 
  days = 3600 * 24;


// Calculations for the reduced speed of the speed of light (miles/sec)
// Also calculations for how far it can travel in one day
  sol_1 = sol_100 / 100;
  sol_1 = sol_1 * days;

  sol_10 = sol_100 / 10;
  sol_10 = sol_10 * days;

  sol_50 = sol_100 / 2;
  sol_50 = sol_50 * days;

  sol_100 = sol_100 * days;

// Displays the distance traveled for each reduced percentage of the speed of light travels in one day
cout << "--Light Speed Distance Calculator--" << endl;

  cout << "The distance the speed of light can travel in one day at 1 percent speed is " << sol_1 << endl;

  cout << "The distance the speed of light can travel in one day at 10 percent speed is " << sol_10 << endl;
  
  cout << "The distance the speed of light can travel in one day at 50 percent speed is " << sol_50 << endl;
  
  cout << "The distance the speed of light can travel in one day at 100 percent speed is " << sol_100 << endl;
  
    return 0;
}

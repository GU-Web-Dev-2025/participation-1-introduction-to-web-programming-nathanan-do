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
float operator used to pprevent overflow
  */
const int 
  SOL = 186000;
double
  sol_1,
  sol_10,
  sol_50,
  sol_100,
// 3600 Seconds in an hour, times 24 is seconds per day 
  days = 3600 * 24;

// Calculations for the reduced speed of the speed of light (miles/sec)
// Also calculations for how far we can travel in one day
  sol_1 = SOL / 100;
  sol_1 = sol_1 * days;

  sol_10 = SOL / 10;
  sol_10 = sol_10 * days;

  sol_50 = SOL / 2;
  sol_50 = sol_50 * days;

  sol_100 = SOL * days;

// Displays the distance traveled for each reduced percentage of the speed of light travels in one day
cout << "--Light Speed Distance Calculator--" << endl;

  cout << "The distance the speed of light can travel in one day at 1 percent speed is " << sol_1 << " miles." << endl;

  cout << "The distance the speed of light can travel in one day at 10 percent speed is " << sol_10 << " miles." << endl;
  
  cout << "The distance the speed of light can travel in one day at 50 percent speed is " << sol_50 << " miles." << endl;
  
  cout << "The distance the speed of light can travel in one day at 100 percent speed is " << sol_100 << " miles." << endl;

    return 0;
}

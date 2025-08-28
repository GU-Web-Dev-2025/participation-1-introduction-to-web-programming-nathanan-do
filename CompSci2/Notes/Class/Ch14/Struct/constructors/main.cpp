#include "clock.h"
#include <iostream>

int main(){

// to call default constructor
    Clock myClock;

    std::cout << myClock.hour;
    std::cout << "damn";


// to call parameterized constructor
/*
    Clock myClock(4, 3, 24, "PM");
    // (int h, int m, int s, std::string mm)

    cout << myClock.hour;
*/


    return 0;
}
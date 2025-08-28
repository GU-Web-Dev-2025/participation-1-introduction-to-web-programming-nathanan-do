#include "clock.h"


// by creating "clock" it sets all values below
Clock::Clock(){

    std::cout << "Test bargining";
    hour = 12;
    minute = 0;
    second = 0;
    meridiem = "AM";

// also make variable/obj in heap
}


Clock::Clock(int h, int m, int s, std::string mm){
    hour = h;
    minute = m;
    second = s;
    meridiem = mm;
};

Clock::~Clock(){
    std::cout << "This will read at end of main";
}
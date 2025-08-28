#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <iostream>

class Clock{

    public:
        int hour, minute, second;
        std::string meridiem;

        // Define function in construc.cpp
        // Automatically runs when calling/cloning Clock in main.cpp
        Clock(); // is public
        // the default constructor

        // parameterized constructor
        Clock(int h, int m, int s, std::string mm);
        // can decalre variables as "new" - stored in heap

        // Destructor - PC auto destroys obj if not called manually
        ~Clock();


    private:



};


#endif
#include "clock.h"

// Initiallizing values in default constructor
Clock::Clock(){

    hour = 12;
    minute = 0;
    second = 0;
    meridiem = "AM";

}

// Parameterized constructor
Clock::Clock(int hour, int minute, int second, string meridiem){

    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->meridiem = meridiem;

}

// Print time function
void Clock::printClock(){

    cout << "The time is: ";
    cout << hour << ":" << minute << ":" << second << " " << meridiem;

}

// Print menu function
void menu(){

    cout << "Would you like to," << endl;
    cout << "1. Set Time" << endl;
    cout << "2. Add hour" << endl;
    cout << "3. Add minute" << endl;
    cout << "4. Add second" << endl;
    cout << "5. Set hour" << endl;
    cout << "6. Set minute" << endl;
    cout << "7. Set second" << endl;
    cout << "8. Change AM/PM" << endl;
    cout << "9. Quit" << endl;
    cout << "(Please Enter a Digit): ";

}

// Checks menu input
int menucheck(string menuchoice){

    while (true) {

    // Check if all characters in 'hour' are digits
        bool allDigits = !menuchoice.empty();
        for (char ch : menuchoice) {

            if (!isdigit(ch)) {

                // Reprompts user if invalid menuchoice
                allDigits = false;
                break;

            }
        }

        if (allDigits) {

            // Convert 'hour' to an integer
            int choice = stoi(menuchoice);

            // Check if the integer is within the valid range
            if (choice >= 1 && choice <= 9) {

                return choice;  // Set the class member variable
                                // Exit the loop if valid

            }
        }

        // Prompt again if input is invalid
        cout << "Not an appropriate value. Re-enter a value 1-9: ";
        getline(cin, menuchoice);

    }
}

// Function to change value of the clock's hour
void Clock::getHour(string hour) {

    while (true) {

        // Check if all characters in 'hour' are digits
        bool allDigits = !hour.empty();
        for (char ch : hour) {

            // cout << "Not an appropriate value. Re-enter a value 1-12: "; if anything non-digit is detected
            if (!isdigit(ch)) {

                allDigits = false;
                break;

            }
        }

        if (allDigits) {
        
            // Convert 'hour' to an integer
            int hourInt = stoi(hour);

            // Check if the integer is within the valid range
            if (hourInt >= 0 && hourInt <= 11) {
        
                this->hour = hourInt;  // Set the class member variable
                break;  // Exit the loop if valid
                
            }
        }

        // Prompt again if input is invalid
        cout << "Not an appropriate value. Re-enter a value 1-12: ";
        getline(cin, hour);
    }

}

// Function to change the clock's minute
void Clock::getMinute(string minute){

    while (true) {

        // Check if all characters in 'minute' are digits
        bool allDigits = !minute.empty();
        for (char ch : minute) {

            // If any letter is found, prompts user to re-enter
            if (!isdigit(ch)) {
            
                allDigits = false;
                break;

            }
        }

        if (allDigits) {

            // Convert 'minute' to an integer
            int minInt = stoi(minute);

                // Check if the integer is within the valid range
            if (minInt >= 0 && minInt <= 59) {
                this->minute = minInt;  // Set the class member variable
                break;  // Exit the loop if valid

            }
        }

        // Prompt again if input is invalid
        cout << "Not an appropriate value. Re-enter a value 1-60: ";
        getline(cin, minute);
    }

}

// Function to change Clock's second
void Clock::getSecond(string second){

    while (true) {
        // Check if all characters in 'second' are digits
        bool allDigits = !second.empty();
        for (char ch : second) {

            if (!isdigit(ch)) {

                allDigits = false;
                break;

            }
        }

        if (allDigits) {

            // Convert 'second' to an integer
            int secInt = stoi(second);

            // Check if the integer is within the valid range of 1-60
            if (secInt >= 0 && secInt <= 59) {
                
                this->second = secInt;  // Set the class member variable
                break;  // Exit the loop if valid

            }
        }

        // Prompt again if input is invalid
        cout << "Not an appropriate value. Re-enter a value 1-60: ";
        getline(cin, second);
    }

}

// Function that toggles between 'AM' and 'PM'
void Clock::changeMeridiem(){

    // conditional operator, meridiem = (meridiem == "AM") ? "PM" : "AM";
        // If meridiem currently holds the value "AM", the condition evaluates to true (changes to PM)
        // If meridiem is anything other than "AM" (eg "PM"), the condition evaluates to false (changes to AM)
    meridiem = (meridiem == "AM") ? "PM" : "AM";

}

// Add hour function
void Clock::addhour(string add){

    bool checker = true;
    int addh;

    while (checker) {
        
        // First, checks if all characters in 'add' are digits
        bool allDigits = !add.empty();
        for (char ch : add) {
            
            if (!isdigit(ch)) {

                // If not a digit, reprompts user for a digit
                allDigits = false;
                break;

            }
        }

        if (allDigits) {

            // Convert 'add' to an integer
            addh = stoi(add);
            checker = false;

        }

        // Prompt again if input is invalid
        if (checker){

            cout << "Not an appropriate value. Re-enter a value: ";
            getline(cin, add);

        }
    }

    // Add hours to current 'hour'
    hour += addh;

    // Calculate full 12-hour cycles and remaining hours
    int cycles = hour / 12; // counts 12 hour cycles to determine how many times changemeridiem() should be toggled
    int remainder = hour % 12;

    // Toggle meridiem for each full 12-hour cycle
    for (int i = 0; i < cycles; ++i) {

        meridiem = (meridiem == "AM") ? "PM" : "AM";

    }

    // Adjust 'hour' to fit within a 12-hour format
    hour = (remainder == 0) ? 12 : remainder;

    // Final meridiem adjustment if 'hour' goes from AM to PM (or vice versa)
    if (addh % 24 >= 12) {

        meridiem = (meridiem == "AM") ? "PM" : "AM";

    }

}

// Function to add minutes
void Clock::addminute(string add){
    
    bool checker = true;
    int addm;

    while (checker) {

        // Check if all characters in 'add' are digits
        bool allDigits = !add.empty();
        for (char ch : add) {

            if (!isdigit(ch)) {

                allDigits = false;
                break;

            }
        }

        if (allDigits) {
            
            // Convert 'add' to an integer
            addm = stoi(add);
            checker = false;

        }

        // Prompt again if input is invalid
        if (checker){

            cout << "Not an appropriate value. Re-enter a value: ";
            getline(cin, add);

        }
    }
    
    // Add minutes to current minute
    minute += addm;

    // Calculate neccessary hours to add and remaining minutes
    int extraHours = minute / 60;
    minute %= 60;

    // Add extra hours to current 'hour'
    hour += extraHours;

    // Calculate full 12-hour cycles and the remainder hours
    int cycles = hour / 12;
    int remainder = hour % 12;

    // Toggle meridiem for each full 12-hour cycle
    for (int i = 0; i < cycles; ++i) {

        meridiem = (meridiem == "AM") ? "PM" : "AM";

    }

    // Adjust hour to fit within a 12-hour range
    hour = (remainder == 0) ? 12 : remainder;

    // Final meridiem adjustment in case extra hours span AM to PM or vice versa
    if (extraHours % 24 >= 12) {

        meridiem = (meridiem == "AM") ? "PM" : "AM";

    }

}

// Function for adding seconds
void Clock::addsecond(string add){

    bool checker = true;
    int adds;

    while (checker) {

        // Check if all characters in 'hour' are digits
        bool allDigits = !add.empty();
        for (char ch : add) {

            if (!isdigit(ch)) {

                allDigits = false;
                break;

            }
        }

        if (allDigits) {

            // Convert 'add' to an integer
            adds = stoi(add);
            checker = false;

        }

        // Prompt again if input is invalid
        if (checker){

            cout << "Not an appropriate value. Re-enter a value: ";
            getline(cin, add);

        }
    }
    
    // adds all seconds to 'second'
    second += adds;

    // Calculate rollovers
    int extraMinutes = second / 60;
    // Update seconds to be within 0-59 range
    second %= 60;  

    // Add the extra minutes to the current minute
    minute += extraMinutes;
    int extraHours = minute / 60;
    // Update minutes to be within 0-59 range
    minute %= 60;

    // Add the extra hours to the current hour
    hour += extraHours;

    // Calculate the number of 12-hour cycles for hour rollover
    int cycles = hour / 12;
    hour = (hour % 12 == 0) ? 12 : hour % 12;  // Adjust hour to fit within 1-12 range

    // Toggle AM/PM for each 12-hour cycle
    for (int i = 0; i < cycles; ++i) {

        meridiem = (meridiem == "AM") ? "PM" : "AM";

    }
}

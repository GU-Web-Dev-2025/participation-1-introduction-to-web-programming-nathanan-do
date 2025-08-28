#include "clock.h"
#include <iostream>
#include <cctype>

int main() {
    
    Clock myClock;

    
    bool digCheck = true, meridiemtf = true;


    do{

        // generalchoice is used to store values for adding/setting
        string menuchoice, generalchoice, choicehour, choiocemin, choicesec, meridiemchoice;
        int choice;

        // Will always print out time when printing menu
        cout << "Welcome to YourOwn(tm) Clock!\nThe current time is: ";
        myClock.printClock(); cout << endl;
        menu();
        getline(cin, menuchoice);
        choice = menucheck(menuchoice);
        
/*   My menu has the following options
        1. Set Time
        2. Add Hour
        3. Add Minute
        4. Add Second
        5. Set Hour
        6. Set Minute
        7. Set Second
        8. Change AM/PM
        9. Quit 
*/
        switch(choice){

            case 1: // 1. Set Time

                    cout << "Set the current time\nFirst, insert hour(s): ";
                    getline(cin, choicehour);
                    myClock.getHour(choicehour);

                    cout << "Next, enter minute(s): ";
                    getline(cin, choiocemin);
                    myClock.getMinute(choiocemin);

                    cout << "Next, set second(s): ";
                    getline(cin, choicesec);
                    myClock.getSecond(choicesec);

                    cout << "Finally, AM or PM: ";
                    getline(cin, meridiemchoice);
                    while (meridiemchoice != "AM" && meridiemchoice != "am" && meridiemchoice != "Am" && meridiemchoice != "aM" && meridiemchoice != "PM" && meridiemchoice != "pm" && meridiemchoice != "Pm" && meridiemchoice != "pM"){
                        cout << "Please type ''AM'' or ''PM'' please: ";
                        getline(cin, meridiemchoice);
                    }
                    if (meridiemchoice == "AM" || meridiemchoice == "am" || meridiemchoice == "Am" || meridiemchoice == "aM"){
                        if (myClock.meridiem == "AM"){
                                break;
                        }else
                        myClock.changeMeridiem();
                        break;
                    }
                     if (meridiemchoice == "PM" || meridiemchoice == "pm" || meridiemchoice == "Pm" || meridiemchoice == "pM"){
                        if (myClock.meridiem == "PM"){
                                break;
                        }else
                        myClock.changeMeridiem();
                        break;
                    }
                    break;

            case 2: // 2. Add Hour

                    cout << "Enter the amount of hours to add to the clock: ";
                    getline(cin, generalchoice);
                    myClock.addhour(generalchoice);
                    cout << "Successfully added." << endl;
                    break;

            case 3: // 3. Add Minute

                    cout << "Enter the amount of minutes to add to the clock: ";
                    getline(cin, generalchoice);
                    myClock.addminute(generalchoice);
                    cout << "Successfully added." << endl;
                    break;

            case 4: // 4. Add Second

                    cout << "Enter the amount of seconds to add to the clock: ";
                    getline(cin, generalchoice);
                    myClock.addsecond(generalchoice);
                    cout << "Successfully added." << endl;
                    break;

            case 5: // 5. Set Hour

                    cout << "Set the hour. Insert hour(s): ";
                    getline(cin, generalchoice);
                    myClock.getHour(generalchoice);
                    cout << "Successfully Set." << endl;
                    break;

            case 6: // 6. Set Minute

                    cout << "Set the minute. Insert minute(s): ";
                    getline(cin, generalchoice);
                    myClock.getMinute(generalchoice);
                    cout << "Successfully Set." << endl;
                    break;

            case 7: // 7. Set Second

                    cout << "Set the second. Insert second(s): ";
                    getline(cin, generalchoice);
                    myClock.getSecond(generalchoice);
                    cout << "Successfully Set." << endl;
                    break;

            case 8: // 8. Change Meridiem

                    myClock.changeMeridiem();
                    cout << "Meridiem changed to: " << myClock.meridiem << endl;
                    break;

            case 9: // 9. Exit

                    digCheck = !digCheck;
                    cout << "Exiting Program";
                    break;

        }

    }while(digCheck); // digCheck = false; when case 9

return 0;

}
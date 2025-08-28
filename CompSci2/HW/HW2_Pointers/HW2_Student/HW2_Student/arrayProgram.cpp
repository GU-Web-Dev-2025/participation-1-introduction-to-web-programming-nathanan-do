#include<iostream>
#include<string>
#include<fstream>
#include "arrayProgram.h"

using namespace std;

/* Write your code in this file. Use ONLY the functions provided in the .h file */
/**
 * function:    runProgram
 * params:      None    
 * returns:     void
 * description: primary program logic. reads data from the "data.dat" file into an int array,
 *              prints the menu, get user input, and continually loops printing the menu
 *              after each user selection is processed. makes appropriate function calls
 *              to other functions. This function is called from main() to begin the program.
 */

void runProgram(){
    using namespace std;
    
    int numArr[7];
    int *arrpntr = nullptr;
    int choice;

    bool menu = true;

    const string thefile = "data.dat";

    fstream infile;
    infile.open("data.dat");

    readFromFile(thefile, numArr, 7);
    arrpntr = numArr;

    do{

        printMenu();
        choice = getUserChoice();

        while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
            cout << "Re-enter A Number: ";
            choice = getUserChoice();
        }
            
            if (choice == 1){

                printArray(arrpntr, 7);

            }

            else if (choice == 2){

                printArrayChars(arrpntr,7);

            }
            
            else if (choice == 3){

                printMemoryMap(arrpntr, 7);

            }

            else if (choice == 4){

                cout << "You've quit";
                menu = false;

            }
            else {
                cout << "Something went wrong";
            }

        cout << endl;
    
    }while(menu==true);

    infile.close();

}

/**
 * function:    printMenu
 * params:      none
 * returns:     void    
 * description: prints the menu of choices to the user, and prompts them to enter a choice.
 *              This function does not get user input, it only prints the menu and asks
 *              for user input. There are 4 choices presented to the user:
 *              1. print the array, 2. print the array as chars, 3. print memory map, and
 *              4. exit. Refer to the homework prompt for an example of how this should look.
 * 
 */
void printMenu(){
    using namespace std; 

        cout << "\nWelcome to the Pointer Program. Read the following options and make a choice." << endl << 
     "1. print the array\n2. print the array as chars \n3. print memory map\n4. exit \nYOUR CHOICE: ";

};

/**
 * function:    getUserChoice
 * params:      none
 * returns:     void
 * description: gets input from the user. There is not print outs in this function,
 *              it's sole job is to get input from the user. Note: the input buffer
 *              should be cleared when this function is done (no garbage leftover)
 *              hint: getline()
 */
int getUserChoice(){
    using namespace std;
    string choice; 
    int r;

    getline(cin, choice);

    r = stoi(choice);

    return r;

};

/**
 * function:    readFromFile
 * params:      const string FILE_NAME - representing the name of the file we are reading from
 *              int arr[] - representing the integer array we are storing our values in
 *              const int ARRAY_LENGTH - representing the number of elements in the array
 * returns:     void
 * description: reads integers from a file named FILE_NAME and stores them into an int array.
 *              Each number in the file is expected to be on seperate lines.
 * 
 */
void readFromFile(const string FILE_NAME, int arr[], const int ARRAY_LENGTH){
    using namespace std;
    fstream reads;
    string strarr[ARRAY_LENGTH];

    reads.open(FILE_NAME);

    int i = 0;
    while (reads >> strarr[i] && i < ARRAY_LENGTH) {
        arr[i] = stoi(strarr[i]);
        i++;
    }

    reads.close();
    cout << "\nOPERATION READ CO";
};

/**
 * function:    printArray
 * params:      int * arr - a pointer to an integer array containing our values
 *              const int ARRAY_LENGTH - the number of elements in the array
 * returns:     void
 * description: prints the contents of the array arr to the terminal.
 *              Output should be printed on one horizontal line with a space between each value.
 * 
 */
void printArray(int * arr, const int ARRAY_LENGTH){
    using namespace std;

    

    for(int i = 0; i < ARRAY_LENGTH; i++){
        cout << arr[i] << " ";
    }

};

/**
 * function:    printArrayChars
 * params:      int * arr - a pointer to an integer array containing our values
 *              const int ARRAY_LENGTH - the number of elements in our array
 * returns:     void
 * description: similar to printArray, printArrayChars prints the values of the array
 *              as chars. Output should be printed in one horizontal line with a space between
 *              each char. integers are cast as chars when printing, effectively showing their ASCII
 *              values.
 * 
 */
void printArrayChars(int * arr, const int ARRAY_LENGTH){

    for (int i = 0; i < ARRAY_LENGTH; i++){
        cout << char(arr[i]) << " ";
    } 

};

/**
 * function:    printMemoryMap
 * params:      int * arr - an int pointer to our integer array
 *              const int ARRAY_LENGTH - the number of elements in the array
 * returns:     void
 * description: Iterates through the array, printing each element of the array to the
 *              terminal, as well as the starting address of the array, and the address
 *              of each element.
 * 
 *              each line prints three things:
 *              ptr address --> address of value | value
 * 
 *              "ptr address" is the memory address of arr, printed in hex
 *              "address of value" is the memory address of the current 
 *                  element we are looking at in the array
 *              "value" is the integer value of the current element we are looking
 *                  at in the array.
 * 
 *              See the homework prompt for an example of how this should look.
 *              Note: your hex values will likely be different than mine.
 * 
 */
void printMemoryMap(int * arr, const int ARRAY_LENGTH){
    cout << "KEY:\nptr address --> address of value | value\n";

    for (int i = 0; i < ARRAY_LENGTH; i++){
        cout << arr << " --> " << &arr[i] << " | "<< arr[i] << endl;
    }
    
};
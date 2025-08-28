/*
Name:           Nathan Doan
Last Worked:    Jan 26, 2025       
Assignment:     Homework 1 - This program will print out the size of the following variables: char, bool, int, float, and double
Class:          260 Computer Organization Sec. 2 - FISCHER
*/

#include <stdio.h>      // i/o library (https://www.w3schools.com/c/c_output.php)
#include <stdbool.h>    // boolean library

int main () {
    char charSize;
    bool boolSize;
    int intSize;
    float floatSize;
    double doubleSize;

    // sieof function returns 'long' variable, therefore using '%lu' allows to print out the size in bytes
    // without '%lu' - nocompile or junk output
    // "A printf format specifier follows the form %[flags][width][.precision][length]specifier" (https://stackoverflow.com/questions/23852073/whats-the-difference-between-ul-and-lu-c-format-specifiers)
    printf("The size of a char in bytes: %lu\n", sizeof(charSize));
    printf("The size of a bool in bytes: %lu\n", sizeof(boolSize));
    printf("The size of an int in bytes: %lu\n", sizeof(intSize));
    printf("The size of a float in bytes: %lu\n", sizeof(floatSize));
    printf("The size of a double in bytes: %lu\n", sizeof(doubleSize));
    
    return 0;
}

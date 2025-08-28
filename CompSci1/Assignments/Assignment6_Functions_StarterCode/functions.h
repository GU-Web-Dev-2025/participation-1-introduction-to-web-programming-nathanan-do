
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


    /*  Function:       printReverse
    *  Params:         int - the number to reverse
    *  Return:         void
    *  Description:    prints the number given by the input
    *                  param in reverse. e.g. 1234 -> 4321
    */
    void printReverse(int number);

    /*  Function:       calculateE
    *  Params:         int - number of iterations to calculate
    *  Return:         double - the approximation of e
    *  Description:    Calculate the approximate value of e given n iterations.
    *                  The value of e can be approximated using 
    *                  (1 + 1 / n) to the power of n, where n = iterations
    *                  The larger the value of n, the closer we can approximate e
    * 
    *                  Note: You cannot use arrays, strings, or any functions,
    *                          you must brute force the answer yourself.
    */
    double calculateE(int iterations);

    /*
    *  Function:       calculateExponent
    *  Params:         int - the base
    *                  int - the power we are raising the base to
    *                  e.g. for 2 raised to the power of 3:
    *                      base would be 2 and power would be 3
    *  Return:         int - the resulting exponentiation of the base and power
    *  Description:    The function takes a number and raises it to a power and
    *                  returns the result. This is kind of like your own implementation
    *                  of the "pow" function we've used earlier.
    * 
    *                  Note:   You must do this by hand yourself, and cannot 
    *                          use any functions or math libraries.
    */
    int calculateExponent(int base, int power);

    /*
    *  Function: printMenu();
    *  This function is provided for you, do not modify.
    *  When this function is called it will print the menu.
    */
    void printMenu();

#endif
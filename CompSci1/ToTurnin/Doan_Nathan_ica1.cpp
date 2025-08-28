/*  file:           main.cpp
 *  date:           2 February 2024
 *  author:         Nathan Doan
 *  description:    This code calculates the total interest on my dream car (Porsche GTR3 RS)
 * 
 * 
 * 
 * */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){

    string buyerName;
    string dreamCar;
    double carCost;
    double apr, monthlyIR;
    int monthsFinanced;
    double monthlyPayment;
    double totalInterest;

    // TODO: 
    // calculate monthly payment
    // calculate total interest paid
    // output:
    //       Congratulations <buyer's name here> on buying a <dreamCar here>!
    //       Your monthly payment is xxx.xx and your total interest paid is xxx.xx

    // TIP:  Use pow for exponents. This is why we #include<math.h>
    //       Example: 
    //       pow(a, b) mean a raised to the power of b
    //       pow(2, 2) would return 4
    //       pow(2, 3) would return 8
    //       pow(3, (2 + 1)) would evaluate to be pow(3, 3) which returns 27

    // Research:
    // -Find out how much your dream car cost
    // -Find out what current interest rates are (this is APR)
    // -You pick how many months to finance, somewhere between 48 to 72 months is reasonable

    // Code your solution below!

    // Defining variables
buyerName = " Nathan Doan";
dreamCar = " Porsche GTR3 RS";
carCost = 336440;
apr = 7.74;
monthsFinanced = 60;
  
    // Calculations for monthly interest rates
  monthlyIR = apr/1200;
  
    // Calculations for monthly payments
  monthlyPayment = ((monthlyIR * carCost) / (1 - pow(1 + monthlyIR, -monthsFinanced)));
  
    // Calculations for total interest by subtracting (monthly payments*months financed) from original cost of car
  totalInterest = (monthlyPayment * monthsFinanced) - carCost; 

    // Print answer
  cout << "Congratulations" << buyerName << " on buying a" << dreamCar << "!" << endl 
    << "Your monthly payment is $" << monthlyPayment << " and your total interest paid is $" << totalInterest << endl;

    return 0;
}
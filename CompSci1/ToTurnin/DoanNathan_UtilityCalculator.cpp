/**
 * file:            UtilityCalculator.cpp
 * author:          Nathan Doan
 * date modified:   13 February 2024
 * description:     This program calculates the amount of money owed to a water company. It has set rates and an initial base fee for the amount of water used (in gallons) that vary based on city zoning (See below):
  Code 'r' or 'R' (residential): $15.00 base fee plus $0.0005 per gallon used
  Code 'c' or 'C' (commercial): $1000.00 base fee plus $0.00002 for each gallon used
  Code 'i' or 'I' (industrial): $2000.00 base fee plus $0.00002 for each gallon used
*/

#include<iostream>

using namespace std;

int main(int argc, char *argv[]){

  // Declaring variables
    char customerCode;
    int meterStart, meterEnd, water_usage, oldmeterStart;
    double usage_gal, costTotal;

  // Prints banner/title for program
    string bannerMessage;
    bannerMessage += "+-----------------------+\n";
    bannerMessage += "|  Utility  Calculator  |\n";
    bannerMessage += "+-----------------------+\n";
    cout << bannerMessage << endl;

  // Prompts the user to enter the starting value of the water meter
  cout << "The water meter measuring usage of water is measured in gallons\nEnter positive integer values for the 9-digit water reader\nPlease enter the starting value of the water meter: ";
  cin >> meterStart; 
  // "oldmeterStart" is used to display the starting value of the water meter if the value rolls over the 9-digit marker
  oldmeterStart = meterStart;

  // Prompts the user to enter the ending value of the water meter
  cout << "Please enter the ending value of the water meter: ";
  cin >> meterEnd;
  
  // Prompts the user to enter the customer/city code
  cout << "Finally, enter the customers code: ";
  cin >> customerCode;
  // If the useer does not enter the correct customer/city code, it will continue to prompt the user to enter a valid code
  while (customerCode != 'r' && customerCode != 'R' && customerCode != 'i' && customerCode != 'I' && customerCode != 'c' && customerCode != 'C'){
   cout << "Please enter a valid Customer Code: ";
   cin >> customerCode;
  }
 
  // Math to calculate the amount of water used in gallons if the ending meter is larger than the starting meter
  if (meterEnd > meterStart) {
    water_usage = meterEnd - meterStart;
    usage_gal = water_usage / 10.0;  
  }
  
  // Math to calculate the amount of water used in gallons if the starting meter is larger than the ending meter
  if (meterEnd < meterStart) {
    meterStart = 1000000000 - meterStart;
    water_usage = meterStart + meterEnd;
    usage_gal = water_usage / 10.0;
  }

  // If no water was used
  else if (meterEnd == meterStart) {
    cout << "\nNo water was used\n";
  }

  // Displays the output based on the user's values and zoning they choose
  // For code 'R' or 'r'
  if (customerCode == 'r' || customerCode == 'R'){
    costTotal = 15.00 + (.0005 * usage_gal);
    cout << "\nCustomer Code: " << customerCode << endl
         << "Begining of Meter Reading: " << oldmeterStart << endl
         << "Ending of Meter Reading: " << meterEnd << endl
         << "Gallons of water used: " << usage_gal << endl;
    cout << "The total cost for this resident is $" << costTotal << endl;
  }

  // For code 'i' or 'I'
  if (customerCode == 'i' || customerCode == 'I'){
    costTotal = 2000.00 + (.00002 * usage_gal);
    cout << "\nCustomer Code: " << customerCode << endl
         << "Begining of Meter Reading: " << oldmeterStart << endl
         << "Ending of Meter Reading: " << meterEnd << endl
         << "Gallons of water used: " << usage_gal << endl;
    cout << "The total cost for this industry is $" << costTotal << endl;
  }

  // For code 'c' or 'C'
  if (customerCode == 'c' || customerCode == 'C'){
    costTotal = 1000.00 + (.00002 * usage_gal);
    cout << "\nCustomer Code: " << customerCode << endl
         << "Begining of Meter Reading: " << oldmeterStart << endl
         << "Ending of Meter Reading: " << meterEnd << endl
         << "Gallons of water used: " << usage_gal << endl;
    cout << "The total cost for this commercial building is $" << costTotal << endl;
  }
    return 0;
}
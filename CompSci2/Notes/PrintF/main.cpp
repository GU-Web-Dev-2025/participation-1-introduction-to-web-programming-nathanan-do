#include <iostream>
using namespace std;

int main() {

  /* // AUGMENTED ASSIGNMENT
int x = 5;
int y = 6;
int z = x = y;
  // output for z is '6' (read right to left)

// When using loops, it's common to add 1 ('x += 1' or 'x++' or '++x')
  // FOR PRINTING (cout << ++x/x++;)
  // pre increment op (first add 1, then use x): ++x
  // post increment op (first use x, then add 1): x++

  */


  
  /* // PRECISION SET AND PRINTF
  double num = 1234.5678;

// normally, this would cut off a portion of the variable and round

  printf("num: %f\n", num); // Standard printing precision value

  // "num: %f\n" is known as format specifier
  // the "num" is the variable being outputted
  // %f is operator, num for assignment variable
  // between '%' and 'f' insert a decimal place you want. EG '.4' for 4 decimal places
  // common formatting with %f: %d (integers), %s (strings), %f double;

  */



  /* // GETLINE
  string str;
  int num;
  cout << "Give: ";
  getline(cin, str); 
  // cin for operator, str for assignment variable (allows for spaces, but removes '\' command (e.g. \n will not work while typing in getline))
  // Therefore, use stoi() func "string to integer" or stod() "string to double"
  num = stoi(str);
  cout << "str: " << str << endl << ++num << endl;
  // does not work well with int  
*/



  
/* RANDOM NUMBER GENERATOR
// Note: rand() is seeded, therefore trying to reuse/running code again will produce the same number
  // therefore using srand("some number") will use a random seed to produce a procedurally generated number, still not neccessarily random
  // to have a larger "randomness" use srand(time(NULL)) which uses the time of the computer for seed 
  // By "modding" rand() by any number (eg rand() % 10) will yield a random number 0-9 because 10%10 is 0
  // to get a random number from a range (eg 50-100) use "rand() % (max-min) + min"
int num;
  srand(time(NULL));
  num = rand();
  printf("Num is: %d\n", num);
*/


  
/* Switch statements
  char chioce;
  cout << "Enter a chioce letter (A, B, C): ";
  cin >> chioce;

  // "break" goes outside the brackets {} and follows the next command
  switch(chioce){
    case 'A': cout << "You entered 'A'";
              break;
    case 'B': cout << "You entered 'A'";
              break;
    case 'C': cout << "You entered 'A'";
              break;
    default: cout << "Broke";
  }
*/



  /*// Loops
  // general formatting for(initialize; test; update) e.g:
  // use "ctrl + c" to stop running command
  for (int i; i <10; i++){
    for (int j; j <10; j++){
      cout << "word ";
    }
    cout << endl;
  }

  for (int j; j <100; j++){
    cout << "word ";
    // use "mod" instead of nested loops
    if (j % 1){
      cout << endl;
    }
  }
*/
  
  return 0;
}
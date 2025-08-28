/**
 * file:            main.cpp
 * author:          Nathan Doan
 * date modified:   20 March 2024
 * description:     The main function of this program is to be able to generate a number on a given interval to use as a "point of reference" for an imaginary tank. Furthermore, it will prompt the user to input both an angle and velocity to estimate the tanks distance in 3 attempts. This is a remake of some classic tank game we all know and enjoy.
*/

#include <iostream>
#include <string>   // For getline function
#include <cmath>    // For cos function
#include <cstdlib>  // For rand() and srand() functions
#include <ctime>    // For time() 


using namespace std;

int main()
{
    double velocity = 0.0;
    double angle = 0.0;
    int bullet = 0, tankPosition = 0;
    string difficulty;
    bool win = 0;
    int roundNumber = 1;

    string banner;
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    banner += "  _______          _      ____        _   _   _       \n";
    banner += " |__   __|        | |    |  _ \\      | | | | | |      \n";
    banner += "    | | __ _ _ __ | | __ | |_) | __ _| |_| |_| | ___  \n";
    banner += "    | |/ _` | '_ \\| |/ / |  _ < / _` | __| __| |/ _ \\ \n";
    banner += "    | | (_| | | | |   <  | |_) | (_| | |_| |_| |  __/ \n";
    banner += "    |_|\\__,_|_| |_|_|\\_\\ |____/ \\__,_|\\__|\\__|_|\\___| \n";
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << banner << endl << endl;

  
  
  // Prompts the user to enter a difficulty
  cout << "Choose your diffuculty: \nA) EASY\nB) NORMAL\nC) HARD\nChoice: ";
  getline(cin, difficulty);


// Short description of the game and rules
  cout << "Your objective is to hit a tank placed between 100-200 units away.\nYou are placed at 0 units. You have 3 attempts to hit the tank or else, YOU LOSE.\n";
    

// Randomly generates the position of the tank using the current time as a seed
  srand(static_cast<unsigned>(time(NULL)));
  tankPosition = 100 + (rand() % 101);



// Makes the maximum allowed attempts for firing 3
while (roundNumber <= 3){

  cout << "\nYou chose ";

// "EASY" option for game
if (difficulty == "a" || difficulty == "A"){
  cout << "'EASY' difficulty, your shot has to land within 20 units from the tank.\n";  

  
// States the round for the player
    cout << "\nROUND: " << roundNumber << endl;

  
// Prompts the user to insert their best guesses to launch the projectile
  cout << "Choose an angle (in deggrees) to shoot from: ";
    cin >> angle;
  cout << "Choose a velocity to shoot from: ";
    cin >> velocity;


// Calculates where the projectile will land in the horizontal direction
    bullet = velocity * cos((angle*3.14/180));
    cout << "\nYour shot lannded at " << bullet << " units." << endl;


// Tells the user if they shot too short or too far
  if (bullet < tankPosition - 20){
    cout << "SHOT LANDED SHORT\n";
  }
// If the player wins, the round count will go to 3, immediately ending the game
  if (bullet >= tankPosition - 20 && bullet <= tankPosition + 20){
    cout << "DIRECT HIT\nThe tank was located at " << tankPosition << " units. Congrats. YOU WON!\n";
      roundNumber = 4;
       win = 1;
  }
  if (bullet > tankPosition + 20){
      cout << "SHOT LANDED OVER\n";
  }


      
}


  // "NORMAL" option for game
if (difficulty == "b" || difficulty == "B"){
  cout << "'NORMAL' difficulty, your shot has to land within 10 units from the tank.\n";  

    cout << "\nROUND: " << roundNumber << endl;


  cout << "Choose an angle (in deggrees) to shoot from: ";
    cin >> angle;
  cout << "Choose a velocity to shoot from: ";
    cin >> velocity;


    bullet = velocity * cos((angle*3.14/180));
    cout << "\nYour shot lannded at " << bullet << " units." << endl;


  if (bullet < tankPosition - 10){
    cout << "SHOT LANDED SHORT\n";
  }
  if (bullet >= tankPosition - 10 && bullet <= tankPosition + 10){
  cout << "DIRECT HIT\nThe tank was located at " << tankPosition << " units. Congrats. YOU WON!\n";
    roundNumber = 4;
    win = 1;
  }
  if (bullet > tankPosition + 10){
      cout << "SHOT LANDED OVER\n";
  }


  
}


  // "HARD" option for game
if (difficulty == "C" || difficulty == "c"){
  cout << "'HARD' difficulty, your shot has to land within 5 units from the tank.\n";  


    cout << "\nROUND: " << roundNumber << endl;


  cout << "Choose an angle (in deggrees) to shoot from: ";
    cin >> angle;
  cout << "Choose a velocity to shoot from: ";
    cin >> velocity;


    bullet = velocity * cos((angle*3.14/180));
    cout << "\nYour shot lannded at " << bullet << " units." << endl;


  if (bullet < tankPosition - 5){
    cout << "SHOT LANDED SHORT\n";
  }
  if (bullet >= tankPosition - 5 && bullet <= tankPosition + 5){
    cout << "DIRECT HIT\nThe tank was located at " << tankPosition << " units. Congrats. YOU WON!\n";
      roundNumber = 4;
      win = 1;
  }
  if (bullet > tankPosition + 5){
      cout << "SHOT LANDED OVER\n";
  }
}


   roundNumber++;
}


  // End screen, two options: win/lose
  if (win == 1){
    cout << "\nThe game has ended with you victorious!\n";
  }
  else {
    cout << "\nYou lost.\nThe tank was located at " << tankPosition << " units.\n";
  }

    return 0;
}

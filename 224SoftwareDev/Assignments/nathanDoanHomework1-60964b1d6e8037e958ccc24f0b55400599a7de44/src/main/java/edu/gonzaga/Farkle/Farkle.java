/**
 *  Zag Farkle - Gonzaga Farkle game
 *  CPSC 224 Class Project
 * 
 *  Author:Jaxon
 *  Copyright year:2024
 * 
 *  Summary:Farkle
 *  Do not touch: 
 */

// Java packaging - specifies directory and Java project namespace
package edu.gonzaga.Farkle;

// Scanner library enables the ability to read inputs from the user terminal.
import java.util.Scanner;

/*
 *  This is the main class for the Farkle project.
 *  It really should just instantiate another class and run
 *   a method of that other class.
 */

/** Main program class for launching Farkle program. */
public class Farkle {
    // This main is where your Farkle game starts execution for general use.
    public static void main(String[] args) {
        
        System.out.println("Hello Player! Welcome to Zarkle!");

        Farkle game = new Farkle();
        game.playGame();


    }

    /**
     * Plays the Game:
     */
    public void playGame() {

         // 1. Check for a farkle at the start of a "game" by generatign a secret hand of dice:
        // This also will be the section where you display the sorted hand and tallied faces
        // specified for this version of the game.

        // Create secret hand of 6 dice:
        Hand newHand = new Hand();

        // Randomize the value of each die:
        newHand.roll();
        // HERE, I suggest making a secret meld to check for farkle before you even think about displaying the menu.


        /* 2. Interperet the values of the die and display them. check for Farkles,
         * ending the game immediately if any appear.
         * 
         * Additionally: The roll of your hand must be displayed in order from least to greatest
         * (using bubble sort / some other method?),
         * Additionally: The total count of dice that rolled each side must be tallied.
        */
        newHand.sortCurrentHand(); //WARNING: THIS IS ALSO CALLED IN DISPLAYHAND()!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        newHand.tallySides();
        
        //Display hand and the number of die that rolled each side:
        newHand.displayCurrentHand();

        /* 3. Prompt the user to select which dice they wish to meld, note that any dice
        selceted to meld should update the score field. */
        Meld newMeld = new Meld();
        System.out.println( newMeld.getScore() );
        System.out.println( newMeld.isFarkle() );
        
        //newMeld.addDiceToMeld( newHand.getCurrentHandSide(3) );
        
        runMeldMenu();

        // 4. Bank the user's dice and update their score:

        return;
    }


    /* 
        Scanner userInputScanner = new Scanner(System.in);

        String userInput = userInputScanner.nextLine();

        System.out.println(userInput);
    */


    /**
     * Displays the Meld menu and loops until the player either banks or quits, then calls for the score
     * to be updated accordingly.
     */
     public void runMeldMenu() {

        // Display meld menu:
        System.out.println("*************************** Current hand and meld *******************");
        System.out.println(" Die   Hand |   Meld");
        System.out.println("------------+---------------");
        
        // Load dice from the players hand into the meld array and display this change:
        
        // Provides the letter given to each dice displayed.
        char diceLetter = 64;
        for ( int i = 0; i < 6; i++ ) {
            diceLetter += 1;
            System.out.println( " [" + diceLetter + "]    ");
        }
        
        
        System.out.println("");
    }
}


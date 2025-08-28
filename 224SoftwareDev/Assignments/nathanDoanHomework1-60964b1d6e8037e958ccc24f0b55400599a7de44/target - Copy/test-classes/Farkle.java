/**
 *  Zag Farkle - Gonzaga Farkle game
 *  CPSC 224 Class Project
 * 
 *  Author:Jaxon
 *  Copyright year:2024
 * 
 *  Summary:Farkle
 * 
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
        Scanner scanner = new Scanner(System.in);
        Hand newHand = new Hand();
        Meld newMeld = new Meld();
        int totalScore = 0;
        boolean gameOver = false;

        while (!gameOver) {
            // Reset the meld for the new turn
            newMeld = new Meld(); // Reset meld for each turn
            System.out.println("\nNew Turn! Rolling the dice...");
            newHand.roll();
            newHand.sortCurrentHand();
            newHand.tallySides();
            newHand.displayCurrentHand();

            // Check for Farkle
            
            if (newMeld.isFarkle()) {
                System.out.println("Farkle! No points this turn.");
                gameOver = true;
                continue;
            }
            
            System.out.println(newMeld.getScore() + totalScore);

            // Let the player choose to meld dice or quit the game
            runMeldMenu(newHand, newMeld);

            // After melding, bank the score and ask if the player wants to continue
            System.out.println("Banking your score. Total Score: " + newMeld.getScore());
            totalScore += newMeld.getScore();

            // Ask the player if they want to continue or quit
            System.out.print("Do you want to continue playing? (Y/N): ");
            String continueOption = scanner.nextLine().toUpperCase();
            if (continueOption.equals("N")) {
                gameOver = true;
            }
        }

        System.out.println("Game Over! Your final score is: " + totalScore);
        scanner.close();
    }

    public void runMeldMenu(Hand hand, Meld meld) {
        Scanner scanner = new Scanner(System.in);
        boolean melding = true;

        while (melding) {
            System.out.println("*************************** Current Hand and Meld *******************");
            System.out.println(" Die   Hand |   Meld");
            System.out.println("------------+---------------");

            char diceLetter = 'A';
            for (int i = 0; i < 6; i++) {
                int handVal = hand.getCurrentHandSide(i);
                String handDisplay = (handVal == 0) ? " " : Integer.toString(handVal);
                String meldDisplay = (i < meld.getMeldSize()) ? meld.getMeldValueAt(i).toString() : " ";

                System.out.println(" [" + diceLetter + "]    " + handDisplay + "   |   " + meldDisplay);
                diceLetter++;
            }

            System.out.println("\nOptions:");
            System.out.println("Meld a die (Enter A-F to choose a die)");
            System.out.println("K: Quit game");
            System.out.print("Enter option: ");
            String option = scanner.nextLine().toUpperCase();

            if (option.equals("K")) {
                melding = false; // Quit melding
            } else if (option.length() == 1 && option.charAt(0) >= 'A' && option.charAt(0) <= 'F') {
                int dieIndex = option.charAt(0) - 'A';
                int dieValue = hand.getCurrentHandSide(dieIndex);

                if (dieValue != 0) {
                    meld.addDiceToMeld(dieValue);
                    hand.setCurrentHandSide(dieIndex, 0); // Remove die from hand
                    System.out.println("Melded die " + dieValue);
                    System.out.println("Current Meld Score: " + meld.getScore());
                } else {
                    System.out.println("Invalid selection. That die is already melded.");
                }
            } else {
                System.out.println("Invalid option. Please try again.");
            }
        }
    }
}
/**
 *  Zag Farkle - Gonzaga Farkle game
 *  CPSC 224 Class Project
 * 
 *  Author: Nathan
 *  Copyright year: 2025
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
    private static String playerName; // Store player's name persistently
    private static Scanner scanner = new Scanner(System.in); // Use a single Scanner instance
    public static void main(String[] args) {
        
        System.out.println("**********************************************");
        System.out.println("|                                            |");
        System.out.println("|    Welcome to Zag Farkle by Nathan Doan    |");
        System.out.println("|                Copyright 2025              |");
        System.out.println("|                                            |");
        System.out.println("**********************************************");

        playerName = getPlayerName();
        Farkle game = new Farkle();
        game.playGame();

    }

    public static String getPlayerName(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your name: ");
        String name = scanner.nextLine().trim();

        if(name.isEmpty()){
            name = "Unknown Player";
        }

        return name;
    }


    /**
     * Plays the Game:
     */
    public void playGame() {
        Scanner scanner = new Scanner(System.in);
        int totalScore = 0;
        boolean gameOver = false;

        while (!gameOver) {
            Hand newHand = new Hand();
            Meld newMeld = new Meld();
            boolean turnOver = false;
            // Reset the meld for the new turn

            newHand.sortCurrentHand();
            newHand.tallySides();

            while (!turnOver) {
                

                System.out.println("\nRolling the dice...");
                System.out.println("Your turn, " + playerName + "!");

                if (newHand.countUnmeldedDice() > 0) {
                    newHand.rerollUnmeldedDice();
                    newHand.displayCurrentHand();
                }
                if (newMeld.isFarkle(newHand)) {
                    System.out.println("Farkle! You lose all points for this turn.");
                    turnOver = true;
                    continue;
                }
                
                newHand.sortCurrentHand();
                newHand.displayCurrentHand();
                int remainingDice = runMeldMenu(newHand, newMeld);
                totalScore += newMeld.getScore();
                System.out.println("Banking your score. Total Score: " + totalScore);

                if (remainingDice == 0) {  // Hot Hand Detection
                    System.out.println("***** HOT HAND! *****");
                    System.out.println("Would you like to roll 6 new dice, or bank and end your turn? (R/B)");
                    String choice = scanner.nextLine().toUpperCase();
                    if (choice.equals("R")) {
                        newHand = new Hand(); // Reset to 6 new dice
                        newMeld.clearMeld(); // Reset meld for new dice
                    } else {
                        turnOver = true;
                    }
                } else {
                    System.out.print("Do you want to reroll your remaining dice? (Y/N): ");
                    String rerollOption = scanner.nextLine().toUpperCase();
                    if (!rerollOption.equals("Y")) {
                        turnOver = true;
                    }
                }
            }

            System.out.println("Game Over! Your final score is: " + totalScore);
            System.out.print("Do you want to play again? (Y/N): ");
            String restartOption = scanner.nextLine().toUpperCase();
            if (!restartOption.equals("Y")) {
                gameOver = true;
            }
        }
        scanner.close();
    }

    public int runMeldMenu(Hand hand, Meld meld) {
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
            System.out.println("Q: Quit game");
            System.out.print("Enter option: ");
            String option = scanner.nextLine().toUpperCase();

            if (option.equals("Q")) {
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
        return hand.countUnmeldedDice();
    }
}
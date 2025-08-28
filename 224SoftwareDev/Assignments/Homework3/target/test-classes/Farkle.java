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
import java.util.*;

/*
 *  This is the main class for the Farkle project.
 *  It really should just instantiate another class and run
 *   a method of that other class.
 */

/** Main program class for launching Farkle program. */

class Player {
    String name;
    int score;

    public Player(String name) {
        this.name = name;
        this.score = 0;
    }
}

public class Farkle {
    private static Scanner scanner = new Scanner(System.in);
    private static int targetScore = 10000;
    private static List<Player> players = new ArrayList<>();
    private static boolean endgameTriggered = false;
    private static int endgameTriggeringScore = 0;
    private static String endgamePlayer = "";

    public static void main(String[] args) {
        setupGame();
        playGame();
    }

    private static void setupGame() {
        System.out.println("**********************************************");
        System.out.println("|                                            |");
        System.out.println("|      Welcome to Zag Farkle by Nathan       |");
        System.out.println("|                Copyright 2025              |");
        System.out.println("|                                            |");
        System.out.println("**********************************************");

        System.out.print("How many points would you like to play in this game? [10000]: ");
        String input = scanner.nextLine();
        if (!input.trim().isEmpty()) {
            try {
                targetScore = Integer.parseInt(input.trim());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Using default 10000 points.");
                targetScore = 10000;
            }
        }

        System.out.print("How many players are going to be playing? [1]: ");
        input = scanner.nextLine();
        int numPlayers = 1;
        if (!input.trim().isEmpty()) {
            try {
                numPlayers = Integer.parseInt(input.trim());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Defaulting to 1 player.");
            }
        }

        for (int i = 1; i <= numPlayers; i++) {
            System.out.print("What is the player #" + i + "'s name? [Unknown player #" + i + "]: ");
            String name = scanner.nextLine().trim();
            if (name.isEmpty()) {
                name = "Unknown player #" + i;
            }
            players.add(new Player(name));
        }
    }

    /**
     * Plays the Game:
     */
    private static void playGame() {
        int currentPlayerIndex = 0;
        int finalTurnPlayerIndex = -1;
        boolean finalTurns = false;

        while (true) {
            Player player = players.get(currentPlayerIndex);
            System.out.println("\n--------------------------");
            System.out.println("It's " + player.name + "'s turn. Current score: " + player.score);

            int turnScore = playTurn(player);
            if (turnScore == -1) {
                System.out.println(player.name + " quit the game.");
                players.remove(currentPlayerIndex);
                if (players.isEmpty()) {
                    System.out.println("All players quit. Ending game.");
                    return;
                }
                currentPlayerIndex %= players.size();
                continue;
            }
            player.score += turnScore;

            printAllScores();

            if (!endgameTriggered && player.score >= targetScore) {
                endgameTriggered = true;
                endgameTriggeringScore = player.score;
                endgamePlayer = player.name;
                finalTurnPlayerIndex = currentPlayerIndex;
                System.out.println("\n******** ENDGAME STARTED ********");
                System.out.println(player.name + " has reached " + player.score + " points!");
            }

            if (finalTurns && currentPlayerIndex == finalTurnPlayerIndex) {
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
            if (endgameTriggered) finalTurns = true;
        }

        System.out.println("\n******** FINAL SCORES ********");
        printAllScores();
        Player winner = Collections.max(players, Comparator.comparing(p -> p.score));
        System.out.println("\n******** WINNER: " + winner.name + " with " + winner.score + " points! ********");
    }

    private static int playTurn(Player player) {
        Hand newHand = new Hand();
        Meld newMeld = new Meld();
        boolean turnOver = false;
        int turnScore = 0;

        while (!turnOver) {
            newHand.rerollUnmeldedDice();
            newHand.displayCurrentHand();
            
            if (newMeld.isFarkle(newHand)) {
                System.out.println("Farkle! No score for this turn.");
                return 0;
            }

            int remainingDice = runMeldMenu(newHand, newMeld);
            turnScore += newMeld.getScore();
            System.out.println("Current turn score: " + turnScore);
            newMeld.clearMeld();

            if (remainingDice == 0) {
                System.out.println("***** HOT HAND! *****");
                System.out.print("Roll fresh dice or bank? (R/B): ");
                String choice = scanner.nextLine().trim().toUpperCase();
                if (choice.equals("R")) {
                    newHand = new Hand();
                } else {
                    turnOver = true;
                }
            } else {
                System.out.print("Reroll remaining dice, bank or quit? (Y/N/Q): ");
                String option = scanner.nextLine().trim().toUpperCase();
                if (option.equals("Q")) return -1;
                if (!option.equals("Y")) turnOver = true;
            }
        }
        return turnScore;
    }

    private static int runMeldMenu(Hand hand, Meld meld) {
        boolean melding = true;
        while (melding) {
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

            System.out.print("Meld a die (A-F) or Q to quit melding: ");
            String option = scanner.nextLine().toUpperCase();

            if (option.equals("Q")) {
                melding = false;
            } else if (option.length() == 1 && option.charAt(0) >= 'A' && option.charAt(0) <= 'F') {
                int dieIndex = option.charAt(0) - 'A';
                int dieValue = hand.getCurrentHandSide(dieIndex);

                if (dieValue != 0) {
                    meld.addDiceToMeld(dieValue);
                    hand.setCurrentHandSide(dieIndex, 0);
                    System.out.println("Melded die " + dieValue);
                    System.out.println("Current Meld Score: " + meld.getScore());
                } else {
                    System.out.println("That die is already melded.");
                }
            } else {
                System.out.println("Invalid input.");
            }
        }
        return hand.countUnmeldedDice();
    }

    private static void printAllScores() {
        System.out.println("\nCurrent total points:");
        for (Player p : players) {
            System.out.println(" " + p.name + " " + p.score);
        }
    }
}
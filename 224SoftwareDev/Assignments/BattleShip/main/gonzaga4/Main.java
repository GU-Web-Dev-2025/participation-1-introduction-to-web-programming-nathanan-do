package edu.gonzaga.BattleShipGame;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("\n=== Welcome to Battleship ===");
            System.out.println("1. Start Game");
            System.out.println("2. View Instructions");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");

            String input = scanner.nextLine().trim();
            switch (input) {
                case "1":
                    GameLoop.main(args);
                    break;
                case "2":
                    printInstructions();
                    break;
                case "3":
                    exit = true;
                    System.out.println("Thanks for playing Battleship!");
                    break;
                default:
                    System.out.println("Invalid input. Please try again.");
            }
        }

        scanner.close();
    }

    private static void printInstructions() {
        System.out.println("\n=== How to Play Battleship ===");
        // … your instructions …
    }
}

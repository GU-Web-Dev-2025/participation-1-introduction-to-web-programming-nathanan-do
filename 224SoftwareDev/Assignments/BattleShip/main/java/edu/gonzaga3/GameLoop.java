package edu.gonzaga.BattleShipGame.GameLoop;

import java.util.*;

public class GameLoop {
    private static final int NUM_SHIPS = 3;
    private static final int BOARD_SIZE = 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Player player1 = new Player("Player 1");
        Player player2 = new Player("Player 2");
        Board board1 = new Board(BOARD_SIZE, BOARD_SIZE);
        Board board2 = new Board(BOARD_SIZE, BOARD_SIZE);

        System.out.println("\n=== Welcome to Battleship ===\n");

        

        // Place ships for Player 1
        System.out.println(player1.getName() + ", place your ships.");
        placeShips(scanner, board1);

        // Place ships for Player 2
        System.out.println("\n" + player2.getName() + ", place your ships.");
        placeShips(scanner, board2);

        // Game loop
        boolean gameOver = false;
        Player currentPlayer = player1;
        Board opponentBoard = board2;
        

        while (!gameOver) {
            System.out.println("\n" + currentPlayer.getName() + "'s turn to fire!");
            opponentBoard.displayBoard(false);

            Coordinate target = getCoordinateInput(scanner, "Enter coordinate to fire at (e.g. B4): ");

            if (!opponentBoard.canPlaceShot(target)) {
                System.out.println("Invalid or already used coordinate. Try again.");
                continue;
            }

            int result = opponentBoard.placeShot(target);
            String sunkShip = opponentBoard.shipNameIfKill(target);
            if (sunkShip != null) {
                System.out.println("You sunk their " + sunkShip + "!");
            }
            System.out.println("Remaining ships: " + opponentBoard.getFleetSize());

            if (result == 3) {
                System.out.println("It's a HIT!");
                currentPlayer.setScore(currentPlayer.getScore(0) + 1);
            
                String sunk = opponentBoard.shipNameIfKill(target);
                if (sunk != null) {
                    System.out.println("You sunk the " + sunk + "!");
                    currentPlayer.setScore(currentPlayer.getScore(0) + 2);
                }
            
                System.out.println("Score: " + currentPlayer.getScore(0));
            }else {
                System.out.println("Miss.");
            }

            if (opponentBoard.isGameOver()) {
                System.out.println("\nGame Over! " + currentPlayer.getName() + " wins!");
                gameOver = true;
            } else {
                // Swap players
                if (currentPlayer == player1) {
                    currentPlayer = player2;
                    opponentBoard = board1;
                } else {
                    currentPlayer = player1;
                    opponentBoard = board2;
                }
            }
        }

        scanner.close();
    }

    private static void placeShips(Scanner scanner, Board board) {
        for (int i = 1; i <= NUM_SHIPS; i++) {
            while (true) {
                System.out.println("\nPlacing Ship #" + i);
                System.out.print("Enter ship name: ");
                String name = scanner.nextLine();

                int length = getIntInput(scanner, "Enter ship length (2-5): ", 2, 5);
                Coordinate start = getCoordinateInput(scanner, "Enter starting coordinate (e.g. A0): ");

                System.out.print("Enter direction (H for horizontal, V for vertical): ");
                String dir = scanner.nextLine().trim().toUpperCase();
                boolean horizontal = dir.equals("H");

                List<Coordinate> coords = new ArrayList<>();
                for (int j = 0; j < length; j++) {
                    int row = start.getRow() + (horizontal ? 0 : j);
                    int col = start.getCol() + (horizontal ? j : 0);

                    if (row >= BOARD_SIZE || col >= BOARD_SIZE) {
                        coords = null;
                        break;
                    }
                    coords.add(new Coordinate(row, col));
                }

                if (coords == null || coords.size() != length) {
                    System.out.println("Ship goes out of bounds. Try again.");
                    continue;
                }

                Ship ship = new Ship(name, coords);
                if (board.canPlaceShip(ship)) {
                    board.placeShip(ship);
                    System.out.println("Ship placed: " + coords);
                    board.displayBoard(true);
                    break;
                } else {
                    System.out.println("Cannot place ship on those coordinates. Try again.");
                }
            }
        }
    }

    private static Coordinate getCoordinateInput(Scanner scanner, String prompt) {
        while (true) {
            System.out.print(prompt);
            String input = scanner.nextLine().trim();
            try {
                return new Coordinate(input);
            } catch (Exception e) {
                System.out.println("Invalid format. Try again (e.g. A4).");
            }
        }
    }

    private static int getIntInput(Scanner scanner, String prompt, int min, int max) {
        while (true) {
            System.out.print(prompt);
            try {
                int value = Integer.parseInt(scanner.nextLine().trim());
                if (value >= min && value <= max) {
                    return value;
                }
            } catch (Exception ignored) {}
            System.out.println("Invalid number. Please enter a value between " + min + " and " + max + ".");
        }
    }
}


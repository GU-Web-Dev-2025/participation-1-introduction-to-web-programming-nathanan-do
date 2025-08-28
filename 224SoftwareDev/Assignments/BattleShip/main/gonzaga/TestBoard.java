package edu.gonzaga;

import java.util.*;

public class TestBoard {
    public static void main(String[] args) {
        // Create a 20x20 board
        Board board = new Board();

        // Create coordinates for a ship from B2 to B5 (row 1, col 2–5)
        List<Coordinate> shipCoords = new ArrayList<>();
        for (int i = 2; i <= 5; i++) {
            shipCoords.add(new Coordinate(1, i)); // B2 to B5
        }

        // Create a ship and place it on the board
        Ship testShip = new Ship("Destroyer", shipCoords);
        boolean placed = board.placeShip(testShip);
        System.out.println("Ship placed: " + placed); // Expect: true

        // Attack a coordinate that should be a hit
        Coordinate hitCoord = new Coordinate("B3");
        boolean hit = board.attack(hitCoord);
        System.out.println("Attack on B3 was a hit: " + hit); // Expect: true

        // Attack a coordinate that should be a miss
        Coordinate missCoord = new Coordinate("C10");
        boolean miss = board.attack(missCoord);
        System.out.println("Attack on C10 was a miss: " + !miss); // Expect: true

        // Try displaying the board with ships visible
        System.out.println("\nBoard Display (revealShips = true):");
        board.displayBoard(true);

        // Try displaying the board with ships hidden
        System.out.println("\nBoard Display (revealShips = false):");
        board.displayBoard(false);

        // Check if all ships are sunk
        System.out.println("\nSinking remaining ship parts...");
        for (int i = 2; i <= 5; i++) {
            Coordinate c = new Coordinate(1, i);
            board.attack(c); // Keep attacking all parts of ship
        }

        System.out.println("All ships sunk: " + board.allShipsSunk()); // Expect: true
    }
}

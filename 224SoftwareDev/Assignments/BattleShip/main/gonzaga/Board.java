package edu.gonzaga;

import java.util.*;

/**
 * Manages the game board including ship placements, hits, and misses.
 */
public class Board {
    private final int SIZE = 10; // Changes of the size of board
        // 20 = letters A-T
        // 10 = letters A-J

    private List<Ship> ships;
    private Set<Coordinate> hits;
    private Set<Coordinate> misses;

    /**
     * Constructs an empty 20x20 board with no ships placed.
     */
    public Board() {
        ships = new ArrayList<>();
        hits = new HashSet<>();
        misses = new HashSet<>();
    }

    /**
     * Attempts to place a ship on the board. Returns false if overlapping occurs.
     * @param ship The ship to be placed.
     * @return True if placed successfully; false if conflict detected.
     */
    public boolean placeShip(Ship ship) {
        for (Coordinate coord : ship.getPoints()) {
            for (Ship s : ships) {
                if (s.hasCoordinates(coord)) {
                    return false; // Conflict with existing ship
                }
            }
        }
        ships.add(ship);
        return true;
    }

    /**
     * Registers an attack on the board at a specific coordinate.
     * @param coord The coordinate being targeted.
     * @return True if it was a hit; false if it was a miss.
     */
    public boolean attack(Coordinate coord) {
        for (Ship s : ships) {
            if (s.hasCoordinates(coord)) {
                s.shipHit(coord);
                hits.add(coord);
                return true;
            }
        }
        misses.add(coord);
        return false;
    }

    /**
     * Checks if all ships on the board have been sunk.
     * @return True if no ships remain; false otherwise.
     */
    public boolean allShipsSunk() {
        for (Ship s : ships) {
            if (!s.noMoreShip()) {
                return false;
            }
        }
        return true;
    }

    /**
     * Displays the board in ASCII format.
     * @param revealShips If true, shows ship locations; otherwise, hides them.
     */
    public void displayBoard(boolean revealShips) {
        System.out.print("   ");
        for (int col = 0; col < SIZE; col++) {
            System.out.printf("%2d ", col);
        }
        System.out.println();

        for (int row = 0; row < SIZE; row++) {
            System.out.printf("%c ", (char) ('A' + row));
            System.out.print(" ");
            for (int col = 0; col < SIZE; col++) {
                Coordinate coord = new Coordinate(row, col);
                if (hits.contains(coord)) {
                    System.out.print(" X ");
                } else if (misses.contains(coord)) {
                    System.out.print(" O ");
                } else if (revealShips && isShipAt(coord)) {
                    System.out.print(" S ");
                } else {
                    System.out.print(" ~ ");
                }
            }
            System.out.println();
        }
    }

    /**
     * Helper method to check if a ship exists at a coordinate.
     * @param coord The coordinate to check.
     * @return True if a ship occupies the coordinate; false otherwise.
     */
    private boolean isShipAt(Coordinate coord) {
        for (Ship s : ships) {
            if (s.hasCoordinates(coord)) {
                return true;
            }
        }
        return false;
    }

    public List<Ship> getShips() {
        return ships;
    }

    public Set<Coordinate> getHits() {
        return hits;
    }

    public Set<Coordinate> getMisses() {
        return misses;
    }
}

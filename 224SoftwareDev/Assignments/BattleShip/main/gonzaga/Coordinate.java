package edu.gonzaga;

/**
 * Represents a coordinate on the 20x20 game board.
 * Coordinates range from A0 to T19.
 */
public class Coordinate {
    private int row; // 0–9 corresponds to A–J
    private int col; // 0–9

    /**
     * Constructs a Coordinate using row and column integers.
     * @param row The row index (0–9).
     * @param col The column index (0–9).
     */
    public Coordinate(int row, int col) {
        this.row = row;
        this.col = col;
    }

    /**
     * Constructs a Coordinate from a string like "B5" or "T1".
     * @param input A string with one letter (A–J) and one or two digits (0–9).
     */
    public Coordinate(String input) {
        input = input.toUpperCase();
        this.row = input.charAt(0) - 'A';
        this.col = Integer.parseInt(input.substring(1));
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Coordinate)) return false;
        Coordinate other = (Coordinate) obj;
        return row == other.row && col == other.col;
    }

    @Override
    public int hashCode() {
        return 31 * row + col;
    }

    @Override
    public String toString() {
        return String.format("%c%d", (char) ('A' + row), col);
    }
}


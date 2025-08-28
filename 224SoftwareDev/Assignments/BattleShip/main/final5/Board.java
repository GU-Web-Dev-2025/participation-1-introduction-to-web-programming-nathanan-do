import java.util.ArrayList; 
import java.util.Iterator;

public class Board {
    private int boardX = 10;
    private int boardY = 10; 
    private int[][] fieldStatic;
    private ArrayList<Ship> fleet = new ArrayList<>();

    // Default constructor
    public Board() {
        this(10, 10);
    }

    // Board constructor with parameters
    public Board(int x, int y) {
        boardX = x;
        boardY = y;
        fieldStatic = new int[boardY][boardX];
        for (int i = 0; i < boardY; i++) {
            for (int j = 0; j < boardX; j++) {
                fieldStatic[i][j] = 0;
            }
        }
    }

    // Attack: returns true if hit
    public boolean attack(Coordinate coord) {
        if (!canPlaceShot(coord)) return false;
        int result = placeShot(coord);
        return result == 3;
    }

    // Place ship on the board
    public boolean canPlaceShip(Ship ship) {
        for (Coordinate c : ship.getCoordinates()) {
            int r = c.getRow();
            int ccol = c.getCol();
            if (r < 0 || r >= boardY || ccol < 0 || ccol >= boardX) return false;
            if (fieldStatic[r][ccol] != 0) return false;
        }
        return true;
    }

    public void placeShip(Ship ship) {
        if (!canPlaceShip(ship)) throw new IllegalStateException("Cannot place ship at given coordinates.");
        for (Coordinate c : ship.getCoordinates()) {
            fieldStatic[c.getRow()][c.getCol()] = 2;
        }
        fleet.add(ship);
    }

    public boolean canPlaceShot(Coordinate coord) {
        int r = coord.getRow(), ccol = coord.getCol();
        if (r < 0 || r >= boardY || ccol < 0 || ccol >= boardX) return false;
        int v = fieldStatic[r][ccol];
        return v == 0 || v == 2;
    }

    public int placeShot(Coordinate coord) {
        int r = coord.getRow(), ccol = coord.getCol();
        int v = fieldStatic[r][ccol];
        if (v == 1 || v == 3) throw new IllegalStateException("Field already shot at.");
        if (v == 0) {
            fieldStatic[r][ccol] = 1; // miss
        } else {
            fieldStatic[r][ccol] = 3; // hit
            Iterator<Ship> it = fleet.iterator();
            while (it.hasNext()) {
                Ship s = it.next();
                if (s.hasCoordinates(coord)) {
                    s.shipHit(coord);
                    if (s.noMoreShip()) it.remove();
                }
            }
        }
        return fieldStatic[r][ccol];
    }

    public boolean isGameOver() {
        return fleet.isEmpty();
    }

    public int getFleetSize() {
        return fleet.size();
    }

    public String shipNameIfKill(Coordinate coord) {
        for (Ship s : fleet) if (s.hasCoordinates(coord)) return s.getName();
        return null;
    }

    public int shipPointsIfKill(Coordinate coord) {
        for (Ship s : fleet) if (s.hasCoordinates(coord)) return s.getLength();
        return 0;
    }

    /**
     * Display the board in a clean ASCII format:
     *
     *     0 1 2 3 4 5 6 7 8 9
     *  A  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
     *  B  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
     *  ...
     *  J  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
     *     0 1 2 3 4 5 6 7 8 9
     *
     * @param revealShips when true, shows ship positions as 'S'.
     */
    public void displayBoard(boolean revealShips) {
        // Header
        System.out.print("    ");
        for (int col = 0; col < boardX; col++) {
            System.out.print(col + " ");
        }
        System.out.println();

        // Rows
        for (int row = 0; row < boardY; row++) {
            char label = (char) ('A' + row);
            System.out.print(label + "   ");
            for (int col = 0; col < boardX; col++) {
                int cell = fieldStatic[row][col];
                char symbol = '~';
                if (cell == 2 && revealShips) symbol = 'S';
                else if (cell == 1) symbol = 'O';
                else if (cell == 3) symbol = 'X';
                System.out.print(symbol + " ");
            }
            System.out.println();
        }

        // Footer
        System.out.print("    ");
        for (int col = 0; col < boardX; col++) {
            System.out.print(col + " ");
        }
        System.out.println();
    }
}

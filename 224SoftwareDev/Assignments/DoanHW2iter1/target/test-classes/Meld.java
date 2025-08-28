package edu.gonzaga.Farkle;

/**
 * Class for a display of a user's hand and the making of melds. Works in conjunction with combo class.
 */

 // ArrayList library enables the use of ArrayLists.
import java.util.ArrayList;
// Scanner library enables the ability to read inputs from the user terminal.
import java.util.Scanner;
// Collections allow to store and sort elements
import java.util.Collections;


public class Meld {
    
    private ArrayList<Integer> diceValues = new ArrayList<Integer>();

    public Meld() {
        diceValues = new ArrayList<>();
    }

    /**
     * Get tallied faces from the player hand
     */
    // public void addTalliedFaces( Hand talliedHand ) {
    //     for (int i = 1; i < 7; i++ ) {
    //         diceValues.add( talliedHand.getTalliedHandInteger( i ) );
    //     }
    //     return;
    // }


    /**
     * Adds dice values to meld:
     */
    public void addDiceToMeld(Integer value) {
        if (value >= 1 && value <= 6){
            diceValues.add(value);
            Collections.sort(diceValues);
        }
    }

    /**
     * Removes a die value from the meld.
     */
    public void removeDiceFromMeld(Integer value) {
        diceValues.remove(value);
    }

    /**
     * Returns the size of the melded dice.
     */
    public int getMeldSize() {
        return diceValues.size();
    }

    /**
     * Gets the meld value at a given index.
     */
    public Integer getMeldValueAt(int index) {
        if (index >= 0 && index < diceValues.size()){
            return diceValues.get(index);
        }
        return null;
    }

    /**
     * Displays the melded dice.
     */
    public void displayMeld() {
        System.out.print("Melded Dice: ");
        for (Integer value : diceValues) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    /**
     * Calculates the score of the melded dice.
     */
    public Integer getScore() {
        return calculateScore();
    }

    /**
     * Checks if the hand is a Farkle (no valid scoring melds).
     */
    public boolean isFarkle() {
            return getScore() == 0;
    }

    private Integer calculateScore() {
        int score = 0;
        Integer[] dieTallies = new Integer[7];

        for (int i = 0; i < 7; i++) {
            dieTallies[i] = 0;
        }

        for (Integer value : diceValues) {
            if (value >= 1 && value <=6){
                dieTallies[value]++;
            }
        }

        // Check for a straight (1-6)
        boolean isStraight = true;
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] != 1) {
                isStraight = false;
                break;
            }
        }
        if (isStraight) return 1500;

        // Check for three pairs
        int pairCount = 0;
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] == 2) pairCount++;
        }
        if (pairCount == 3) return 1500;

        // Check for triples (including triple 1's)
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] >= 3) {
                score += (i == 1) ? 1000 : (i * 100);
                dieTallies[i] -= 3;
            }
        }

        // Check for single 1's and 5's
        score += dieTallies[1] * 100;
        score += dieTallies[5] * 50;

        return score;
    }

}
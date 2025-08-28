package edu.gonzaga.Farkle;

/**
 * Class for a display of a user's hand and the making of melds. Works in conjunction with combo class.
 */

 // ArrayList library enables the use of ArrayLists.
import java.util.ArrayList;
// Scanner library enables the ability to read inputs from the user terminal.
import java.util.Scanner;
//


public class Meld {
    
    // Attributes go here:
    
    //private Integer score = 0;

    // All I need is an arrayList of Integers
    private ArrayList<Integer> diceValues = new ArrayList<Integer>();

    
    // Constructor:
    // Meld() {
    //     for (int i = 0; i < 6; i++ ) {
    //         diceValues.add( 0 );
    //     }
    // }

    // _________________________ Methods go here: _________________________


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
    public void addDiceToMeld( Integer value ) {
        diceValues.add( value );
    }

    /**
     * Removes dice values from the meld
     */
    public void removeDiceToMeld( Integer value ) {
        diceValues.remove( value );
    }

    /**
     * Displays the current contents of the Meld ArrayList
     */
    public void displayMeldArray() {
        for ( Integer value : diceValues ) {
            System.out.println( value );
        }
    }
  

    /**
     * Recomputes first matching dice values from the Meld:
     */

    /**
     * Gets current meld score.
     */
    public Integer getScore() {
        Integer score = calcScore();
        return score;
    }

    /**
     * Checks if Farkle. (When the current score's meld is ZERO)
     */
    public boolean isFarkle() {
        return getScore() == 0;
    }

    private Integer calcScore() {
        Integer score = 0;

        // Create tallyOfDiceSides
        // Use tally to find combos, add up score as we go
        Integer[] dieTallies = new Integer[7];
        for( Integer currDieValue : diceValues ) {
            dieTallies[currDieValue]++;
        }

        // Calc combos, add score

        return score;
    }
    
    /**
     * Calculates valid meld combinations from the Meld ArrayList of face values,
     * starting with the largest combo and working to the smallest.
     */
    public void checkCombos() {

        // Check straight:


        // Three pairs:

        // Triple numbers +

        // Triple 1's:

        // Single 1's:

        // Single 5's:

    }
}
package edu.gonzaga.Farkle;

/**
 * Class for a hand of six dice used in a game of Farkle
 */

import java.util.ArrayList;
import java.util.Collections;

/** Class for a player's current hand of Dice */
public class Hand {

    // Place Attributes here:
    
    // currentHand stores the 6 dice of a player's hand each turn.
    private ArrayList<Die> currentHand = new ArrayList<Die>(); // ArrayList object that stores Dice objects
    // numSideRolled stores the total number of each face rolled for the 6 die in the currentHand.
    private ArrayList<Integer> quantitySideRolled = new ArrayList<Integer>();
    private static Integer NUMSIDES = 6;

    // currentHand constructor:
    public Hand(){
        for ( int i = 0; i < 6; i++ ) {
            //Add die objects to currentHand:
            currentHand.add( new Die( NUMSIDES, 1) );
        }
        for ( int i = 0; i < 7; i++ ) {
            //Add Integer objects to quantitySideRolled (number of times each side is rolled):
            quantitySideRolled.add(0);
            //System.out.println( "TEST of QSR: " + quantitySideRolled.get(i) );
        }
    }

    // Place methods here:

    /**
     * Gets the face value of a specific die from the currentHand.
     */
    public Integer getCurrentHandSide(int index){
        
        // The currentHand is an array of Die objects. Instead of using currentHand.get(),
        // use .getSideUp() in order to retrieve the integer value of the die's face.
        return currentHand.get(index).getSideUp();
    }

    /**
     * Sets the face value of a specific die from the currentHand.
     */
    public void setCurrentHandSide(int index, int newValue){

        // CurrentHand.get( index ) retrieves the desired doce pbject from the arraylist.
        // then, ".setSideUp( newValue )" changes the face value of that specific die.
        currentHand.get( index ).setSideUp(newValue);
        return;
    }

    void tallySides() {
        // Gets the total size of the tally array, then loops for each "face" 1 - 6:
        // Basically constructs a tally array?
        for( int i = 0; i < quantitySideRolled.size(); i++ ) {
            quantitySideRolled.set(i, 0);
        }
        
        // For each die object in array currentHand:
        for( Die d : currentHand ) {
            // Set the current tally of each face value to:
            // the current face of the die rolled as (INDEX), the current tally value + 1 (NEW VALUE)
            quantitySideRolled.set(d.getSideUp(), quantitySideRolled.get(d.getSideUp()) + 1);
        }
    }

    /**
     * Gets the tallied count of a sides rolled from the quantitySideRolled.
     */
    public Integer getTalliedHandInteger( int index ){
        // Gets the count of times a certain side was rolled.
        return quantitySideRolled.get(index);
    }

    /**
     * Rolls the currentHand dice for new random values between 1 and 6, then adds them to the
     * current hand.
     */
    public void roll() {

        /* For reference:
         * Random rand = new Random();
         * this.sideUp = rand.nextInt(this.numSides) + 1;
        */

        // For each die in the array currentHand, roll the die to get a new random value between 1 - 6.
        for( Die d : currentHand ) {
            d.roll();
        }
        // re-tally?
        return;
    }

    /**
     * Sorts the currentHand dice by current side value, and arranges them from least to greatest.
     * 
     */
    public void sortCurrentHand() {

        // Sorts the values of the hand of dice from least to greatest face value. ( 1 to 6 )
        Collections.sort(currentHand);
        return;
    }

    /**
     * Displays the player's rolled dice by:
     * 1. The side each dice rolled, from least to greatest.
     * 2. The total count of each face rolled.
     * 
     * 
     */
    public void displayCurrentHand() {

        // Sort and tally sides rolled:
        //sortCurrentHand();

        // Display dice by sorted face value:
        System.out.print( "Your current hand: ");
        for ( int i = 0; i < NUMSIDES; i++ ) {
            if ( i <= 4 ) {
                System.out.print( currentHand.get(i) + ", " );
            }
            else {
                System.out.println( currentHand.get(i) );
            }
        }
        // Display dice by total count of each face rolled:
        System.out.print( "Quantity of each die value: ");
        for ( int i = 1; i < 7; i++ ) {
            if ( i <= 5 ) {
                System.out.print( quantitySideRolled.get(i) + ", " );
            }
            else {
                System.out.println( quantitySideRolled.get(i) );
            }
        }
    }


}

package edu.gonzaga.Farkle;


import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MeldTest {
    
    @Test
    void testFullHouseScore() {
        Meld meld = new Meld();
        meld.addDiceToMeld(2);
        meld.addDiceToMeld(2);
        meld.addDiceToMeld(4);
        meld.addDiceToMeld(4);
        meld.addDiceToMeld(4);
        assertEquals(1500, meld.getScore(), "Full House should score 1500");
    }

    @Test
    void testNotFullHouseWithExtraDice() {
        Meld meld = new Meld();
        meld.addDiceToMeld(2);
        meld.addDiceToMeld(2);
        meld.addDiceToMeld(4);
        meld.addDiceToMeld(4);
        meld.addDiceToMeld(4);
        meld.addDiceToMeld(6); // extra die breaks full house
        assertNotEquals(1500, meld.getScore(), "More than 5 dice should not count as Full House");
    }

    @Test
    void testTripleOneOverriddenByFullHouse() {
        Meld meld = new Meld();
        meld.addDiceToMeld(1);
        meld.addDiceToMeld(1);
        meld.addDiceToMeld(1);
        meld.addDiceToMeld(2);
        meld.addDiceToMeld(2);
        assertEquals(1500, meld.getScore(), "Full House (1s and 2s) should score 1500 not 1000");
    }

    @Test
    void testNoFullHouse() {
        Meld meld = new Meld();
        meld.addDiceToMeld(1);
        meld.addDiceToMeld(1);
        meld.addDiceToMeld(1);
        assertEquals(1000, meld.getScore(), "Triple 1s should score 1000");
    }
}

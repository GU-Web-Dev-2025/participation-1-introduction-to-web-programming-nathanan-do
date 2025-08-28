package edu.gonzaga.Farkle;

import java.util.*;

public class Meld {
    private ArrayList<Integer> diceValues = new ArrayList<>();

    public Meld() {
        diceValues = new ArrayList<>();
    }

    public void addDiceToMeld(Integer value) {
        if (value >= 1 && value <= 6){
            diceValues.add(value);
            Collections.sort(diceValues);
        }
    }

    public void removeDiceFromMeld(Integer value) {
        diceValues.remove(value);
    }

    public int getMeldSize() {
        return diceValues.size();
    }

    public Integer getMeldValueAt(int index) {
        if (index >= 0 && index < diceValues.size()){
            return diceValues.get(index);
        }
        return null;
    }

    public void displayMeld() {
        System.out.print("Melded Dice: ");
        for (Integer value : diceValues) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public Integer getScore() {
        return calculateScore();
    }

    public boolean isFarkle(Hand hand) {
        for (int i = 0; i < 6; i++) {
            int dieValue = hand.getCurrentHandSide(i);
            if (dieValue == 1 || dieValue == 5 || isThreeOfAKind(dieValue)) {
                return false;
            }
        }
        return true;
    }

    private boolean isThreeOfAKind(int dieValue) {
        int count = 0;
        for (Integer value : diceValues) {
            if (value == dieValue) {
                count++;
            }
        }
        return count >= 3;
    }

    private boolean isFullHouse(Integer[] tallies) {
        boolean hasThree = false;
        boolean hasTwo = false;
        for (int i = 1; i <= 6; i++) {
            if (tallies[i] == 3) hasThree = true;
            if (tallies[i] == 2) hasTwo = true;
        }
        return (diceValues.size() == 5) && hasThree && hasTwo;
    }

    private Integer calculateScore() {
        int score = 0;
        Integer[] dieTallies = new Integer[7];
        Arrays.fill(dieTallies, 0);

        for (Integer value : diceValues) {
            if (value >= 1 && value <=6){
                dieTallies[value]++;
            }
        }

        if (isFullHouse(dieTallies)) return 1500;

        // Straight (1-6)
        boolean isStraight = true;
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] != 1) {
                isStraight = false;
                break;
            }
        }
        if (isStraight) return 1500;

        // Three pairs
        int pairCount = 0;
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] == 2) pairCount++;
        }
        if (pairCount == 3) return 1500;

        // Triples
        for (int i = 1; i <= 6; i++) {
            if (dieTallies[i] >= 3) {
                score += (i == 1) ? 1000 : (i * 100);
                dieTallies[i] -= 3;
            }
        }

        // Single 1's and 5's
        score += dieTallies[1] * 100;
        score += dieTallies[5] * 50;

        return score;
    }

    public void clearMeld() {
        diceValues.clear();
    }
}

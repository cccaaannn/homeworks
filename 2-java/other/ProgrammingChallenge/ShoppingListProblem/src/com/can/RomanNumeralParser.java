package com.can;

import java.util.HashMap;

public class RomanNumeralParser {
    private HashMap<Character, Integer> romanNumerals;

    RomanNumeralParser(){
        this.romanNumerals = new HashMap<Character, Integer>();
        this.populateNumerals();
    }

    private void populateNumerals() {
        /*
            Numerals are all lowercase for compatibility.
         */

        this.romanNumerals.put('i', 1);
        this.romanNumerals.put('v', 5);
        this.romanNumerals.put('x', 10);
        this.romanNumerals.put('l', 50);
        this.romanNumerals.put('c', 100);
        this.romanNumerals.put('d', 500);
        this.romanNumerals.put('m', 1000);
    }


    public boolean isConvertible(String romanStr){
        /*
            Checks validity of a roman numeral string
         */
        if(romanStr.matches("^m{0,4}(cm|cd|d?c{0,3})(xc|xl|l?x{0,3})(ix|iv|v?i{0,3})$")){
            return true;
        }
        else{
            return false;
        }
    }


    public int toDecimalLoop(String romanStr){
        /*
            function for converting roman numerals to decimal
         */
        romanStr = romanStr.toLowerCase();

        int res = 0;
        for (int i = 0; i < romanStr.length(); i++) {
            int currentFirstDecimal = this.romanNumerals.get(romanStr.charAt(i));

            if (i + 1 < romanStr.length()) {
                int previousFirstDecimal = this.romanNumerals.get(romanStr.charAt(i + 1));
                if (currentFirstDecimal >= previousFirstDecimal) {
                    res = res + currentFirstDecimal;
                }
                else {
                    res = res + previousFirstDecimal - currentFirstDecimal;
                    i++;
                }
            }
            else {
                res = res + currentFirstDecimal;
            }
        }
        return res;
    }


    public int toDecimal(String romanStr){
        /*
            starting function before recursive one
            this checks if the str is single digit roman numeral
            and adds first roman character since it will always be added.
         */
        romanStr = romanStr.toLowerCase();

        Character firstRoman = romanStr.charAt(romanStr.length() - 1);
        int firstDecimal = this.romanNumerals.get(firstRoman);

        if(romanStr.length() == 1){
            return this.romanNumerals.get(romanStr.charAt(0));
        }

        return this.toDecimalRecursive(romanStr) + firstDecimal;
    }


    int toDecimalRecursive(String romanStr) {
        /*
            recursive function for converting roman numerals to decimal
         */

        // set the previous numeral value
        Character previousLastRoman = romanStr.charAt(romanStr.length() - 1);
        romanStr = romanStr.substring(0, romanStr.length() - 1);
        int previousLastDecimal = this.romanNumerals.get(previousLastRoman);

        // base case
        if (romanStr.equals("")) {
            return 0;
        }

        // comparison
        else {
            // set the current numeral value
            char currentLastRoman = romanStr.charAt(romanStr.length() - 1);
            int currentLastDecimal = this.romanNumerals.get(currentLastRoman);

            // if the current last character is bigger add it else subtract it
            if (currentLastDecimal >= previousLastDecimal) {
                // System.out.println(romanStr + " + " + previousLastRoman);
                return toDecimalRecursive(romanStr) + currentLastDecimal;
            } else {
                // System.out.println(romanStr + " - " + previousLastRoman);
                return toDecimalRecursive(romanStr) - currentLastDecimal;
            }

        }

    }

}

package com.can;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class ShoppingListProcessor {
    boolean logErrors;
    RomanNumeralParser romanNumeralParser;

    ShoppingListProcessor(boolean logErrors) {
        this.logErrors = logErrors;
        this.romanNumeralParser = new RomanNumeralParser();
    }

    private ArrayList<List<String>> readShoppingListFile(String inputTextPath) {
        /*
            Reads and cleans shopping list file.
         */
        try (BufferedReader br = new BufferedReader(new FileReader(inputTextPath))) {
            ArrayList<List<String>> lines = new ArrayList<List<String>>();
            String line;
            while ((line = br.readLine()) != null) {
                // Clean punctuation and spaces, convert to lowercase, split elements into List<String>
                List<String> cleanLine = Arrays.asList(line.replaceAll("\\p{Punct}", "").strip().toLowerCase().split("\\s+"));
                lines.add(cleanLine);
            }
            return lines;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private HashMap<String, Integer> solveShoppingListEquation(List<String> shoppingEquation, HashMap<String, Integer> knownVariables) throws ShoppingListEquationException, IllegalArgumentException {
        /*
            Tries to solve a shoppingEquation, by subtracting leftSum from equRight to find the unknown.
            shoppingEquations has to have one unknown otherwise we can not solve them so the function throws a ShoppingListEquationException if there are more than one unknown
         */

        // check if question has 'is' in it
        int locationOfIs = shoppingEquation.indexOf("is");
        if(locationOfIs == -1){
            throw new IllegalArgumentException("This line does not contains 'is' '" + shoppingEquation + "', skipping this line...");
        }

        List<String> equLeft = shoppingEquation.subList(0, locationOfIs);
        String equRightRoman = shoppingEquation.get(shoppingEquation.size() - 1);
        int equRight;
        try {
            // try to convert int first
            equRight = Integer.valueOf(equRightRoman);
        }
        catch (NumberFormatException e) {
            // try roman numeral conversion
            if (!equRightRoman.equals("") && this.romanNumeralParser.isConvertible(equRightRoman)) {
                equRight = this.romanNumeralParser.toDecimal(equRightRoman);
            }
            else {
                throw new IllegalArgumentException("Can not convert token '" + equRightRoman + "' roman to decimal, skipping this line...");
            }
        }


        // finding the solution
        String unkown = "";
        int leftSum = 0;
        for (String variable : equLeft) {
            if (knownVariables.containsKey(variable)) {
                leftSum += knownVariables.get(variable);
            }
            else if (unkown.equals("")) {
                unkown = variable;
            }
            // if there are more than one unknown we can't solve this
            else {
                throw new ShoppingListEquationException("There are more than one unknown");
            }
        }

        int solution = equRight - leftSum;
        // check if all the values in the equation are known
        if(!unkown.equals("")){
            knownVariables.put(unkown, solution);
        }

        return knownVariables;
    }


    private void printAnswerList(List question, int sum) {
        /*
            Prints the answer formatted as required
            ex: tomato potato strawberry is 140
         */
        for (var element : question) {
            System.out.print(element + " ");
        }
        System.out.print("is " + sum + "\n");
    }


    private void answerQuestions(ArrayList<List<String>> questions, HashMap<String, Integer> shoppingItems) {
        /*
            Iterates over given questions, tries to find prices of the items on the shoppingItems
            If finds a price increases the sum
            else displays error message
         */
        System.out.println("ANSWERS");
        for (List<String> question : questions) {

            int sum = 0;
            String unknownValue = "";
            for (String questionElement : question) {
                if (shoppingItems.containsKey(questionElement)) {
                    sum += shoppingItems.get(questionElement);
                }
                else {
                    unknownValue = questionElement;
                    break;
                }
            }

            if (unknownValue.equals("")) {
                printAnswerList(question, sum);
            }
            else {
                if(this.logErrors) System.out.println("invalid input, value of '" + unknownValue + "' is unknown");
            }

        }
    }



    public void process(String inputTextPath) {
        /*
            Processes the given text with these steps
            1- reads the file
            2- iterates the lines while separating them for different precesses
            3- tries to solve equation lines
            4- answers questions
         */

        ArrayList<List<String>> questions = new ArrayList<List<String>>();       // ex:[["tomato", "potato", "strawberry"], [...]]
        ArrayList<List<String>> equations = new ArrayList<List<String>>();       // ex: [["potato", "carrot", "strawberry", "is", "102"], [...]]
        HashMap<String, Integer> shoppingItems = new HashMap<String, Integer>();    // ex: {"apple": 3, "melon": 1}

        // read the file
        ArrayList<List<String>> textLines = this.readShoppingListFile(inputTextPath);

        // Check if text exists
        if(textLines == null){
            System.out.println("There is a problem on the file on the path " + inputTextPath);
            return;
        }

        // Iterate over the input text line by line
        for (List<String> line : textLines) {

            // this line is a variable like
            if (line.size() == 3 && line.get(1).equals("is")) {

                String romanVal = line.get(2);
                int decimalVal;

                // try converting int first
                try{
                    decimalVal = Integer.valueOf(romanVal);
                    shoppingItems.put(line.get(0), decimalVal); // apple is 6
                }
                catch (NumberFormatException e){
                    // roman numeral conversion
                    if(!romanVal.equals("") && this.romanNumeralParser.isConvertible(romanVal)){
                        decimalVal = this.romanNumeralParser.toDecimal(romanVal);
                        shoppingItems.put(line.get(0), decimalVal); // apple is IV
                    }
                    else{
                        if(this.logErrors) System.out.println("Roman number is formatted wrong '" + romanVal + "' is not convertible from roman to decimal, skipping this line...");
                    }
                }


            }
            // this line is a question
            else if (line.get(0).equals("what")) {
                // ex: [what, is, the, price, of, tomato, peach, apple, carrot] returns [tomato, peach, apple, carrot]
                questions.add(line.subList(line.indexOf("of") + 1, line.size()));
            }
            // this line is equation like
            else {
                equations.add(line);
            }
        }



        // if equation order is not allow us to solve some of them on the first try, this loop will try to solve all of it until there is no progress.
        int oldLen = 0;
        do {
            System.out.println();
            oldLen = shoppingItems.size();

            // iterate over equations, try to solve them
            for (List equation : equations) {
                try {
                    shoppingItems = this.solveShoppingListEquation(equation, shoppingItems);
                }
                catch (ShoppingListEquationException e) {
                    if(this.logErrors) System.out.println("Can not solve " + equation + " I might try it again after other ones solved.");
                }
                catch (IllegalArgumentException e){
                    if(this.logErrors) System.out.println(e.getMessage());
                }
            }

        }while (shoppingItems.size() > oldLen);


        // answer the questions
        System.out.println();
        this.answerQuestions(questions, shoppingItems);



    }

}

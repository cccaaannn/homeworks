package com.can;


public class Main {
    public static void main(String[] args) {
        /*
            Pass a shopping list file path to 'process' function,
            you can also disable error logging from constructor
         */

        String inputTextPath = "src/inputFile.txt";
        // String inputTextPath = "src/inputFileHard.txt";
        ShoppingListProcessor shoppingListProcessor = new ShoppingListProcessor(true);
        shoppingListProcessor.process(inputTextPath);

    }
}

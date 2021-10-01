package com.can;

public class Main {
    public static void main(String[] args) {
        App app = new App();

        int dayLengthMs = 10000;  // length of a day, decreased for testing schedules.
        boolean onlyMenu = false;  // if true MessagingService wont run.
        app.start(dayLengthMs, onlyMenu);
    }
}

// for testing menu option 6
// user:   4de4f4d77bca4eb0b07cef36d57f3a49
// start:  2021-06-01
// end:    2021-09-01
// status: 0

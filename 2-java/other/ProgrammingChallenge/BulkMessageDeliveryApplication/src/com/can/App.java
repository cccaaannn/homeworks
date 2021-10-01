package com.can;


import java.util.ArrayList;
import java.util.Scanner;
import java.util.Timer;

public class App {
    public void start(int dayLengthMs, boolean onlyMenu){
        DBHandler dbHandler = new DBHandler();
        Scanner scanner = new Scanner(System.in);

        // messaging service
        if(!onlyMenu) {
            MessagingService messagingService = new MessagingService();

            Timer t = new Timer();
            t.scheduleAtFixedRate(messagingService, 0, dayLengthMs);

            System.out.println("MessagingService stated\n");
        }

        while(true) {
            System.out.print("\nMain menu\n\n1- Create user\n2- User menu\n\n0- exit\n:");
            int menuSelection = Integer.valueOf(scanner.nextLine().trim());

            if(menuSelection == 0){
                System.out.println("Good bye...");
                break;
            }

            // user adding
            else if (menuSelection == 1){
                System.out.println("Please enter a daily quota");
                int dailyQuota = Integer.valueOf(scanner.nextLine().trim());

                String apiKey = dbHandler.addUser(dailyQuota);
                if(apiKey != null){
                    System.out.println("New user has been successfully created\nYour api key is: " + apiKey + "\n");
                }
                else{
                    System.out.println("User creation error\n");
                }
            }

            // user menu
            else if (menuSelection == 2) {
                System.out.println("Please enter your api key for authentication");
                String apiKey = scanner.nextLine().trim();
                int userId = dbHandler.isUserExists(apiKey);

                if(userId == -1){
                    System.out.println("Sorry there is no user with this api key");
                }
                else {
                    while (true) {
                        System.out.print("\nUser menu\n\n1- Delete user\n2- Create a message schedule\n3- View a schedule with schedule id\n4- View schedules with status code\n5- Abort a schedule\n6- View sent message statuses\n\n0- Main menu");

                        // show total usage to user
                        ArrayList<Message> allMessages = dbHandler.getMessages("2020-01-01", "2099-01-01", userId);
                        System.out.println("\nTotal of " + allMessages.size() + " messages sent by this user (Api usage count)\n");

                        menuSelection = Integer.valueOf(scanner.nextLine().trim());

                        if (menuSelection == 0) {
                            break;
                        }

                        // user deleting
                        else if (menuSelection == 1) {
                            System.out.println("User with the " + apiKey + " will be deleted continue? (Y/N)");
                            String sure = scanner.nextLine().trim();

                            if (sure.equals("Y")) {
                                boolean res = dbHandler.deleteUser(apiKey);
                                if (res) {
                                    // exit from session on user deletion
                                    System.out.println("User has been successfully removed\n");
                                    break;
                                } else {
                                    System.out.println("User deletion error\n");
                                }
                            } else {
                                System.out.println("exited...");
                            }
                        }


                        // create scheduled message
                        else if (menuSelection == 2) {
                            System.out.println("Schedule messages menu\n");

                            System.out.println("Please enter recipients. ex: 0123,0541555,5550142");
                            String recipient_list = scanner.nextLine().trim();

                            System.out.println("Please enter starting date for scheduled messages. (formatting is important) ex: 2021-09-05");
                            String start_time = scanner.nextLine().trim();

                            System.out.println("Please enter end date for scheduled messages. (formatting is important) ex: 2021-09-20");
                            String end_time = scanner.nextLine().trim();

                            System.out.println("Please enter sender address. ex: SOME COMPANY");
                            String sender_address = scanner.nextLine().trim();

                            System.out.println("Please enter your message, messages has to be shorter than 1024 characters and not be empty. ex: hello world!");
                            String message = scanner.nextLine().trim();
                            boolean res = this.validateMessage(message);
                            if (!res) {
                                System.out.println("Sorry your message is not satisfies the parameters.");
                                continue;
                            }

                            // create scheduled message
                            int schedule_id = dbHandler.addScheduledMessage(userId, recipient_list, start_time, end_time, message, sender_address);

                            if (schedule_id == -1) {
                                System.out.println("Sorry schedule can not been created\n");
                            } else {
                                System.out.println("Scheduled message successfully created.\nYour schedule id for this schedule is: " + schedule_id + "\n");
                            }

                        }

                        // schedule viewing with id
                        else if (menuSelection == 3) {
                            System.out.println("Please enter your schedule id for viewing");
                            int schedule_id = Integer.valueOf(scanner.nextLine().trim());

                            if (dbHandler.isUserOwnsSchedule(schedule_id, userId)) {
                                ScheduledMessage scheduledMessage = dbHandler.getScheduledMessage(schedule_id);
                                if (scheduledMessage == null) {
                                    System.out.println("An error occurred\n");
                                } else {
                                    System.out.println(scheduledMessage.toString());
                                }
                            } else {
                                System.out.println("Sorry you don't own this schedule\n");
                            }

                        }

                        // schedule viewing with status
                        else if (menuSelection == 4) {
                            System.out.println("Please enter a status code for viewing, (0:ACTIVE, 1:COMPLETED, 2:ABORTED)");
                            int statusInt = Integer.valueOf(scanner.nextLine().trim());
                            String statusStr;

                            if (statusInt == 0) {
                                statusStr = "ACTIVE";
                            } else if (statusInt == 1) {
                                statusStr = "COMPLETED";
                            } else if (statusInt == 2) {
                                statusStr = "ABORTED";
                            } else {
                                System.out.println("Wrong input\n");
                                continue;
                            }

                            ArrayList<ScheduledMessage> scheduledMessages = dbHandler.getScheduledMessagesByStatus(userId, statusStr);
                            if (scheduledMessages == null) {
                                System.out.println("An error occurred\n");
                            } else {
                                ScheduledMessage.printScheduledMessageArray(scheduledMessages);
                            }
                        }

                        // schedule aborting
                        else if (menuSelection == 5) {
                            System.out.println("Please enter your schedule id for aborting");
                            int schedule_id = Integer.valueOf(scanner.nextLine().trim());

                            if (dbHandler.isUserOwnsSchedule(schedule_id, userId)) {
                                dbHandler.updateScheduledMessageStatus(schedule_id, "ABORTED");
                                System.out.println("Scheduled message aborted\n");
                            } else {
                                System.out.println("Sorry you don't own this schedule\n");
                            }

                        }

                        // View sent message statuses
                        else if (menuSelection == 6) {
                            System.out.println("Please enter a starting date. (formatting is important) ex: 2021-09-05");
                            String start_time = scanner.nextLine().trim();

                            System.out.println("Please enter an ending date. (formatting is important) ex: 2021-09-20");
                            String end_time = scanner.nextLine().trim();

                            System.out.println("Please enter a status code.(success:0, unreachable:1, network_error:2, unknown_error:3) ex: 0");
                            int message_status = Integer.valueOf(scanner.nextLine().trim());

                            // total messages
                            ArrayList<Message> allMessagesPeriod = dbHandler.getMessages(start_time, end_time, userId);
                            System.out.println("\nTotal of " + allMessagesPeriod.size() + " messages sent by this user in this period (Api usage count)\n");

                            // with the status code
                            ArrayList<Message> messages = dbHandler.getMessages(start_time, end_time, userId, message_status);
                            System.out.println("Messages with the status code " + message_status + " are below. (" + messages.size() + ")");
                            Message.printMessageArray(messages);
                        }

                    }
                }

            }

        }



    }


    private static boolean validateMessage(String message){
        if(message.equals("") || message.length() > 1024 || message == null){
            return false;
        }
        else{
            return true;
        }
    }



}

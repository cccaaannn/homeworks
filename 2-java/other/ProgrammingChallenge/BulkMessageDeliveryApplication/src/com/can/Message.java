package com.can;

import java.util.ArrayList;

public class Message {
    private int message_id;
    private int user_id;
    private int schedule_id;
    private String recipient_num;
    private int message_status;
    private String timestamp;

    public Message(int message_id, int user_id, int schedule_id, String recipient_num, int message_status, String timestamp) {
        this.message_id = message_id;
        this.user_id = user_id;
        this.schedule_id = schedule_id;
        this.recipient_num = recipient_num;
        this.message_status = message_status;
        this.timestamp = timestamp;
    }


    public static void printMessageArray(ArrayList<Message> messages){
        if(messages.size() == 0){
            System.out.println("No messages found");
        }
        else {
            for (Message message : messages) {
                System.out.println(message.toString());
            }
        }
    }


    public int getMessage_id() {
        return message_id;
    }

    public void setMessage_id(int message_id) {
        this.message_id = message_id;
    }

    public int getUser_id() {
        return user_id;
    }

    public void setUser_id(int user_id) {
        this.user_id = user_id;
    }

    public int getSchedule_id() {
        return schedule_id;
    }

    public void setSchedule_id(int schedule_id) {
        this.schedule_id = schedule_id;
    }

    public String getRecipient_num() {
        return recipient_num;
    }

    public void setRecipient_num(String recipient_num) {
        this.recipient_num = recipient_num;
    }

    public int getMessage_status() {
        return message_status;
    }

    public void setMessage_status(int message_status) {
        this.message_status = message_status;
    }

    public String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }

    @Override
    public String toString() {
        return "Message{" +
                "message_id=" + message_id +
                ", user_id=" + user_id +
                ", schedule_id=" + schedule_id +
                ", recipient_num='" + recipient_num + '\'' +
                ", message_status=" + message_status +
                ", timestamp='" + timestamp + '\'' +
                '}';
    }
}

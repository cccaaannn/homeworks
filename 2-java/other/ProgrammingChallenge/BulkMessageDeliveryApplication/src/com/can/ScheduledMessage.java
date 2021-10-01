package com.can;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;

public class ScheduledMessage {
    private int schedule_id;
    private int user_id;
    private String recipient_list;
    private String start_time;
    private String end_time;
    private String message;
    private String status;
    private String sender_address;

    public ScheduledMessage(int schedule_id, int user_id, String recipient_list, String start_time, String end_time, String message, String status, String sender_address) {
        this.schedule_id = schedule_id;
        this.user_id = user_id;
        this.recipient_list = recipient_list;
        this.start_time = start_time;
        this.end_time = end_time;
        this.message = message;
        this.status = status;
        this.sender_address = sender_address;
    }

    public int testTimePeriod(){
        try{
            SimpleDateFormat dt = new SimpleDateFormat("yyyy-MM-dd");
            Date startDate = dt.parse(start_time);
            Date endDate = dt.parse(end_time);
            Date now = new Date();

            // not stared
            if(now.before(startDate)){
                return -1;
            }
            // in time
            else if(now.after(startDate) && now.before(endDate)) {
                return 0;
            }
            // passed
            else if(now.after(endDate)) {
                return 1;
            }

        }
        // error
        catch (ParseException e){
            return 2;
        }
        return 2;
    }

    public ArrayList<String> getRecipientsAsList(){
        return new ArrayList<String>(Arrays.asList(this.recipient_list.split(",")));
    }

    public static void printScheduledMessageArray(ArrayList<ScheduledMessage> scheduledMessages){
        if(scheduledMessages.size() == 0){
            System.out.println("No scheduledMessages found");
        }
        else {
            for (ScheduledMessage scheduledMessage : scheduledMessages) {
                System.out.println(scheduledMessage.toString());
            }
        }
    }

    public int getSchedule_id() {
        return schedule_id;
    }

    public int getUser_id() {
        return user_id;
    }

    public String getRecipient_list() {
        return recipient_list;
    }

    public String getStart_time() {
        return start_time;
    }

    public String getEnd_time() {
        return end_time;
    }

    public String getMessage() {
        return message;
    }

    public String getStatus() {
        return status;
    }

    public String getSender_address() {
        return sender_address;
    }


    @Override
    public String toString() {
        return "ScheduledMessage{" +
                "schedule_id=" + schedule_id +
                ", user_id=" + user_id +
                ", recipient_list='" + recipient_list + '\'' +
                ", start_time='" + start_time + '\'' +
                ", end_time='" + end_time + '\'' +
                ", message='" + message + '\'' +
                ", status='" + status + '\'' +
                ", sender_address='" + sender_address + '\'' +
                '}';
    }

}

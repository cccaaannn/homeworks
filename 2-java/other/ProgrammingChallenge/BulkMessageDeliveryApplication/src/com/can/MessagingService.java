package com.can;

import java.util.ArrayList;
import java.util.TimerTask;

public class MessagingService extends TimerTask {
    DBHandler dbHandler;

    MessagingService(){
        this.dbHandler = new DBHandler();
    }


    @Override
    public void run() {

        // new day, reset all usages
        this.dbHandler.resetAllUserUsage();

        // get all active scheduled messages
        ArrayList<ScheduledMessage> scheduledMessages = this.dbHandler.getScheduledMessagesByStatus("ACTIVE");

        // System.out.println("active messages: " + scheduledMessages.toString());

        for (ScheduledMessage scheduledMessage: scheduledMessages) {

            // check user quota
            if(!this.dbHandler.isUserQuotaReached(scheduledMessage.getUser_id())){

                // get message period
                int period = scheduledMessage.testTimePeriod();
                //System.out.println("message period test result: " + period + " schedule_id: " + scheduledMessage.getSchedule_id());

                // if end date is passed, update database
                if(period == 1){
                    this.dbHandler.updateScheduledMessageStatus(scheduledMessage.getSchedule_id(), "COMPLETED");
                }
                // if now is in the period
                else if(period == 0){
                    // start MessageSenders
                    for (String recipient: scheduledMessage.getRecipientsAsList()) {
                        new MessageSender(scheduledMessage.getUser_id(), scheduledMessage.getSchedule_id(), scheduledMessage.getSender_address(), recipient, scheduledMessage.getMessage()).start();

                        // increase user usage quota
                        this.dbHandler.increaseUserUsage(scheduledMessage.getUser_id());
                    }
                }
            }

        }

    }


}

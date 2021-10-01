package com.can;

public class MessageSender extends Thread{
    private MessageServiceCenter msc;
    private DBHandler dbHandler;
    private int user_id;
    private int schedule_id;
    private String senderAddress;
    private String destinationNumber;
    private String messageBody;

    MessageSender(int user_id, int schedule_id, String senderAddress, String destinationNumber, String messageBody){
        this.msc = new MessageServiceCenter();
        this.dbHandler = new DBHandler();
        this.user_id = user_id;
        this.schedule_id = schedule_id;
        this.senderAddress = senderAddress;
        this.destinationNumber = destinationNumber;
        this.messageBody = messageBody;
    }

    @Override
    public void run() {
        super.run();

        for (int i = 0; i < 3; i++) {
            // try to submit message
            int status = this.msc.submitMessage(this.senderAddress, this.destinationNumber, this.messageBody);

            // save message status to db
            dbHandler.addMessage(this.user_id, this.schedule_id, this.destinationNumber, status);

            //System.out.println(status);

            // quit on success
            if(status == 0){
                break;
            }

            // wait 1 sec before retry
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

package com.can;

import java.sql.*;
import java.util.ArrayList;
import java.util.UUID;

public class DBHandler {

    private Connection connect() {
        /*
            connects to db
         */

        String url = "jdbc:sqlite:src/db.db";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url);
            //System.out.println("db connected");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return conn;
    }


    // user functions
    public String addUser(int daily_quota) {
        /*
            Adds user, generates a random api_key with uuid and returns it
         */

        String sql = "INSERT INTO users(api_key, daily_quota, api_requests) VALUES(?,?,?)";

        String api_key = UUID.randomUUID().toString().replace("-", "");
        int api_requests = 0;

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, api_key);
            pstmt.setInt(2, daily_quota);
            pstmt.setInt(3, api_requests);
            pstmt.executeUpdate();
            conn.close();

            return api_key;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }

    public boolean deleteUser(String api_key) {
        /*
            Deletes user with api_key
         */
        String sql = "DELETE FROM users WHERE api_key = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, api_key);
            pstmt.executeUpdate();
            conn.close();

            return true;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return false;
        }
    }

    public int isUserExists(String api_key) {
        /*
            Returns user_id if api_key exists
         */
        String sql = "SELECT * FROM users WHERE api_key = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, api_key);
            ResultSet rs = pstmt.executeQuery();
            int id = rs.getInt("user_id");
            conn.close();

            return id;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return -1;
        }
    }


    public boolean increaseUserUsage(int user_id) {
        /*
            Increases api_requests for this user. (for daily usage)
         */

        String sql = "UPDATE users SET api_requests = api_requests + 1 WHERE user_id = ?;";

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, user_id);
            pstmt.executeUpdate();
            conn.close();

            return true;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return false;
        }

    }

    public boolean resetAllUserUsage() {
        /*
            resets api_requests for this all users. (for daily usage)
         */

        String sql = "UPDATE users SET api_requests = 0;";

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.executeUpdate();
            conn.close();

            return true;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return false;
        }

    }

    public boolean isUserQuotaReached(int user_id) {
        /*
            Checks if user reached their daily quota.
         */

        String sql = "SELECT * FROM users WHERE user_id = ?;";

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, user_id);
            ResultSet rs = pstmt.executeQuery();
            int currentUsage = rs.getInt("api_requests");
            int quota = rs.getInt("daily_quota");
            conn.close();

            if(currentUsage < quota){
                return false;
            }
            else{
                return true;
            }

        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return true;
        }

    }


    // scheduled message functions
    public int addScheduledMessage(int user_id, String recipient_list, String start_time, String end_time, String message, String sender_address) {
        /*
            Creates a scheduled message.
         */

        String sql = "INSERT INTO scheduled_messages(user_id, recipient_list, start_time, end_time, message, status, sender_address)  VALUES(?,?,?,?,?,?,?);";

        String status = "ACTIVE";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            pstmt.setInt(1, user_id);
            pstmt.setString(2, recipient_list);
            pstmt.setString(3, start_time);
            pstmt.setString(4, end_time);
            pstmt.setString(5, message);
            pstmt.setString(6, status);
            pstmt.setString(7, sender_address);
            pstmt.executeUpdate();
            ResultSet rs = pstmt.getGeneratedKeys();

            // get generated id
            int schedule_id = -1;
            if (rs.next()) {
                schedule_id = rs.getInt(1);
            }
            conn.close();

            return schedule_id;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return -1;
        }
    }


    public boolean updateScheduledMessageStatus(int schedule_id, String status) {
        /*
            Updates a scheduled message status.
         */
        String sql = "UPDATE scheduled_messages SET status = ? WHERE schedule_id = ?;";

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, status);
            pstmt.setInt(2, schedule_id);
            pstmt.executeUpdate();
            conn.close();

            return true;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return false;
        }

    }


    public ScheduledMessage getScheduledMessage(int schedule_id) {
        /*
            Returns a scheduled message with all of its content.
         */
        String sql = "SELECT * FROM scheduled_messages WHERE schedule_id = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, schedule_id);
            ResultSet rs = pstmt.executeQuery();

            ScheduledMessage scheduledMessage = new ScheduledMessage(
                    rs.getInt("schedule_id"),
                    rs.getInt("user_id"),
                    rs.getString("recipient_list"),
                    rs.getString("start_time"),
                    rs.getString("end_time"),
                    rs.getString("message"),
                    rs.getString("status"),
                    rs.getString("sender_address")
            );
            conn.close();

            return scheduledMessage;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }


    public ArrayList<ScheduledMessage> getScheduledMessagesByStatus(String status) {
        /*
            Returns scheduled messages by their status code for a all users
         */
        String sql = "SELECT * FROM scheduled_messages WHERE status = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, status);
            ResultSet rs = pstmt.executeQuery();

            ArrayList<ScheduledMessage> scheduledMessages = new ArrayList<ScheduledMessage>();

            while(rs.next()){
                ScheduledMessage scheduledMessage = new ScheduledMessage(
                        rs.getInt("schedule_id"),
                        rs.getInt("user_id"),
                        rs.getString("recipient_list"),
                        rs.getString("start_time"),
                        rs.getString("end_time"),
                        rs.getString("message"),
                        rs.getString("status"),
                        rs.getString("sender_address")
                );

                scheduledMessages.add(scheduledMessage);
            }

            conn.close();

            return scheduledMessages;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }


    public ArrayList<ScheduledMessage> getScheduledMessagesByStatus(int user_id, String status) {
        /*
            Returns scheduled messages by their status code for a specific user
         */
        String sql = "SELECT * FROM scheduled_messages WHERE user_id = ? AND status = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, user_id);
            pstmt.setString(2, status);
            ResultSet rs = pstmt.executeQuery();

            ArrayList<ScheduledMessage> scheduledMessages = new ArrayList<ScheduledMessage>();

            while(rs.next()){
                ScheduledMessage scheduledMessage = new ScheduledMessage(
                        rs.getInt("schedule_id"),
                        rs.getInt("user_id"),
                        rs.getString("recipient_list"),
                        rs.getString("start_time"),
                        rs.getString("end_time"),
                        rs.getString("message"),
                        rs.getString("status"),
                        rs.getString("sender_address")
                );

                scheduledMessages.add(scheduledMessage);
            }

            conn.close();

            return scheduledMessages;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }


    public boolean isUserOwnsSchedule(int schedule_id, int user_id) {
        /*
            Returns true if user owns schedule with this id
         */
        String sql = "SELECT * FROM scheduled_messages WHERE schedule_id = ? AND user_id = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, schedule_id);
            pstmt.setInt(2, user_id);
            ResultSet rs = pstmt.executeQuery();

            rs.getInt("user_id");

            conn.close();

            return true;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return false;
        }
    }



    // message functions
    public int addMessage(int user_id, int schedule_id, String recipient_num, int message_status) {
        /*

         */

        String sql = "INSERT INTO messages(user_id, schedule_id, recipient_num, message_status)  VALUES(?,?,?,?);";

        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
            pstmt.setInt(1, user_id);
            pstmt.setInt(2, schedule_id);
            pstmt.setString(3, recipient_num);
            pstmt.setInt(4, message_status);
            pstmt.executeUpdate();
            ResultSet rs = pstmt.getGeneratedKeys();

            // get generated id
            int message_id = -1;
            if (rs.next()) {
                message_id = rs.getInt(1);
            }
            conn.close();

            return message_id;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return -1;
        }
    }


    public ArrayList<Message> getMessages(String startDate, String endDate, int user_id) {
        /*
            Returns messages in a time period for a specific user without status
         */
        String sql = "SELECT * FROM messages WHERE (timestamp BETWEEN ? AND ?) AND user_id = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, startDate);
            pstmt.setString(2, endDate);
            pstmt.setInt(3, user_id);
            ResultSet rs = pstmt.executeQuery();

            ArrayList<Message> scheduledMessages = new ArrayList<Message>();

            while(rs.next()){
                Message message = new Message(
                        rs.getInt("message_id"),
                        rs.getInt("user_id"),
                        rs.getInt("schedule_id"),
                        rs.getString("recipient_num"),
                        rs.getInt("message_status"),
                        rs.getString("timestamp")
                );

                scheduledMessages.add(message);
            }

            conn.close();

            return scheduledMessages;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }


    public ArrayList<Message> getMessages(String startDate, String endDate, int user_id, int message_status) {
        /*
            Returns messages in a time period for a specific user with status
         */
        String sql = "SELECT * FROM messages WHERE (timestamp BETWEEN ? AND ?) AND message_status = ? AND user_id = ?;";
        try{
            Connection conn = this.connect();
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, startDate);
            pstmt.setString(2, endDate);
            pstmt.setInt(3, message_status);
            pstmt.setInt(4, user_id);
            ResultSet rs = pstmt.executeQuery();

            ArrayList<Message> scheduledMessages = new ArrayList<Message>();

            while(rs.next()){
                Message message = new Message(
                        rs.getInt("message_id"),
                        rs.getInt("user_id"),
                        rs.getInt("schedule_id"),
                        rs.getString("recipient_num"),
                        rs.getInt("message_status"),
                        rs.getString("timestamp")
                );

                scheduledMessages.add(message);
            }

            conn.close();

            return scheduledMessages;
        } catch (SQLException e) {
            //System.out.println(e.getMessage());
            return null;
        }
    }

}
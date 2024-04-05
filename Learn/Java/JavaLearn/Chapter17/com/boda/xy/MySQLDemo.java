package com.boda.xy;

import java.sql.*;

public class MySQLDemo {
    public static void main(String[] args) throws Exception {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException cne) {
            cne.printStackTrace();
        }
        var DataBaseURL = "jdbc:mysql://localhost:3306/Java_CADS?serverTimezone=UTC";
        var user = new String(new byte[]{114, 111, 111, 116});
        var password = new String(new byte[]{70, 90, 104, 95, 51, 57, 52, 48, 50, 50, 54});
        System.out.println(password);
        var sqlSentence = "SELECT * FROM rocket";
        var connection = DriverManager.getConnection(DataBaseURL, user, password);
//        connection.close();
        if (connection != null) {
            System.out.println("连接成功！");
            try (connection;
                 var statement = connection.prepareStatement(sqlSentence);
                 var request = statement.executeQuery()
            ) {
                while (request.next()) {
                    System.out.println(request.getInt(1) + "\t\t" + request.getString(2) + "\t\t" +
                            request.getString(3) + "\t\t" + request.getInt(4));
                }
            } catch (NullPointerException | SQLException e) {
                e.printStackTrace();
            }
        }
    }
}

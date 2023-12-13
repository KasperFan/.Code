package com.boda.xy;

import java.sql.*;

public class MySQLDemo {
    public static void main(String[] args) throws Exception {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException cne) {
            cne.getStackTrace();
        }
        var DataBaseURL = "jdbc:mysql://localhost:3306/webstore?serverTimezone=UTC";
        var user = java.util.Arrays.toString(new byte[]{114, 111, 111, 116});
        var password = java.util.Arrays.toString(new byte[]{70, 90, 104, 95, 51, 57, 52, 48, 50, 50, 54});
        var sqlSentence = "SELECT * FROM books";
        var connection = DriverManager.getConnection(DataBaseURL, user, password);
        if (connection != null) {
            System.out.println("连接成功！");
            try (connection;
                 var statement = connection.prepareStatement(sqlSentence);
                 var request = statement.executeQuery()
            ) {
                while (request.next()) {
                    System.out.println(request.getInt(1) + "\t\t" + request.getString(2) + "\t\t" +
                            request.getString(3) + "\t\t" + request.getDouble(4) + "\t\t" +
                            request.getString(5));
                }
            } catch (NullPointerException | SQLException e) {
                e.getStackTrace();
            }
        }
    }
}

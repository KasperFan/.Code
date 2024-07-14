package com.boda.xy;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import java.beans.PropertyVetoException;
import java.sql.*;


public class DataSourceDemo {
    public static void main(String[] args) throws Exception {
        var sql = "SELECT * FROM books WHERE id < 104";
        try (var dbconn = getConnection();
             var stmt = dbconn.prepareStatement(sql);
             var rst = stmt.executeQuery()) {
            while (rst.next()) {
                System.out.println(
                        rst.getInt(1) + "\t" + rst.getString(2)
                                + "\t" + rst.getString(3) + "\t"
                                + rst.getDouble(4)
                );
            }
        } catch (SQLException e) {
            e.printStackTrace(System.out);
        }
    }

    private static Connection getConnection() throws PropertyVetoException, SQLException {
        ComboPooledDataSource dataSource = new ComboPooledDataSource();
        var driver = "com.mysql.cj.jdbc.Driver";
        var dburl = "jdbc:mysql://localhost:3306/webstore?&useUnicode=true&characterEncoding=utf8&serverTimezone=UTC";
        var user = new String(new byte[]{114, 111, 111, 116});
        var password = new String(new byte[]{70, 90, 104, 95, 51, 57, 52, 48, 50, 50, 54});
        dataSource.setDriverClass(driver);
        dataSource.setJdbcUrl(dburl);
        dataSource.setUser(user);
        dataSource.setPassword(password);
        dataSource.setMaxPoolSize(40);
        dataSource.setMinPoolSize(2);
        dataSource.setInitialPoolSize(10);
        dataSource.setMaxStatements(100);

        var dbconn = dataSource.getConnection();
        return dbconn;
    }
}

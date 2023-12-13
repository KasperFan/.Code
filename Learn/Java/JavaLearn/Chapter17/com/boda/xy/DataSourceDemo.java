package com.boda.xy;

import com.mchange.v2.c3p0.ComboPooledDataSource;


public class DataSourceDemo {
    public static void main(String[] args) throws Exception {
        for (var i :
                "FZh_3940226".getBytes()) {
            System.out.println(i);
        }
        ComboPooledDataSource dataSource = new ComboPooledDataSource();
        var driver = "com.mysql.cj.jdbc.Driver";
        var dburl = "jdbc:mysql://localhost:3306/webstore?&useUnicode=true&characterEncoding=utf8&serverTimezone=UTC";
        var user = java.util.Arrays.toString(new byte[]{114, 111, 111, 116});
        var password = java.util.Arrays.toString(new byte[]{70, 90, 104, 95, 51, 57, 52, 48, 50, 50, 54});
        dataSource.setDriverClass(driver);
        dataSource.setJdbcUrl(dburl);
        dataSource.setUser(user);
        dataSource.setPassword(password);
        dataSource.setMaxPoolSize(40);
        dataSource.setMinPoolSize(2);
        dataSource.setInitialPoolSize(10);
        dataSource.setMaxStatements(100);
    }
}

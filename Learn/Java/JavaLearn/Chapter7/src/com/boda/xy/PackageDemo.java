package com.boda.xy;

import java.util.*;
import java.sql.*;


public class PackageDemo {
    public static void main(String[] args) {
        /**
         * 对 'Date' 的引用不明确，'java.util.Date' 和 'java.sql.Date' 均匹配
         * */
//        Date d = new Date();
        /* 因为在java.util包和java.sql包中都有Date类，编译器不知道创建哪个类的对象
        * 这时需要使用类的完全限定名 */
        java.util.Date d = new java.util.Date();
        System.out.println("d = " + d);
    }
}

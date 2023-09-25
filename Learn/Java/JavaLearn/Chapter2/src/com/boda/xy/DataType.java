package com.boda.xy;

public class DataType {
    //  类（抽象类）
    static class Student {
    }

    //  接口
    interface Player {
    }

    //  枚举
    enum Color {RED, GREEN, BLUE}

    //  记录（Java 17新特性）
    record Point(int x, int y) {
    }

    //  注解
    @interface Author {
    }

    //  数组
    int[] number;

    public static void main(String[] args) {
        Student stud = new Student();
//        Player p = new MusicPlayer();
        Color c = Color.BLUE;
//        public class Employee{}
//
    }
}

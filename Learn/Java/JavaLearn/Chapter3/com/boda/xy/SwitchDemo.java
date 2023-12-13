package com.boda.xy;

import java.util.Scanner;

public class SwitchDemo {
    enum Season {Spring, Summer, Fall, Winter}

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("输入一个季节(1,2,3,4):");
        var season = Season.Spring.ordinal();
//      传统switch语句
        switch (season) {
            case 1:
                System.out.println("1");
                System.out.println("456");
                break;
            case 2:
                System.out.println("2");
                break;
            case 3:
                System.out.println("3");
                break;
            case 4:
                System.out.println("4");
                break;
            default:
                System.out.println("?");
                break;
        }
//      增强switch语法糖(Java 14新特性)
        switch (season) {
            case 1 -> System.out.println("1");
            case 2 -> System.out.println("2");
            case 3 -> System.out.println("3");
            case 4 -> System.out.println("4");
            default -> System.out.println("?");
        }
//        new Scanner(System)
    }
}

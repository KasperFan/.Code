package com.boda.practice;

import java.util.Arrays;
import java.util.Scanner;

public class StringPractice {
    public static void ansOne() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入包括中文、大小写英文、数字和一个特殊字符的字符串:");
        String str = sc.nextLine();
        System.out.println("str.length = " + str.length());
        System.out.println("str.charAt(head) = " + str.charAt(0));
        System.out.println("str.charAt(tail) = " + str.charAt(str.length() - 1));
    }

    public static void ansTwo() {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine(), str2 = sc.nextLine();
        System.out.println(str1.contains(str2));
    }

    public static boolean ansThree() {
        Scanner sc = new Scanner(System.in);
        String ISBN = sc.nextLine();
        if (ISBN.length() == 17) {
            return ISBN.charAt(3) == '-' && ISBN.charAt(5) == '-' && ISBN.charAt(9) == '-' && ISBN.charAt(15) == '-';
        } else return false;
    }

    public static int countLetters(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                count++;
            }
        }
        return count;
    }

    public static String toBinary(int value) {
//        return Integer.toBinaryString(value);
        StringBuilder stringBuilder = new StringBuilder();
        while (value > 0) {
            stringBuilder.append(value % 2);
            value /= 2;
        }
        return stringBuilder.reverse().toString();
    }

    public static String sort(String s) {
        char[] array = s.toCharArray();
        Arrays.sort(array);
        return new String(array);
    }

    public static String[] splitToStringArray(String s) {
        String[] result = s.split("[,\\s]");
        return result;
    }



    public static void main(String[] args) {
//        ansOne();
//        ansTwo();
//        System.out.println(toBinary(10));
//        for (var str :
//                splitToStringArray("no pains,no gains.")) {
//            System.out.println(str);
//        }
//        System.out.println(sort("morning"));
        int[] array = new int[args.length];
        for (int i = 0; i < array.length; i++) {
            array[i]=Integer.parseInt(args[i]);
        }
        System.out.println(array[2] > (array[0] > array[1] ? array[0] : array[1]) ? array[2] : (array[0] > array[1] ? array[0] : array[1]));
        System.out.println(array[2] < (array[0] < array[1] ? array[0] : array[1]) ? array[2] : (array[0] < array[1] ? array[0] : array[1]));
    }
}

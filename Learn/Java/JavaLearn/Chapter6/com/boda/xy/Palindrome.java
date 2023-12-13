package com.boda.xy;

import java.util.Scanner;

public class Palindrome {
    public static boolean isPalindrome(String s) {
//        int head = 0, tail = s.length() - 1;
//        while (head < tail) {
//            if (s.charAt(head++) != s.charAt(tail--))
//                return false;
//        }
//        return true;
        /* 借用StringBuilder类的方法 */
        StringBuilder stringBuilder = new StringBuilder(s);
        return stringBuilder.toString().equals(stringBuilder.reverse().toString());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入一个字符串:");
        var s = sc.nextLine();
        /* 以下两个方法等效 */
        // if条件分支判断
        if (isPalindrome(s))
            System.out.println(s + ":是回文。");
        else
            System.out.println(s + ":不是回文。");
        // 三元运算符
        System.out.println(s + ":" + (isPalindrome(s) ? "" : "不") + "是回文。");
    }
}

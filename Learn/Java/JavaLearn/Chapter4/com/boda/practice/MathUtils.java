package com.boda.practice;

import java.util.Scanner;

public class MathUtils {
    public static boolean isPrime(int num) {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static boolean isPalindromes(int num) {
        /**
         * 常规方法，逐位倒置后结果比较
         * */
//        int temp = num, reverse = 0;
//        while (temp > 0) {
//            reverse = reverse * 10 + temp % 10;
//            temp /= 10;
//        }
//        return num == reverse;
        /**
         * 使用StringBuilder或StringBuffer类将数据处理为字符串直接倒置实现
         * */
        StringBuilder stringBuilder = new StringBuilder(String.valueOf(num));
        return stringBuilder.toString().contentEquals(stringBuilder.reverse().toString());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        int all = sc.nextInt();
        var count = 0;
        for (int n = 2; count < 20; n++) {
            if (isPalindromes(n) && isPrime(n)) {
                count++;
                if (count % 10 == 0) System.out.printf(" %5s%n", n);
                else System.out.printf(" %5s", n);
            }
        }
    }
}

package com.boda.practice;

import java.util.Scanner;

public class GCD {
    public static int gcd(int m, int n) {
        if (m % n == 0) {
            return n;
        } else return gcd(n, m % n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a= sc.nextInt(),b= sc.nextInt();
        int individual = gcd(a,b);
        System.out.println(individual);
        System.out.println(a / individual + " " + b / individual);
    }
}

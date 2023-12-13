package com.boda.xy;

public class FibonacciNumber {
    public static long fibo(int n) {
        if (n == 1 || n == 2) {
            return 1;
        } else {
            return fibo(n - 1) + fibo(n - 2);
        }
    }

    public static void main(String[] args) {
        /* 递归方法调用 */
        for (int i = 1; i <= 20; i++) {
            System.out.println("fibo(" + i + ")=" + fibo(i));
        }
        System.out.println("fibo(19)/fibo(20)=" + fibo(19) * 1.0 / fibo(20));
    }
}

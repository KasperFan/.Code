package com.boda.xy;

public class FractionDemo {
    public static void main(String[] args) {
        Fraction a = new Fraction(3, -8);
        Fraction b = new Fraction(21, 15);
        System.out.println("a + b =" + a.add(b));
        System.out.println("a - b =" + a.subtract(b));
        System.out.println("a * b =" + a.multiply(b));
        System.out.println("a / b =" + a.divide(b));
    }
}

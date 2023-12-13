package com.boda.practice;

public class QuadraticEquation {
    private double a, b, c;

    public QuadraticEquation(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double getDiscriminant() {
        return Math.pow(b, 2) - 4 * a * c;
    }

    public double getRoot1() {
        double discriminant = this.getDiscriminant();
        if (discriminant < 0) {
            System.out.println("方程无根");
            return Double.parseDouble(null);
        } else return (-b + Math.sqrt(discriminant)) / 2 * a;
    }
    public double getRoot2() {
        double discriminant = this.getDiscriminant();
        if (discriminant < 0) {
            System.out.println("方程无根");
            return Double.parseDouble(null);
        } else return (-b - Math.sqrt(discriminant)) / 2 * a;
    }
}

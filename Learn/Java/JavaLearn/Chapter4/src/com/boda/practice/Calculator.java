package com.boda.practice;

public class Calculator {
    private double a, b;

    public Calculator() {
    }

    public Calculator(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public void setA(double a) {
        this.a = a;
    }

    public void setB(double b) {
        this.b = b;
    }

    public double add() {
        return a + b;
    }

    public double minus() {
        return a - b;
    }

    public double multiply() {
        return a * b;
    }

    public double divide() {
        if (b == 0) throw new RuntimeException("除数不可为0!");
        else return a / b;
    }
}

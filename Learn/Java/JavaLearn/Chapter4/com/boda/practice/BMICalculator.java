package com.boda.practice;

public class BMICalculator {
    private double weight, height, bmi;

    public BMICalculator(double weight, double height) {
        this.weight = weight;
        this.height = height;
    }

    public void calculate() {
        bmi = weight / Math.pow(height, 2);
    }
    public boolean isOverWeight(){
        return bmi>25;
    }
}

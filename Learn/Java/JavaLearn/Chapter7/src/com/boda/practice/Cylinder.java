package com.boda.practice;

public class Cylinder extends Circle {
    double height;

    public Cylinder() {
    }

    public Cylinder(double radius, double height) {
        super(radius);
        this.height = height;
    }

    @Override
    public double getArea() {
        return 2 * super.getArea() + super.getPerimeter() * height;
    }

    public double getVolume() {
        return super.getArea() * height;
    }
}

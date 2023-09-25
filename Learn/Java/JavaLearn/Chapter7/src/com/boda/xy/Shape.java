package com.boda.xy;

public abstract class Shape {
    String name;

    public Shape() {
    }

    public Shape(String name) {
        this.name = name;
    }
    public abstract double getArea();
    public abstract double getPerimeter();
}

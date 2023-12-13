package com.boda.practice;

import com.boda.xy.Shape;

public class Square extends Shape {
    double edge;

    public Square(double edge) {
        this.edge = edge;
    }

    @Override
    public double getArea() {
        return Math.pow(edge, 2);
    }

    @Override
    public double getPerimeter() {
        return edge * 4;
    }
}

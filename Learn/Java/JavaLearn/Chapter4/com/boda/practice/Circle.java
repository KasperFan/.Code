package com.boda.practice;

import com.boda.xy.Shape;

public class Circle extends Shape {
    double centerX;
    double centerY;
    double radius;


    public Circle() {
        this(1.0);
    }

    public Circle(double radius) {
        /* 调用父类的构造方法 */
        super("圆");
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    /**
     * 实现父类的抽象方法
     */
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    /**
     * 实现父类的抽象方法
     */
    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public String toString() {
        return "[圆] radius=" + radius;
    }
}

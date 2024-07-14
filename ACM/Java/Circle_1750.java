/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2022-11-30 09:43:40
 * @LastEditTime: 2024-04-05 21:15:51
 * @FilePath: /Java/Circle_1750.java
 * @Description: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
import java.lang.Math;
import java.util.Scanner;

class Circle_1750 {
    static final double PI = 3.1415926;

    public static class Circle {
        double x = 0;
        double y = 0;
        double radious = 1;

        public Circle() {
        }
        
        public Circle(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public Circle(double radious) {
            this.radious = radious;
        }

        public Circle(double x, double y, double radious) {
            this.x = x;
            this.y = y;
            this.radious = radious;
        }

        public double getArea() {
            return PI * this.radious * this.radious;
        }

        public double getPerimeter() {
            return PI * this.radious * 2;
        }

        public boolean contains(double x, double y) {
            if (Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2)) <= this.radious)
                return true;
            else
                return false;
        }

        public boolean contains(Circle inCircle) {
            if (Math.sqrt(Math.pow(inCircle.x - this.x, 2) + Math.pow(inCircle.y - this.y, 2))
                    + inCircle.radious <= this.radious)
                return true;
            else
                return false;
        }

        public boolean overlaps(Circle inCircle) {
            if (inCircle.x == this.x && inCircle.y == this.y && inCircle.radious == this.radious)
                return true;
            else
                return false;
        }

        // public double getMaxProCoordinates() {
        // // if ()
        // }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Circle O = new Circle();
        Circle C = new Circle(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
        sc.close();
        System.out.println();
        System.out.println(C.getPerimeter() + ' ' + C.radious);
        System.out.println("Is contain?=" + C.contains(O) + "\nIs overlaps? =" + C.overlaps(O));

    }
}

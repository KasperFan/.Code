package com.boda.xy;

import java.util.Scanner;

public class ComputeArea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double radius;
        double area, perimeter;
        System.out.print("请输入半径值：");
        radius = input.nextDouble();
        area = Math.PI * radius * radius;
        perimeter = 2 * Math.PI * radius;
        System.out.println(area);
        System.out.println(perimeter);
    }
}

package com.boda.practice;

import com.boda.utils.Input;

public class Test {
    public static void main(String[] args) {
        long start=System.nanoTime();
        System.out.print("请输入一个浮点数：");
        double d = Input.readDouble();
        System.out.println("d = " + d);
        System.out.print("请输入一个整数：");
        int n = Input.readInt();
        System.out.println("n = " + n);
        System.out.print("请输入一行字符串：");
        System.out.println(Input.readString());
        System.out.println(Input.readChar());
        long end = System.nanoTime();
        System.out.println(end - start);
    }
}
// 123.4 123asdfghjklfgbo
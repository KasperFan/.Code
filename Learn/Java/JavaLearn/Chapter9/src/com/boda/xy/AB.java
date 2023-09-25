package com.boda.xy;

public class AB implements AA,BB {

    @Override
    public void display() {
        System.out.println("接口AA的display方法");
    }

    @Override
    public void show() {
        System.out.println("接口BB的show方法");
    }
}

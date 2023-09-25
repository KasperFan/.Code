package com.boda.xy;

public class DD implements CC {
    @Override
    public void display() {         // 实现接口AA中的display方法
        System.out.println("接口AA的display方法");
    }

    @Override
    public void show() {            // 实现BB接口中的show方法
        System.out.println("接口BB的show方法");
    }

    // 测试DD类的使用
    public static void main(String[] args) {
        DD dd = new DD();
        System.out.println(DD.STATUS);  // 从AA接口继承来的常量
        dd.show();
        dd.print();                     // 调用继承来的默认方法
        AA aa = new DD();
        aa.display();
    }
}

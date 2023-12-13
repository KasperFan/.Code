package com.boda.xy;

public class Counter {
    public int x;                   // 实例变量
    public static int y = 0;        // 静态变量/类变量，被所有实例对象共享

    public Counter() {
        x = 100;
    }

    public static void main(String[] args) {
//        对于静态变量通常使用类名访问
        Counter.y=100;
        Counter.y=200;
        System.out.println(Counter.y);  // 输出200
//        通过实例访问静态变量可能产生混乱的代码
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        c1.y = 100;
        c2.y = 200;
        System.out.println(c1.y);       // 输出结果为200
    }
}

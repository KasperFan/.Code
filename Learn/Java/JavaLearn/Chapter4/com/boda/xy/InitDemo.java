package com.boda.xy;

/**
 * 赋值优先级:
 * <p>声明赋值 > 初始化块赋值 > 构造方法赋值
 */
public class InitDemo {
    int x = 100;

    {
        x = 60;
        System.out.println("初始化块中x = " + x);
    }

    public InitDemo() {
        x = 58;
        System.out.println("构造方法中x = " + x);
    }

    public static void main(String[] args) {
        InitDemo d = new InitDemo();
        System.out.println("对象创建后x = " + d.x);
    }
}

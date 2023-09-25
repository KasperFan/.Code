package com.boda.xy;

public class StaticDemo {
    static int x = 100;
    /**
     * 静态初始化块，只能访问静态成员
     * */
    static {
        x = 48;
    }

    public StaticDemo() {
        x = 88;
    }
    // 其他代码
}

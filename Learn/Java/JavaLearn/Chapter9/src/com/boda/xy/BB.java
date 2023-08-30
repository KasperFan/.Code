package com.boda.xy;

public interface BB {
    void show();                // 一个抽象方法
    default void print(){       // 一个默认方法
        System.out.println("接口BB的默认方法");
    }
}

package com.boda.xy;

public class Student {
    int id;
    String name;
    int age;

/**
 * <p>可以在成员变量声明的同时为变量初始化，如下所示</p>
 * */
/*
    int id = 1001;
    String name = "李明";
    int age = 20;
*/

/**
 * 在类体中用一对花括号定义一个 初始化块(initialization block)，在该块中可以实现对实例变量初始化。
 * */
/*
    int id;
    String name;
    int age;
    {
        id = 1001;
        name = "李明";
        age = 20;
    }
*/

    /**
     * 可以使用在构造方法中对变量初始化。例如，对于Student类可以定义下面的构造方法。
     */
    public Student(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    /**
     * 该类未定义构造方法
     */

    public void display() {
        System.out.println("is + " + id);
        System.out.println("name = " + name);
        System.out.println("age = " + age);
    }
}

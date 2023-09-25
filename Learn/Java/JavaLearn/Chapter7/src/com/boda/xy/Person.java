package com.boda.xy;

public class Person {
    public String name;
    public int age;

    /**
     * 无参数构造方法
     * */
    public Person() {
    }

    /**
     * 带2个参数构造方法
     * */
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void sayHello(){
        System.out.println("My name is " + name);
    }
}

package com.boda.practice;

public class Person {
    String name;
    int age;

    public Person() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void speak(){
        System.out.println("My name is " + name + ",And my age is " + age);
    }
    public void show() {
        System.out.println(age);
    }

    public void main(String[] args) {
        int num = 88;
        Person p = new Person();
        p.show();
    }
}

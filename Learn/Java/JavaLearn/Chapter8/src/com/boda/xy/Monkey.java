package com.boda.xy;

import java.util.Objects;

public class Monkey implements Cloneable {
    private String name;    // 名字
    private int age;        // 年龄

    public Monkey(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (!(obj instanceof Monkey))
            return false;

        Monkey mon = (Monkey) obj;
        return getAge() == mon.getAge() && Objects.equals(getName(), mon.getName());
    }

    public String toString() {
        return "猴子:name = " + name + " age =" + age;
    }

    public static void main(String[] args) throws CloneNotSupportedException {
        Monkey mon = new Monkey("金丝猴", 2);
        Monkey mon2 = (Monkey) mon.clone();
        System.out.println(mon == mon2);
        System.out.println(mon.equals(mon2));
        System.out.println(mon.getClass().getName());
        System.out.println(mon.hashCode());
        System.out.println(mon);
    }
}

package com.boda.xy;

public class classEmployee {
    String name;
    int age;
    double salary;

    public classEmployee() {
    }

    public classEmployee(String name, int age, double salary) {
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void sayHello() {
        System.out.println("My name is " + name);
    }

    public double computeSalary(int hours, double rate) {
        double totalSalary;
        totalSalary = salary + hours * rate;
        return totalSalary;
    }
}

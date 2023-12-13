package com.boda.xy;

public class PassByValue {
    public static void change(int num) {
        num *= 2;
        System.out.println(num);
    }

    public static void change(classEmployee emp) {
        emp.setSalary(8000);
        System.out.println(emp.getSalary());
    }

    public static void main(String[] args) {
        int number = 100;
        change(number);
        System.out.println(number);
        classEmployee employee = new classEmployee();
        employee.setSalary(5000);
        change(employee);
        System.out.println(employee.getSalary());
    }
}

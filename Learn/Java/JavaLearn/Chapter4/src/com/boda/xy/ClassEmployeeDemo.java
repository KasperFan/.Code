package com.boda.xy;

public class ClassEmployeeDemo {
    public static void main(String[] args) {
//        Employee employee = new Employee("李明",28,5000.00);
        classEmployee employee = new classEmployee();
        employee.name = "李明";// 同一包下可访问其成员变量，否则应使用public修饰
        employee.sayHello();
    }
}

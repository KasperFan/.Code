package com.boda.xy;

import java.util.Objects;

public class Employee extends Person {
    public int id;
    public double salary;

    /**
     * 无参数构造方法
     */
    public Employee() {
    }

    /**
     * 带1个参数构造方法
     */
    public Employee(double salary) {
        this.salary = salary;
    }

    /**
     * 带3个参数构造方法
     */
    public Employee(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    /**
     * 带2个参数构造方法
     *
     * @param name
     * @param age
     */
    public Employee(String name, int age, int id, double salary) {
        super(name, age);
        this.id = id;
        this.salary = salary;
    }


    public static void main(String[] args) {
        var emp = new Employee("刘明", 30, 5000);
        System.out.println("姓名 = " + emp.name);
        System.out.println("年龄 = " + emp.age);
        emp.sayHello();
        System.out.println(emp.computeSalary(10, 50.0));
    }

    /**
     * 计算并返回员工总工资
     */
    public double computeSalary(int hours, double rate) {
        double totalSalary = this.salary + hours * rate;
        return totalSalary;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Employee employee = (Employee) o;
        return id == employee.id && Double.compare(employee.salary, salary) == 0 && name.equals(employee.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, salary);
    }
}

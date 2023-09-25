package com.boda.xy;

public class SomeClass {
    int x = 5;
    /**
     * 静态方法和静态变量可以直接通过类名调用，相当于全局变量或全局方法
     * */
    static int y = 48;
    /**
     * 此处的display()方法是静态的，它可以访问类的静态成员y，但不能访问x，因为x是实例变量，所以程序中的后两行会导致编译器错误;
     * <p>因为x是非静态的，所以它必须通过实例访问。
     * */
    public static void display(){
        y+=100;
        System.out.println("y = " + y);
        /**
         * 无法从 static 上下文引用非 static 字段 'x'
         */
//        x *= 5;
//        System.out.println("x = " + x);
    }

    /**
     * 作为应用程序执行入口点的main()方法必须用static修饰，也是因为Java运行时系统(RuntimeSystem)在开始执行程序前，并没有生成类的一个实例，因此只能通过类名来调用main()方法开始执行程序。
     * */
    public static void main(String[] args) {
    /**
     * 通常使用类名访问静态方法，例如
     * */
    SomeClass.display();
//    SomeClass.main();


    }
}

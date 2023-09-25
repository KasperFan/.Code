package com.boda.xy;

/**
 * 与类的其他成员类似，静态内部类使用static修饰，静态内部类也称<strong>嵌套类</strong>(nested class),静态内部类与成员内部类的行为不同，下面是它们的不同之处:<br>
 * · 静态内部类中可以定义静态成员，而成员内部类不能。<br>
 * · 静态内部类只能访问外层类的静态成员。成员内部类可以访问外层类的实例成员和静态成员。<br>
 * · 创建静态内部类的实例不需要先创建一个外层类的实例。相反，创建成员内部类实例，必须先创建一个外层类的实例。<br>
 * */
public class Outer2 {
    private static int x = 100;
    private static class Inner2{
        private String y = "hello";
        public void innerMethod(){
            System.out.println("x = " + x);
            System.out.println("y = " + y);
        }
    }

    public static void main(String[] args) {
        Outer2.Inner2 snc = new Outer2.Inner2();
    }
}

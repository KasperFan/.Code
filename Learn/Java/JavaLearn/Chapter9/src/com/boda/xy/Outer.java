package com.boda.xy;

/**
 * Java 语言允许在一个类(或接口）的内部定义另一个类(接口、枚羊、记录或注解等)，这种类称为<strong>内部类</strong>(inner class)。使用内部类可以带來如下好处：对只在一处使用的类进行分组，提高封装性；增强代码的可读性和可维护性。<br>
 * 有多种类型的内部类。大致可分为<strong>成员内部类、静态内部类、匿名内部类和局部内部类</strong>。<br>
 * 下面分别讨论这几种内部类的定义和使用。
 * */
public class Outer {
    private int x = 200;

    /**
     * 成员内部类是没有用static 修饰且定义在外层类的类体中。下面程序在 Outer 类中定义了一个成员内部类 Inner。
     * */
    public class Inner {
        int y = 300;

        public int calculate() {
            return x + y;
        }
    }

    public void makeInner(){
        Inner ic = new Inner();                     //  创建内部类对象
        System.out.println(ic.calculate());
    }

    public static void main(String[] args) {
        Outer outer = new Outer();
        var inner = outer.new Inner();
        System.out.println(inner.calculate());      //  输出：500
    }
}

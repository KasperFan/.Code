package com.boda.xy;

/**
 * 在Java类的设计中，有时希望一个类在任何时候只能有一个实例。
 * <p>这时可以将该类设计为<strong>单例模式(singleton)</strong>。</p>
 * <p>要将一个类设计为单例模式，类的构造方法的访问修饰符应声明为private，然后在类中定义一个static方法，在该方法中创建类的对象</p>
 */
public final class Sun {
    private static final Sun INSTANCE = new Sun();
    private int a = 0;

    /**
     * 世界上只有一个太阳（Sun）
     */
    public Sun() {
    }

    /**
     * Java中，synchronized关键字是用来控制线程同步的，就是在多线程的环境下，控制synchronized代码段不被多个线程同时执行。synchronized可以保证方法或者代码块在运行时，同一时刻只有一个方法可以进入到临界区，同时它还可以保证共享变量的内存可见性。
     * <p>synchronized可以作为函数的修饰符（也就是常说的同步方法），也可以作为函数内的语句（也就是常说的同步代码块）。synchronized修饰的对象有以下几种：
     * <p>修饰一个代码块，被修饰的代码块称为同步语句块，其作用的范围是大括号 {}括起来的代码，作用的对象是调用这个代码块的对象；
     * <p>修饰一个方法，被修饰的方法称为同步方法，其作用的范围是整个方法，作用的对象是调用这个方法的对象；
     * <p>修改一个静态的方法，其作用的范围是整个静态方法，作用的对象是这个类的所有对象；
     * <p>修改一个类，其作用的范围是synchronized后面括号括起来的部分，作用主的对象是这个类的所有对象。
     * <p><p>synchronized在使用时要注意以下几点：
     * <p>synchronized关键字不能继承。如果在父类中的某个方法使用了synchronized关键字，而在子类中覆盖了这个方法，在子类中的这个方法默认情况下并不是同步的，而必须显式地在子类的这个方法中加上synchronized关键字才可以。
     * <p>synchronized锁定的是对象，每个对象只有一个锁（lock）与之相关联。如果一个对象有多个synchronized方法，只要一个线程访问了其中的一个synchronized方法，其它线程就不能同时访问这个对象中任何一个synchronized方法。
     * <p>synchronized可以防止多个线程同时访问这个对象或者类所创建的对象中的synchronized方法或者代码块。但是当一个线程访问对象或者类中的一个synchronized (this)同步代码块时，另一个线程仍然可以访问该对象或者类中的非synchronized (this)同步代码块。
     */
    public static synchronized Sun getInstance() {
        return INSTANCE;
    }

    public void methodA() {
        a++;
        System.out.println("a = " + a);
    }

/**
 * 程序中将构造方法定义为private，外部不能直接使用构造方法创建Sun的实例，而必须通过getInstance()方法或INSTANCE常量返回唯一的实例。
 */
    public static void main(String[] args) {
        Sun sun1 = Sun.getInstance();
        Sun sun2 = Sun.getInstance();
        sun1.methodA();
        sun2.methodA();
        System.out.println(sun1 == sun2);
    }
}

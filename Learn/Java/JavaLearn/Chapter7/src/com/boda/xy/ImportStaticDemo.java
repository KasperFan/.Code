package com.boda.xy;

import static java.lang.Math.*;
import static java.lang.System.*;

/**
 * 使用一个类的静态常量或静态方法，需要在常量名前或方法名前加上类名，如Math.PI、Math.random()等。
 * <p>如果使用的常量或方法较多，代码就显得冗长。因此在Java5中，允许使用import static语句导入类中的常量和静态方法，再使用这些类中的常量或方法就不用加类名前缀了</p>
 * <p>例如，要使用Math类的random()等方法，则可以先使用静态导入语句：<br><blockquote><pre>{@code import static java.lang.Math.*;}</pre></blockquote></p>
 * */
public class ImportStaticDemo {
    public static void main(String[] args) {
        var d = random();
        var pi = PI;
        out.println("d = " + d);
        out.println("pi = " + pi);
    }
}

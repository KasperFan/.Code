package com.boda.xy;

public class VarargsDemo {
    /**
     * <p>Java语言<strong>允许定义方法（包括构造方法）带数量可变的参数</strong>,这种方法称为<strong>可变参数</strong>(variable argument)方法。具体做法是在方法参数列表的最后一个参数的类型名之后、参数名之前使用省略号（...）表示</p>
     */
    public static double average(double... values) {
        var sum = 0.0;
        for (var value :
                values) {
            sum += value;                                   // 求数组元素之和
        }
        double average = sum / values.length;
        return average;
    }

    /**
     * <p>在可变参数的方法中还可以有一般的参数，但是可变参数必须是方法的最后一个参数，例如，下面定义的方法也是合法的</p>
     */
    public static double average(String name, double... values) {
        var sum = 0.0;
        for (var value :
                values) {
            sum += value;                                   // 求数组元素之和
        }
        double average = sum / values.length;
        return average;
    }

    public static void main(String... args) {
        System.out.println(average(60, 70, 86));    // 输出：72.0
    }
}

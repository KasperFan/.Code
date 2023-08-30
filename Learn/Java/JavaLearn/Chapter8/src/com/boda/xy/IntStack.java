package com.boda.xy;

public class IntStack {
    private Integer[] elements;
    private int size = 0;
    public static final int DEFAULT_CAPACITY = 10;

    public IntStack() {
        this(DEFAULT_CAPACITY);
    }

    public IntStack(int capacity) {
        elements = new Integer[capacity];
    }

    public void push(Integer value) {
        if (size >= elements.length) {
            // 创建一个长度是原数组长度2倍的数组
            Integer[] temp = new Integer[elements.length * 2];
            // 将原来数组元素复制到新数组中
            System.arraycopy(elements, 0, temp, 0, elements.length);
            elements = temp;
        }
        elements[size++] = value;
    }

    /**
     * assert是一个Java关键字，它用于在代码中插入断言，也就是一些预期的条件或结果。如果断言的表达式为真，那么程序会继续执行；如果断言的表达式为假，那么程序会抛出一个AssertionError异常，并停止运行。这样可以帮助开发者在开发和测试阶段检查程序的正确性和逻辑错误，提高代码的质量和可靠性。
     *
     * 例如，假设我们有一个计算两个数的最大公约数的方法gcd(int a, int b)，我们可以使用assert来检查方法的入参和返回值是否符合我们的预期，如下所示：<blockquote><pre>{@code public static int gcd(int a, int b) {
     *   // 断言入参都是正数
     *   assert a > 0 && b > 0 : "a and b must be positive";
     *   // 使用辗转相除法计算最大公约数
     *   while (a != b) {
     *     if (a > b) {
     *       a = a - b;
     *     } else {
     *       b = b - a;
     *     }
     *   }
     *   // 返回最大公约数
     *   return a;
     * }
     *
     * public static void main(String[] args) {
     *   // 测试gcd方法
     *   int x = 15;
     *   int y = 20;
     *   int z = gcd(x, y);
     *   // 断言返回值是5
     *   assert z == 5 : "gcd of " + x + " and " + y + " should be 5";
     *   // 打印结果
     *   System.out.println("gcd of " + x + " and " + y + " is " + z);
     * }}</pre></blockquote>
     *
     * 如果我们运行这段代码，我们会看到输出：<blockquote><pre>{@code gcd of 15 and 20 is 5}</pre></blockquote>
     *
     * 这说明程序运行正常，没有触发任何断言异常。但是如果我们把x或y改成负数，或者把z的期望值改成其他数字，那么程序就会抛出AssertionError异常，并显示我们定义的错误信息，如下所示：<blockquote><pre>{@code Exception in thread "main" java.lang.AssertionError: a and b must be positive
     * 	at Gcd.gcd(Gcd.java:4)
     * 	at Gcd.main(Gcd.java:18)}</pre></blockquote>
     *
     * 或者<blockquote><pre>{@code Exception in thread "main" java.lang.AssertionError: gcd of 15 and 20 should be 6
     * 	at Gcd.main(Gcd.java:23)}</pre></blockquote>
     * 这样我们就可以快速定位问题的原因，并进行修改和调试。
     * <br>
     * 需要注意的是，assert语句默认是关闭的，也就是说在正常运行时不会执行断言检查。要启用断言检查，我们需要在运行时加上-ea或-enableassertions参数，例如：<blockquote><pre>{@code java -ea Gcd}</pre></blockquote>
     *
     * 或者
     * <blockquote><pre>{@code java -enableassertions Gcd}</pre></blockquote>
     * 这样才能让断言语句生效。另外，断言语句只适用于开发和测试阶段，不应该用于生产环境中，因为它可能会影响程序的性能和安全性。如果你想在生产环境中对方法入参进行合法性检查，你可以使用其他方式，比如抛出IllegalArgumentException或NullPointerException等异常。
     * */

    public Integer pop() {          // 出栈方法
        assert !empty() : "栈已空.";
        return elements[--size];
    }

    public Integer peek() {         // 返回栈顶元素方法
        assert !empty() : "栈已空.";
        return elements[size - 1];
    }

    public boolean empty() {        // 判断栈空方法
        return size == 0;
    }

    public int size() {
        return size;
    }
}

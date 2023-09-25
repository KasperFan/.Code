package com.boda.xy;

public class HelloProgram {
    /**
     * Java应用程序从main()方法开始执行。main()方法的声明格式如下：
     * <p>public static void main(String[] args) {}</p>
     * <p>其中，参数args称为<strong>命令行参数</strong>，它是一个String数组，该参数是在程序运行时通过命令行传递给main()方法。</p>
     * */
    public static void main(String[] args) {
        System.out.println(args[0] + " " + args[1] + " " + args[2]);
    }
}

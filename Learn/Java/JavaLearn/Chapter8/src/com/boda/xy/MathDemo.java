package com.boda.xy;

import static java.lang.Math.*;
import static java.lang.System.*;

public class MathDemo {
    public static void main(String[] args) {
        out.println("sqrt(2) = " + sqrt(2));
        out.println("pow(2,5) = " + pow(2, 5));
        out.println("rint(2.5) = " + rint(2.5));
        out.println("rint(-3.5) = " + rint(-3.5));
        out.println("round(3.5) = " + round(3.5));
        out.println("round(-3.5) = " + round(-3.5));
        double pi = PI;
        pi = round(pi * 10000) / 10000.0; // 四舍五入到小数点后4位
        out.println("PI = " + pi);
    }
}

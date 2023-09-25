package com.boda.xy;

public class ArrayCopyDemo {
    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4};
        int[] b = {8, 7, 6, 5, 4, 3, 2, 1};
        int[] c = {10, 20};
        try {
            System.arraycopy(a, 0, b, 0, a.length);
//          下面的语句发生异常，目标数组容纳不下数组a的元素
            System.arraycopy(a, 0, c, 0, a.length);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println(e);
        }
        for (var elem :
                b) {
            System.out.print(elem + " ");
        }
        System.out.println();
        for (var elem :
                c) {
            System.out.print(elem + " ");
        }
        System.out.println("\n");
    }
}

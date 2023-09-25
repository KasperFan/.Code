package com.boda.xy;

public class ArrayDemo {
    public static void main(String[] args) {
        var marks = new double[]
        {
            79, 84.5, 63, 90, 98,
        };
        /*marks[0] = 79;
        marks[1] = 84.5;
        marks[2] = 63;
        marks[3] = 90;
        marks[4] = 98;*/
        System.out.println(marks[2]);
        System.out.println(marks.length);
        /* 用for循环访问数组元素 */
        for (int i = 0; i < marks.length; i++) {
            System.out.println(marks[i]);
        }
        /* 增强for循环(for-each)直接遍历数组元素 */
        for (double i : marks){
            System.out.println(i);
        }
    }
}

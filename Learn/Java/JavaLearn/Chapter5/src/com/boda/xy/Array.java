package com.boda.xy;

public class Array {
    /**
     * 数组声明的两种等价形式
     * <p>数组声明不能指定数组元素的个数，仅声明一个数组对象的引用</p>
     */
    int[] arrayName1;
    int arrayName2[];

    /**
     * 数组的创建，即为数组的每个元素分配存储空间
     * <p>数组的创建使用new语句，其一般格式如下：</p>
     * */
//    arrayName1 =new int[5];

    /**
     * 数组的创建与声明可以写在一条语句中，如下
     */
    int[] ArrayName = new int[5];

    /* 数组参数与返回值 */

    /**
     * 数组对象可以作为参数传递给方法
     */
    public static double sumArray(double[] array) {
        var sum = 0.0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        return sum;
    }

    /**
     * 一个方法也可以返回一个数组对象
     */
    public static int[] reverse(int[] list) {
        var result = new int[list.length];  // 创建一个与参数数组大小相同的数组
        for (int i = 0, j = result.length - 1; i < list.length; i++, j--) {
            result[j] = list[i];            // 实现数组反转
        }
        return result;                      // 返回数组
    }


}

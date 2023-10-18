package com.boda.xy;

public class BubbleSort {
    static int cnt = 0;
    /**
     * 除冒泡排序以外，还可以使用快速排序：
     * <quoteblock><pre>{@code
     *     public static void quickSort(int[] a) {
     *         quickSort(a, 0, a.length - 1);
     *     }
     *
     *     public static void quickSort(int[] a, int leftBound, int rightBound) {
     *         if (leftBound >= rightBound) return;
     *         else {
     *             int l = leftBound - 1, r = rightBound + 1, mid = a[(l + r) / 2];
     *             while (l <= r) {
     *                 while (a[l] < mid && l < rightBound) l++;
     *                 while (a[r] > mid && r >= leftBound) r--;
     *                 if (l < r) {
     *                     a[l] ^= a[r];
     *                     a[r] = a[l] ^ a[r];
     *                     a[l] = a[l] ^ a[r];
     *                 }
     *             }
     *             System.out.print("第 " + (cnt++ + 1) + "趟结果：");
     *             for (var n :
     *                     a) {
     *                 System.out.print(" " + n);
     *             }
     *             System.out.println();
     *             quickSort(a, leftBound, l);
     *             quickSort(a, l + 1, rightBound);
     *         }
     *     }
     * }</pre></quoteblock>
     * */
    public static void bubbleSort(int[] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    a[j] ^= a[j + 1];
                    a[j + 1] = a[j] ^ a[j + 1];
                    a[j] = a[j] ^ a[j + 1];
                }
            }
            System.out.print("第 " + (cnt++ + 1) + " 趟结果：");
            for (var n :
                    a) {
                System.out.print(" " + n);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] nums = {75, 53, 32, 12, 46, 199, 17, 54};
        System.out.print("初始元素：");
        for (var n :
                nums) {
            System.out.print(" " + n);
        }
        System.out.println();
        bubbleSort(nums);             // 调用bubbleSort()方法对num排序
    }
}

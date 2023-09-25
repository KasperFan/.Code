package com.boda.practice;

import com.boda.xy.Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static double[] a = {75, 53, 32, 12, 46, 199, 17, 54};
    static int[] a2 = {75, 53, 32, 12, 46, 199, 17, 54};

    static int[] sum1 = {1, 2, 4}, sum2 = {2, 4, 6, 8};

    public static double total(double[] array) {
        double total = 0;
        for (var elem : array) {
            total += elem;
        }
        return total;
    }

    public static double max(double[] array) {
        double max = 0;
        for (var elem : array) {
            max = Math.max(max, elem);
        }
        return max;
    }

    public static double min(double[] array) {
        double min = Double.POSITIVE_INFINITY;
        for (var elem : array) {
            min = Math.min(min, elem);
        }
        return min;
    }

    public static double average(double[] array) {
        double temp = 0;
        for (var elem : array) {
            temp += elem;
        }
        return temp / array.length;
    }

    public static void printFibonacci() {
        int[] fibonacci = new int[20];
        fibonacci[0] = fibonacci[1] = 1;
        for (int i = 2; i < fibonacci.length; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        for (var elem :
                fibonacci) {
            System.out.println(elem);
        }
    }

    public static void reversePrintArray(int[] array) {
        StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
        int[] reverse = Array.reverse(array);
        for (int i = 0; i < array.length; i++) {
            sb1.append(array[i]).append(" ");
            sb2.append(reverse[i]).append(" ");
        }
        System.out.println(sb1);
        System.out.println(sb2);
    }

    public static void selectSort(int[] array) {
        int minIndex;
        for (int i = 0; i < array.length - 1; i++) {
            minIndex = i;
            for (int j = i; j < array.length; j++) {
                if (array[minIndex] > array[j]) minIndex = j;
            }
            if (minIndex != i) {
                int temp = array[minIndex];
                array[minIndex] = array[i];
                array[i] = temp;
            }
        }
    }

    public static int[] sumArray(int[] a, int[] b) {
        int maxLen = Math.max(a.length, b.length), minLen = Math.min(a.length, b.length);
        int[] result = new int[maxLen];
        for (int i = 0; i < minLen; i++) {
            result[i] = a[i] + b[i];
        }
        for (int i = minLen; i < maxLen; i++) {
            result[i] = a.length < b.length ? b[i] : a[i];
        }
        return result;
    }

    public static int[] arrayMerge(int[] a, int[] b) {
        int[] result = new int[Math.max(a.length, b.length)];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        Arrays.sort(result);
        return result;
    }

    public static int solveQuadratic(double[] egn, double[] roots) {
        double discriminant = Math.pow(egn[1], 2) - 4 * egn[0] * egn[2];
        if (discriminant < 0) return 0;
        else if (discriminant == 0) {
            roots = new double[1];
            roots[0] = -egn[1] / 2 * egn[0];
            return 1;
        } else {
            roots = new double[2];
            for (int i = 0; i < 2; i++) {
                roots[i] = (-egn[1] + Math.pow(-1, i) * Math.sqrt(discriminant)) / 2 * egn[0];
            }
            return 2;
        }
    }

    public static void getPrimes() {
        boolean isPrime;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : new int[]{2, 3, 5, 7}) {
            list.add(i);
        }
//        loop:
        for (int i = 2; i <= 100; i++) {
            isPrime = true;
            if (list.contains(i)) continue;
            for (int chk : list) {
                if (i % chk == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) list.add(i);
        }
        for (int num :
                list) {
            System.out.println(num);
        }
    }

    public static boolean equals(int[] list1, int[] list2) {
        if (list1.length == list2.length) {
            for (int i = 0; i < list1.length; i++) {
                if (list1[i] != list2[i]) return false;
            }
            return true;
        } else return false;
    }

    public static int answerJosephus() {
        int[] list = new int[12];
        int head = 0, tail = 11, start = 0;
        for (int i = 0; i < 12; i++) {
            list[i] = i + 1;
        }
        while (head != tail) {
            start += 4;
            start %= (tail + 1);
            for (int i = start; i < tail; i++) {
                list[i] = list[i + 1];
            }
            tail--;
        }
        return list[0];
    }

    public static int[][] sumMatrix(int[][] matrix1, int[][] matrix2) {
        int[][] result = new int[matrix1.length][matrix1[0].length];
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return result;
    }

    public static int[][] subMatrix(int[][] matrix1, int[][] matrix2) {
        int[][] result = new int[matrix1.length][matrix1[0].length];
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        return result;
    }

    public static int[][] transposeMatrix(int[][] matrix) {
        int[][] result = new int[matrix[0].length][matrix.length];
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                result[i][j] = matrix[j][i];
            }
        }
        return result;
    }

    public static int[] locateLargest(double[][] a) {
        int[] location = new int[2];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (a[location[0]][location[1]] < a[i][j]) {
                    location[0] = i;
                    location[1] = j;
                }
            }
        }
        return location;
    }

    public static void turnMatrix() {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入矩阵的阶数：");
        int n = sc.nextInt(), cnt = 1;
        int[][] ints = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ints[i][j] = cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >=0; j--) {
                System.out.print(ints[j][i]+"\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        printFibonacci();
        reversePrintArray(a2);
        selectSort(a2);
        for (var elem :
                a2) {
            System.out.println(elem);
        }
        for (var elem :
                sumArray(sum1, sum2)) {
            System.out.println(elem);
        }
        System.out.println(answerJosephus());
        getPrimes();
        turnMatrix();
    }

}
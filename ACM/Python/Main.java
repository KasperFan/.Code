/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-10-12 23:05:52
 * @LastEditTime: 2023-10-12 23:09:32
 * @FilePath: /Python/Main.java
 * @describes: This file is created for learning Python to deal OJ problems.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
import java.util.Scanner;
import static java.lang.Math.*;

public class Main {

    public static boolean zhiShu(int m) {
        int sk = (int) sqrt(m);
        for (int i = 2; i <= sk; i++)
            if (m % i == 0)
                return false;
        return true;
    }

    public static void qiuHe(int k) {
        for (int i = k / 2; i >= 1; i--)
            if (zhiShu(i) && zhiShu(k - i)) {
                System.out.println(i * (k - i));
                return;
            }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        qiuHe(S);
    }
}

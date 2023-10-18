/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-09-28 14:18:32
 * @LastEditTime: 2023-09-28 14:20:58
 * @FilePath: /Python/九九乘法表.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
public class 九九乘法表 {
    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < 9 - i; j++) {
                System.out.print("\t");
            }
            for (int j = i; j > 0; j--) {
                System.out.print(j + "*" + i + "=" + i * j + "\t");
            }
            System.out.println();
        }
    }
}
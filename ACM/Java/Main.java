/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2024-04-11 19:44:56
 * @LastEditTime: 2024-04-12 16:25:59
 * @FilePath: /Java/Main.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2024 by KasperFan in WFU, All Rights Reserved. 
 */

import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Integer a = 3;
        BigInteger b = new BigInteger("3");
        System.out.println(b.xor(BigInteger.valueOf(a)));
    }
}

/*
 * @Author: KasperFan && fanwlx@foxmail.com
 * @Date: 2023-05-22 14:48:53
 * @LastEditTime: 2023-05-22 19:41:06
 * @FilePath: /蓝桥杯省赛/阶乘之和.java
 * @describes: This file is created for learning Code.
 * Copyright (c) 2023 by KasperFan in WFU, All Rights Reserved. 
 */
import java.math.BigInteger;

public class 阶乘之和 {

    static BigInteger end = new BigInteger("202320232023"), ans = new BigInteger("0");
    
    public static void main(String[] args) {
        BigInteger temp = new BigInteger("1");
        for (BigInteger i = BigInteger.ONE; i.toString() != end.toString(); i=i.add(BigInteger.ONE)) {
            temp = temp.multiply(i);
            ans = ans.add(temp);
            System.out.println(ans.toString().substring(Math.max(0, ans.toString().length() - 9)));
        }
    }
}
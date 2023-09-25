package com.boda.xy;

public class ForDemo {
    public static void main(String[] args) {
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j <= i; j++) {
//                System.err.print(j + "*" + i + "=" + j * i + "\t");
                System.err.print(new StringBuilder().append(j).append("*").append(i).append("=").append(j*i).append("\t").toString());
            }
            System.err.println();
        }
    }
}

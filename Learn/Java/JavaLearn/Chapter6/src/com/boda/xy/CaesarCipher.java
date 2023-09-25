package com.boda.xy;

import java.util.Scanner;

public class CaesarCipher {
    public static void Encryption() {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入一个字符串:");
        String str = sc.nextLine();
        System.out.println("原字符串是：" + str);
        StringBuilder ss = new StringBuilder(str);

        for (int i = 0; i < ss.length(); i++) {
            char c = ss.charAt(i);
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                if (c <= 'Z')
                    c = (char) ((c + 5) > 'Z' ? 'A' + (c + 4) % 'Z' : c + 5);
                else c = (char) ((c + 5) > 'z' ? 'a' + (c + 4) % 'z' : c + 5);
            }
            ss.setCharAt(i, c);
        }
        System.out.println("加密后的字符串为：" + ss);
    }

    public static void Decryption() {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入加密字符串:");
        String str = sc.nextLine();
        System.out.println("加密字符串是：" + str);
        StringBuilder ss = new StringBuilder(str);

        for (int i = 0; i < ss.length(); i++) {
            char c = ss.charAt(i);
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
                if (c <= 'Z')
                    c = (char) ((c - 5) < 'A' ? 'Z' + (c - 4) - 'A' : c - 5);
                else c = (char) ((c - 5) < 'a' ? 'z' + (c - 4) - 'a' : c - 5);
            }
            ss.setCharAt(i, c);
        }
        System.out.println("解密后的字符串为：" + ss);
    }

    public static void main(String[] args) {
        Encryption();
        Decryption();
    }
}

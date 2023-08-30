package com.boda.xy;

import java.io.IOException;

public class InputDemo {
    public String getUserInput() {
        var sb = new StringBuilder();
        try {
            char c = (char) System.in.read(); // 从键盘读取一个字符
            while (c != '\r' && c != '\n') {
                sb.append(c);                 /* 这里的try-catch结构用于捕获和处理异常。在第10章有讲到 */
                c = (char) System.in.read();
            }
        } catch (IOException e) {
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        var demo = new InputDemo();
        String input = demo.getUserInput();
        System.out.println(input);
    }
}

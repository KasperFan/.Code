package com.boda.practice;

import java.io.IOException;

public class SystemInput {
    public static void main(String[] args) throws IOException {
        for (var i :
                System.in.readNBytes(100)) {
            System.out.println(i);
        }

    }
}

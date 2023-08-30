package com.boda.xy;

import java.util.Scanner;

public class TryWithResources {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println(sc.nextInt());
        }catch (Throwable ignored) {}
    }
}

package com.boda.xy;

import java.time.LocalTime;
import java.time.temporal.ChronoUnit;

public class CurrentTime {
//  输出当前时间（格林尼治时间）
    public static void main(String[] args) {
        long t = System.currentTimeMillis();
        long seconds = t / 1000;
        long s = seconds % 60;
        long minutes = seconds / 60;
        long m = minutes % 60;
        long hours = minutes / 60;
        long h = hours % 24;
        System.out.println("当前时间：" + h + ":" + m + ":" + s);
//      输出当前本地时间（LocalTime类）
        System.out.println("当前时间：" + LocalTime.now().truncatedTo(ChronoUnit.SECONDS));
    }
}


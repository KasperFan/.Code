package com.boda.xy;

import java.time.DayOfWeek;

public class StringSwitchDemo {
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        System.out.print("请输入英文季节名称:");
//        String season = input.next();
//        switch (season.toLowerCase()) {
//            case "spring" -> System.out.println("春天");
//            case "summer" -> System.out.println("夏天");
//            case "autumn" -> System.out.println("秋天");
//            case "winter" -> System.out.println("冬天");
//            default -> System.out.println("输入名称错误!");
//        }
//    }

    public static void main(String[] args) {
        DayOfWeek day = DayOfWeek.SATURDAY;
        int numLetters = switch (day) {
            case MONDAY, FRIDAY, SUNDAY -> 6;
            case TUESDAY -> 7;
            case THURSDAY, SATURDAY -> 8;
            case WEDNESDAY -> 9;
        };
        System.out.println(numLetters);
    }
}

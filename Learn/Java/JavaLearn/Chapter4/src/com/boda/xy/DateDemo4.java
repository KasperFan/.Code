package com.boda.xy;

import com.boda.utils.Date;

public class DateDemo4 {
    public static void main(String[] args) {
        long start = System.nanoTime();
        Date today = new Date(2021,10,5);
        System.out.println(today.toString());
        Date birthday = new Date(2002, 10, 26);
        System.out.println(birthday.getYear() + "年"
                + (birthday.isLeapYear() ? "是闰年" : "不是闰年"));
        System.out.println("你已出生" + birthday.between(today) + "天");
    }
}

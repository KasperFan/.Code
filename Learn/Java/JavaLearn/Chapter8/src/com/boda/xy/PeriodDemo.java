package com.boda.xy;

import java.time.LocalDate;
import java.time.Month;
import java.time.Period;
import java.time.temporal.ChronoUnit;

public class PeriodDemo {

    public static void main(String[] args) {
        var today = LocalDate.now();
        var birthday = LocalDate.of(2002, Month.JANUARY, 1);
        Period p = Period.between(birthday, today);
        // 计算两个日期之间相差的天数
        long p2 = ChronoUnit.DAYS.between(birthday, today);
        System.out.println("You are " + p.getYears() + " years, "
                + p.getMonths() + " months, and " + p.getDays()
                + " days old. (" + p2 + " days total)");
    }
}

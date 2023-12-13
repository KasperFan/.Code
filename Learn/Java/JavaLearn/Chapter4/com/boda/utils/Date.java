package com.boda.utils;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Date {
    private int year;
    private int month;
    private int day;

    public Date() {
        year = LocalDate.now().getYear();
        month = LocalDate.now().getMonthValue();
        day = LocalDate.now().getDayOfMonth();
    }

    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public long between(Date another) {
//        if (Math.abs(this.year - another.year) == 0) {
//            if (Math.abs(this.month - another.month) == 0)
//                return Math.abs(this.day - another.day);
//        }
        return ChronoUnit.DAYS.between(LocalDate.parse(this.toString()), LocalDate.parse(another.toString()));
    }

    public boolean isAfter(Date another) {
        return LocalDate.parse(this.toString()).isAfter(LocalDate.parse(another.toString()));
//        if (this.year == another.year) {
//            if (this.month == another.month) {
//                return this.day > another.day;
//            } else return this.month > another.month;
//        } else return this.year > another.year;
    }

    public boolean isBefore(Date another) {
        return LocalDate.parse(this.toString()).isBefore(LocalDate.parse(another.toString()));
//        if (this.year == another.year) {
//            if (this.month == another.month) {
//                return this.day < another.day;
//            } else return this.month < another.month;
//        } else return this.year < another.year;
    }

    public boolean isLeapYear() {
        return (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
//        return LocalDate.parse(this.toString()).isLeapYear();
    }

    @Override
    public String toString() {
        return String.format("%d-%02d-%02d", year, month, day);
    }
}

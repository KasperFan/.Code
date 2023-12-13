package com.boda.practice;

import java.time.LocalTime;

public class Time {
    private int hour;
    private int minute;
    private int seconds;

    public Time() {
        hour = LocalTime.now().getHour();
        minute = LocalTime.now().getMinute();
        seconds = LocalTime.now().getSecond();
    }

    public Time(int hour, int minute, int seconds) {
        if (hour < 0 || minute < 0 || seconds < 0) throw new RuntimeException("时间单位不可小于0!");
        else {
            if (!((hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) && (seconds >= 0 && seconds <= 59)))
                throw new RuntimeException("时间非法!");
        }
        this.hour = hour;
        this.minute = minute;
        this.seconds = seconds;
    }

    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public int getSeconds() {
        return seconds;
    }

    public boolean isBefore(Time time) {
        if (this.hour == time.hour) {
            if (this.minute == time.minute) {
                return this.seconds < time.seconds;
            } else return this.minute < time.minute;
        } else return this.hour < time.hour;
    }

    public boolean isAfter(Time time) {
        if (this.hour == time.hour) {
            if (this.minute == time.minute) {
                return this.seconds > time.seconds;
            } else return this.minute > time.minute;
        } else return this.hour > time.hour;
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d:%02d", hour, minute, seconds);
    }
}

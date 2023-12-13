package com.boda.practice;

public class Bus extends Vehicle {
    int passenger;

    public void gotOn(int n) {
        passenger += n;
    }

    public void gotOff(int n) {
        passenger -= n;
    }
}

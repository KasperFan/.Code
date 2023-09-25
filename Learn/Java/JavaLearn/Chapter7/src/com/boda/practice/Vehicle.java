package com.boda.practice;

public class Vehicle {
    double speed;

    public Vehicle() {
    }

    public Vehicle(double speed) {
        this.speed = speed;
    }

    public void start(int speed) {
        this.speed = speed;
    }

    public void speedUp(double deltaSpeed) {
        this.speed += deltaSpeed;
    }

    public void stop() {
        this.speed = 0;
    }
}

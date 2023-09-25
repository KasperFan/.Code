package com.boda.practice;

public class Stock {
    private String symbol;
    private String name;
    private double previousPrice;
    private double currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    public Stock(String symbol, String name, double previousPrice, double currentPrice) {
        this.symbol = symbol;
        this.name = name;
        this.previousPrice = previousPrice;
        this.currentPrice = currentPrice;
    }

    public double getChangePercent() {
        return currentPrice / previousPrice - 1;
    }

}

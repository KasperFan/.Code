package com.boda.practice;

import java.time.LocalDate;

public class Account {
    private int id;
    private double balance;
    private double annulRate;
    private LocalDate dateCreated;

    public Account() {
    }

    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getAnnulRate() {
        return annulRate;
    }

    public void setAnnulRate(double annulRate) {
        this.annulRate = annulRate;
    }

    public LocalDate getDateCreated() {
        return dateCreated;
    }

    public double getMonthlyInterestRate() {
        return annulRate / 12;
    }

    public void withdraw(double amount) {
        this.setBalance(this.getBalance() - amount);
    }

    public void deposit(double amount) {
        this.setBalance(this.getBalance() + amount);
    }
}

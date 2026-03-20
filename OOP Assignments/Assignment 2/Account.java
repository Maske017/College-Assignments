//Marin Aske
//COP3330 Object Oriented Programming
//Assignment 2: Objects
//9/15/2024

public class Account {
    private String name;
    private double balance;
    private double interestRate;

    public Account(String name, double interestRate) {
        this.name = name;
        this.interestRate = interestRate;
        this.balance = 0.0;
    }

    public boolean deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }

    public boolean withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    public double getBalance() {
        return balance;
    }

    public String getName() {
        return name;
    }

    public void calcInterest(int months) {
        if (months <= 0) {
            System.out.println("Invalid number of months.");
            return;
        }
        double interestPeriod = interestRate * (months / 12.0) / 100;
        balance *= (1 + interestPeriod);
    }
}

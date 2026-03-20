//Marin Aske
//Object Oriented Programming COP3330
//Assignment 4: File I/O and Linked Lists
//10/19/2024

import java.util.LinkedList;

public class Customer {
    private String name;
    private boolean isReturning; // true if returning, false if buying

    // Constructor
    public Customer(String name, boolean isReturning) {
        this.name = name;
        this.isReturning = isReturning;
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Getter for whether the customer is returning or buying
    public boolean getBusiness() {
        return isReturning;
    }
}

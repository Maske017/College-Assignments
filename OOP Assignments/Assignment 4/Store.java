//Marin Aske
//Object Oriented Programming COP3330
//Assignment 4: File I/O and Linked Lists
//10/19/2024

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class Store {
    // Two LinkedLists to store customers
    private static LinkedList<Customer> checkoutLine = new LinkedList<>();
    private static LinkedList<Customer> returnLine = new LinkedList<>();

    public static void main(String[] args) {
        // Create a scanner to read the filename from user
        Scanner inputScanner = new Scanner(System.in);
        System.out.print("Enter the filename: ");
        String filename = inputScanner.nextLine();

        // Read the file and load customers into checkout line
        try {
            File file = new File(filename);
            Scanner fileScanner = new Scanner(file);

            // The first line is the number of customers
            int numberOfCustomers = Integer.parseInt(fileScanner.nextLine());

            // Read each customer and add them to the checkout line
            for (int i = 0; i < numberOfCustomers; i++) {
                String name = fileScanner.next();
                boolean isReturning = fileScanner.nextBoolean();
                Customer customer = new Customer(name, isReturning);
                checkoutLine.add(customer);
            }
            fileScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            return;
        }

        // Process the lines
        while (!checkoutLine.isEmpty() || !returnLine.isEmpty()) {
            // Process two customers from the checkout line
            for (int i = 0; i < 2 && !checkoutLine.isEmpty(); i++) {
                Customer customer = checkoutLine.poll();
                if (customer.getBusiness()) {
                    System.out.println(customer.getName() + " was forwarded to the return line.");
                    returnLine.add(customer); // Move to the return line
                } else {
                    System.out.println(customer.getName() + " checked out.");
                }
            }

            // Process one customer from the return line, if any
            if (!returnLine.isEmpty()) {
                Customer returnCustomer = returnLine.poll();
                System.out.println(returnCustomer.getName() + " returned an item.");
            }
        }
    }
}

//Marin Aske
//COP3330 Object Oriented Programming
//Assignment 2: Objects
//9/15/2024

import java.util.Scanner;

public class Bank {
    private static Account[] accounts = new Account[5];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        while (true) {
            // Display the main menu
            displayMainMenu();

            // Get user input
            System.out.print("What would you like to do? ");
            choice = scanner.nextInt();

            if (choice == 6) {
                System.out.println("Goodbye.");
                break;
            }

            if (choice < 1 || choice > 5) {
                System.out.println("Invalid option. Try again.");
                continue;
            }

            int accountIndex = choice - 1;

            // If the selected account is empty, prompt to create a new account
            if (accounts[accountIndex] == null) {
                createAccount(scanner, accountIndex);
            }

            // Display account operations menu
            handleAccountOperations(scanner, accounts[accountIndex], accountIndex);
        }

        scanner.close();
    }

    private static void displayMainMenu() {
        System.out.println("Welcome to Knightro Banking:");
        for (int i = 0; i < accounts.length; i++) {
            if (accounts[i] == null) {
                System.out.println((i + 1) + ". Empty");
            } else {
                System.out.println((i + 1) + ". " + accounts[i].getName());
            }
        }
        System.out.println("6. Exit Program");
    }

    private static void createAccount(Scanner scanner, int index) {
        scanner.nextLine(); // clear the buffer
        System.out.println("Creating a new account.");
        System.out.print("What is the name of the account: ");
        String name = scanner.nextLine();
        System.out.print("What is the interest rate? ");
        double interestRate = scanner.nextDouble();
        accounts[index] = new Account(name, interestRate);
        System.out.println("Account created.");
    }

    private static void handleAccountOperations(Scanner scanner, Account account, int index) {
        int option;
        System.out.println("What would you like to do?");
        System.out.println("1. Deposit Funds");
        System.out.println("2. Withdraw Funds");
        System.out.println("3. Check Balance");
        System.out.println("4. Calculate Interest");
        System.out.println("5. Close Account");
        option = scanner.nextInt();

        switch (option) {
            case 1:
                System.out.print("How much money would you like to deposit? ");
                double depositAmount = scanner.nextDouble();
                if (account.deposit(depositAmount)) {
                    System.out.println("You have added $" + depositAmount);
                } else {
                    System.out.println("This is an invalid amount.");
                }
                break;
            case 2:
                System.out.print("How much would you like to withdraw? ");
                double withdrawAmount = scanner.nextDouble();
                if (account.withdraw(withdrawAmount)) {
                    System.out.println("You have withdrawn $" + withdrawAmount);
                } else {
                    System.out.println("This is an invalid amount.");
                }
                break;
            case 3:
                System.out.println("You have $" + account.getBalance());
                break;
            case 4:
                System.out.print("How many months have passed? ");
                int months = scanner.nextInt();
                account.calcInterest(months);
                System.out.println("Interest calculated.");
                break;
            case 5:
                accounts[index] = null;
                System.out.println("Account closed.");
                break;
            default:
                System.out.println("Invalid option. Try again.");
        }

        // Return to main menu after each account operation
    }
}

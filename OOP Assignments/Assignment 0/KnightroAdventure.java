//Marin Aske
//COP 3300 Object Oriented Programming
//9/1/2024
//Assignment 0 

import java.util.Scanner;

public class KnightroAdventure {

    public static void visitBeach(Scanner scanner) {
        System.out.print("What time did Knightro go to the beach? (24-hour format): ");
        int time = scanner.nextInt();
        
        if (time >= 9 && time <= 18) {
            System.out.println("Enjoy your drive.");
        } else {
            System.out.println("Oh no! the beach is closed.");
        }
    }

    public static void playDiscGolf(Scanner scanner) {
        int distance = 421;  // Favorite prime number between 300-500
        System.out.println("Welcome to the Park1!" + "\n" + "There is " + distance + " feet left until the basket.");
        
        while (distance != 0) {
            System.out.print("How far did you throw? ");
            int throwDistance = scanner.nextInt();
            distance = Math.abs(distance - throwDistance);
            
            if (distance == 0) {
                System.out.println("You made it in!");
            } else {
                System.out.println("You are now " + distance + " feet away from the basket.");
            }
        }
    }

    public static void visitSpeedway(Scanner scanner) {
        System.out.print("How many laps are left? ");
        int lapsLeft = scanner.nextInt();
        
        for (int i = lapsLeft; i > 0; i--) {
            System.out.println(i + " laps left.");
        }
        System.out.println("Finished!");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("\nKnightro's Activity Menu");
            System.out.println("1. Drive on the Beach");
            System.out.println("2. Play Disc Golf");
            System.out.println("3. See the Race");
            System.out.println("4. Exit");
            
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    visitBeach(scanner);
                    break;
                case 2:
                    playDiscGolf(scanner);
                    break;
                case 3:
                    visitSpeedway(scanner);
                    break;
                case 4:
                    System.out.println("Goodbye!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}
 

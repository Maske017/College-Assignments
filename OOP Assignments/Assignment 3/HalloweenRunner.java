//Marin Aske
//Assignment 3
//COP3330 Object Oriented Programming
//10/6/2024 

import java.io.*;
import java.util.*;

public class HalloweenRunner {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask for input file name
        System.out.print("Enter the input file name: ");
        String inputFileName = scanner.nextLine();

        // List to hold HalloweenCostumes objects
        List<HalloweenCostumes> costumes = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(inputFileName))) {
            int numberOfCostumes = Integer.parseInt(br.readLine().trim());

            for (int i = 0; i < numberOfCostumes; i++) {
                String[] data = br.readLine().split(" ");
                String name = data[0];
                double cost = Double.parseDouble(data[1]);
                int wantFactor = Integer.parseInt(data[2]);

                // Create appropriate HalloweenCostumes object based on input
                HalloweenCostumes costume = new HalloweenCostumes(name, cost, wantFactor);
                costume.calcCoolness();
                costumes.add(costume);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
            return;
        }

        // Sort costumes by coolness score in descending order
        Collections.sort(costumes);

        // Ask for output file name
        System.out.print("Enter the output file name: ");
        String outputFileName = scanner.nextLine();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(outputFileName))) {
            for (HalloweenCostumes costume : costumes) {
                bw.write(costume.toString());
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }
}

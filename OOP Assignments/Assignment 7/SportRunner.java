//Marin Aske
//COP3330 
//Assingment 7
//11/10/2024

import java.io.*;
import java.util.*;

public class SportRunner {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the file name of the test run: ");
        String fileName = scanner.nextLine();
        List<Sports> teams = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            int n = Integer.parseInt(br.readLine().trim()); // Number of teams
            for (int i = 0; i < n; i++) {
                String teamType = br.readLine().trim();
                if (teamType.equals("Football")) {
                    teams.add(new Football(i));
                } else if (teamType.equals("Basketball")) {
                    teams.add(new Basketball(i));
                }
            }

            int s = Integer.parseInt(br.readLine().trim()); // Number of scores
            for (int i = 0; i < s; i++) {
                String[] scoreData = br.readLine().trim().split(" ");
                int teamID = Integer.parseInt(scoreData[0]);
                String scoreType = scoreData[1];

                Sports team = teams.get(teamID);
                switch (scoreType) {
                    case "l":
                        team.score_large();
                        break;
                    case "m":
                        team.score_med();
                        break;
                    case "s":
                        team.score_small();
                        break;
                }
            }

            // Sorts teams in descending order by score using a comparator
            teams.sort((team1, team2) -> Integer.compare(team2.get_score(), team1.get_score()));
            for (Sports team : teams) {
                System.out.println(team);
            }

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}

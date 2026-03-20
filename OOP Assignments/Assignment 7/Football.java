//Marin Aske
//COP3330
//Assignment 7
//11/10/2024

public class Football implements Sports, Comparable<Sports> {
    private int score;
    private final int id;

    public Football(int id) {
        this.id = id;
        this.score = 0;
    }

    public void score_large() {
        score += 7;
    }

    public void score_med() {
        score += 3;
    }

    public void score_small() {
        score += 1;
    }

    public int get_score() {
        return score;
    }

    public int get_id() {
        return id;
    }

    @Override
    public int compareTo(Sports other) {
        return Integer.compare(other.get_score(), this.score); // Descending order
    }

    @Override
    public String toString() {
        return id + " - " + score;
    }
}

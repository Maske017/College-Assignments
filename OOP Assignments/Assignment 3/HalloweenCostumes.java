//Marin Aske
//Assignment 3
//COP3330 Object Oriented Programming
//10/6/2024

public class HalloweenCostumes implements Comparable<HalloweenCostumes> {
    private String name;
    private double cost;
    private int wantFactor;
    private int coolnessScore;

    // Default values
    private static final String DEFAULT_NAME = "Super_Awesome_Costume";
    private static final double DEFAULT_COST = 39.99;
    private static final int DEFAULT_WANT = 3;

    // Constructors
    public HalloweenCostumes() {
        this(DEFAULT_NAME, DEFAULT_COST, DEFAULT_WANT);
    }

    public HalloweenCostumes(String name) {
        this(name, DEFAULT_COST, DEFAULT_WANT);
    }

    public HalloweenCostumes(String name, double cost) {
        this(name, cost, DEFAULT_WANT);
    }

    public HalloweenCostumes(String name, int wantFactor) {
        this(name, DEFAULT_COST, wantFactor);
    }

    public HalloweenCostumes(String name, double cost, int wantFactor) {
        this.name = name.equals("-1") ? DEFAULT_NAME : name;
        this.cost = cost == -1 ? DEFAULT_COST : cost;
        this.wantFactor = wantFactor == -1 ? DEFAULT_WANT : wantFactor;
        this.coolnessScore = 0; // Default coolness score
    }

    public HalloweenCostumes(double cost) {
        this(DEFAULT_NAME, cost, DEFAULT_WANT);
    }

    public HalloweenCostumes(double cost, int wantFactor) {
        this(DEFAULT_NAME, cost, wantFactor);
    }

    public HalloweenCostumes(int wantFactor) {
        this(DEFAULT_NAME, DEFAULT_COST, wantFactor);
    }

    // Calculate coolness score
    public void calcCoolness() {
        coolnessScore = (int) Math.round((name.length() * wantFactor) / cost);
    }

    public String getName() {
        return name;
    }

    public double getCost() {
        return cost;
    }

    public int getWant() {
        return wantFactor;
    }

    // Compare based on coolness score, then alphabetically by name if scores are equal
    @Override
    public int compareTo(HalloweenCostumes other) {
        if (this.coolnessScore != other.coolnessScore) {
            return Integer.compare(other.coolnessScore, this.coolnessScore);
        }
        return this.name.compareTo(other.name);
    }

    @Override
    public String toString() {
        return String.format("%s %d %.2f %d", name, coolnessScore, cost, wantFactor);
    }
}

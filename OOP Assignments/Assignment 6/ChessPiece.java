//Marin Aske
//OOP3330
//Assignment 6: Inheritance
//11/3/2024

import java.util.ArrayList;

public abstract class ChessPiece {
    public static ArrayList<ChessPiece> masterList = new ArrayList<ChessPiece>();
    private String color;

    public ChessPiece(String color) {
        this.color = color;
        masterList.add(this);
    }

    public String getColor() {
        return this.color;
    }

    public static ChessPiece isOccupied(int row, int col) {
        for (ChessPiece piece : masterList) {
            if (piece.getRow() == row && piece.getCol() == col) {
                return piece;
            }
        }
        return null;
    }

    public abstract int getRow();
    public abstract int getCol();
    public abstract boolean isValidMove(int row, int col);
}

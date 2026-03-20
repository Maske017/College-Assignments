//Marin Aske
//OOP3330
//Assignment 6: Inheritance
//11/3/2024

public class Rook extends ChessPiece {
    private int row;
    private int col;

    public Rook(String color, int row, int col) {
        super(color);
        this.row = row;
        this.col = col;
    }

    @Override
    public int getRow() {
        return row;
    }

    @Override
    public int getCol() {
        return col;
    }

    @Override
    public boolean isValidMove(int row, int col) {
        if (this.row != row && this.col != col) {
            return false; // Rook can only move straight
        }
        
        // Determine direction
        int rowDirection = Integer.compare(row, this.row);
        int colDirection = Integer.compare(col, this.col);

        // Check each square along the path to the destination
        int currentRow = this.row + rowDirection;
        int currentCol = this.col + colDirection;

        while (currentRow != row || currentCol != col) {
            if (ChessPiece.isOccupied(currentRow, currentCol) != null) {
                return false; // Path is blocked
            }
            currentRow += rowDirection;
            currentCol += colDirection;
        }

        // Final position check
        ChessPiece occupyingPiece = ChessPiece.isOccupied(row, col);
        return occupyingPiece == null || !occupyingPiece.getColor().equals(this.getColor());
    }
}

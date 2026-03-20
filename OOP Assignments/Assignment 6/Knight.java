//Marin Aske
//OOP3330
//Assignment 6: Inheritance
//11/3/2024

public class Knight extends ChessPiece {
    private int row;
    private int col;

    public Knight(String color, int row, int col) {
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
        int rowDiff = Math.abs(this.row - row);
        int colDiff = Math.abs(this.col - col);
        
        if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
            ChessPiece occupyingPiece = ChessPiece.isOccupied(row, col);
            return occupyingPiece == null || !occupyingPiece.getColor().equals(this.getColor());
        }
        return false;
    }
}

public class KnightTest {
    public static void main(String[] args) {
        // Adding pieces to test valid moves for Knight and Rook
        new Rook("Black", 6, 4);
        new Knight("White", 4, 2);
        new Knight("Black", 6, 3);
        new Rook("White", 2, 3);

        // Testing moves for the White Knight at (4, 2)
        System.out.println(ChessPiece.masterList.get(1).isValidMove(6, 3)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(6, 1)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(2, 3)); // Expected: false
        System.out.println(ChessPiece.masterList.get(1).isValidMove(2, 1)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(5, 4)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(3, 4)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(5, 0)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(3, 0)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(3, 3)); // Expected: true
        System.out.println(ChessPiece.masterList.get(1).isValidMove(6, 4)); // Expected: false
    }
}

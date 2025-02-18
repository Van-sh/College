// 13. Write a program to reverse the elements of a given 2*2 array. Four integer numbers need to be passed as Command-Line arguments.

public class matrixreverse {
   public static void main(String[] args) {
      if (args.length != 4) {
         System.out.println("Please provide exactly 4 arguments.");
         return;
      }

      int[][] matrix = new int[2][2], reversedMatrix = new int[2][2];
      for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 2; j++) {
            matrix[i][j] = Integer.parseInt(args[i * 2 + j]);
         }
      }
      System.out.println("Original Matrix:");
      printMatrix(matrix);
      for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 2; j++) {
            reversedMatrix[i][j] = matrix[matrix.length - i - 1][matrix[i].length - j - 1];
         }
      }
      System.out.println("Reversed Matrix");
      printMatrix(reversedMatrix);
   }

   private static void printMatrix(int[][] matrix) {
      for (int i = 0; i < matrix.length; i++) {
         for (int j = 0; j < matrix[i].length; j++) {
            System.out.print(matrix[i][j] + " ");
         }
         System.out.println();
      }
   }
}

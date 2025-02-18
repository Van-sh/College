// 11. Write a program to print * in Floyd's format (using for and while loop).

import java.util.Scanner;

public class floyd {
   public static void main(String[] args) {
      System.out.print("Enter number of rows: ");
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      sc.close();
      for (int i = 0; i < n; i++) {
         for (int j = 0; j <= i; j++) {
            System.out.print("* ");
         }
         System.out.println("");
      }
   }
}

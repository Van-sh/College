// 12. Initialize an integer array with ASCII values and print the corresponding character values in a single row.

import java.util.Scanner;

public class asciichar {
   public static void main(String[] args) {
      System.out.print("Enter the size of array: ");
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] arr = new int[n];
      System.out.print("Enter ASCII Values: ");
      for (int i = 0; i < n; i++) {
         arr[i] = sc.nextInt();
      }
      sc.close();
      System.out.print("The character values are: ");
      for (int asciiCode : arr) {
         if (asciiCode >= 0 && asciiCode < 128) {
            System.out.print((char) asciiCode + " ");
         } else {
            System.out.print("Invalid ");
         }
      }
   }
}

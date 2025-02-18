// 9. Initialize two-character variables in a program and display the characters alphabetically.

import java.util.Scanner;

public class characters {
   public static void main(String[] args) {
      System.out.print("Enter two characters: ");
      Scanner sc = new Scanner(System.in);
      char a = sc.next().charAt(0), b = sc.next().charAt(0);
      sc.close();
      System.out.println("Alphabetical Order: " + (((a & 31) < (b & 31)) ? (a + " " + b) : (b + " " + a)));
   }
}

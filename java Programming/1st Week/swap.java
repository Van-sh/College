// 5. Write a Program to swap two numbers using bitwise operators

import java.util.Scanner;

public class swap {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter two numbers: ");
      int a = sc.nextInt();
      int b = sc.nextInt();
      sc.close();
      System.out.println("Before swapping: a = " + a + ", b = " + b);
      a = a ^ b;
      b = a ^ b;
      a = a ^ b;
      System.out.println("After swapping : a = " + a + ", b = " + b);
   }
}

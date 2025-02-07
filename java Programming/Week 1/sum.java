// 4. Write a Program to accept two integers as inputs and print their sum

import java.util.Scanner;

public class sum {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter two numbers: ");
      int a = sc.nextInt();
      int b = sc.nextInt();
      sc.close();
      System.out.println("Sum of " + a + " and " + b + " is " + (a + b));
   }
}

// 8. Write a Program to find if the given number is palindrome or not.

import java.util.Scanner;

public class palindrome {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a number: ");
      int original = sc.nextInt();
      sc.close();
      int tmp = original, reverse = 0;
      while (tmp != 0) {
         reverse = reverse * 10 + tmp % 10;
         tmp /= 10;
      }
      if (original == reverse) {
         System.out.println(original + " is a palindrome.");
      } else {
         System.out.println(original + " is not a palindrome.");
      }
   }
}

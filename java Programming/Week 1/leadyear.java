// 7. Write a Program to check whether the entered year is leap year or not.

import java.util.Scanner;

public class leapyear {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a year: ");
      int year = sc.nextInt();
      sc.close();
      if (year % 4 == 0) {
         if (year % 100 == 0) {
            if (year % 400 == 0) {
               System.out.println(year + " is a leap year.");
            } else {
               System.out.println(year + " is not a leap year.");
            }
         } else {
            System.out.println(year + " is a leap year.");
         }
      } else {
         System.out.println(year + " is not a leap year.");
      }
   }
}

// 15. Write a program to produce tokens from a given string. 

import java.util.Scanner;

public class tokens {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a string: ");
      String input = sc.nextLine();
      sc.close();
      System.out.println("Tokens:");
      String token = "";
      for (int i = 0; i < input.length(); i++) {
         char c = input.charAt(i);
         if (c != ' ') {
            token += c;
         } else if (!token.isEmpty()) {
            System.out.println(token);
            token = "";
         }
      }

      if (!token.isEmpty()) {
         System.out.println(token);
      }
   }
}
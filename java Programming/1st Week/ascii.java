// 3. Write a program to find the ASCII code of a character

import java.util.Scanner;

public class ascii {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a character: ");
      char c = sc.next().charAt(0);
      sc.close();
      System.out.println("ASCII value of " + c + " is " + (int) c);
   }
}

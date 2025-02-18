// 10. Write a program to receive a colour code from the user (an Alphabet).

import java.util.Scanner;

public class colourcode {
   public static void main(String[] args) {
      System.out.print("Enter a character for colour: ");
      Scanner sc = new Scanner(System.in);
      char a = sc.next().charAt(0);
      sc.close();
      a = Character.toLowerCase(a);
      System.out.print("Colour: ");
      switch (a) {
         case 'r':
            System.out.println("Red");
            break;
         case 'g':
            System.out.println("Green");
            break;
         case 'b':
            System.out.println("Black");
            break;
         case 'y':
            System.out.println("Yellow");
            break;
         case 'o':
            System.out.println("Orange");
            break;
         default:
            System.out.println("Invalid");
      }
   }
}
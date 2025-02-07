// 1. Write a Program to accept a String as a command-line argument and print a Welcome message as given below:- “Welcome yourname”.
public class welcome {
   public static void main(String[] args) {
      if (args.length < 1) {
         System.out.println("Usage: java welcome <name>");
         return;
      }
      System.out.println("Welcome, " + args[0]);
   }
}
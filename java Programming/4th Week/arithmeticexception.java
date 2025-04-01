import java.util.Scanner;

public class arithmeticexception {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      try {
         System.out.print("Enter two numbers: ");
         int a = sc.nextInt();
         int b = sc.nextInt();

         int result = a / b;
         System.out.println("The quotient of " + a + "/" + b + " = " + result);
      } catch (ArithmeticException e) {
         System.out.println("DivideByZeroException caught");
      } finally {
         System.out.println("Inside finally block");
         sc.close();
      }
   }
}

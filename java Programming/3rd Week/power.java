public class power {
   public static void main(String[] args) {
      System.out.println("2^3 = " + Calculator.powerInt(2, 3));
      System.out.println("2.5^3 = " + Calculator.powerDouble(2.5, 3));
   }
}

class Calculator {
   static int powerInt(int num1, int num2) {
      int result = 1;
      for (int i = 0; i < num2; i++) {
         result *= num1;
      }
      return result;
   }

   static double powerDouble(double num1, int num2) {
      double result = 1;
      for (int i = 0; i < num2; i++) {
         result *= num1;
      }
      return result;
   }
}
import java.util.Scanner;

public class marksexception {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      try {
         for (int i = 1; i <= 2; i++) {
            System.out.print("Enter Student " + i + " Name: ");
            String name = sc.next();

            int totalMarks = 0;
            for (int j = 1; j <= 3; j++) {
               System.out.print("Enter marks for Subject " + j + ": ");
               String input = sc.next();

               int marks;
               try {
                  marks = Integer.parseInt(input);
               } catch (NumberFormatException e) {
                  throw new NumberFormatException("Invalid input: " + input + ". Please enter an integer.");
               }

               if (marks < 0) {
                  throw new NegativeValueException("Marks cannot be negative: " + marks);
               }

               if (marks > 100) {
                  throw new OutOfRangeException("Marks should be between 0 and 100. Invalid: " + marks);
               }

               totalMarks += marks;
            }

            double average = totalMarks / 3.0;
            System.out.println(name + "'s Average Marks: " + Math.round(average));
         }
      } catch (NumberFormatException | NegativeValueException | OutOfRangeException e) {
         System.out.println("Exception: " + e.getMessage());
      } finally {
         sc.close();
         System.out.println("Execution completed.");
      }
   }
}

class NegativeValueException extends Exception {
   public NegativeValueException(String message) {
      super(message);
   }
}

class OutOfRangeException extends Exception {
   public OutOfRangeException(String message) {
      super(message);
   }
}

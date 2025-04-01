import java.util.Scanner;

public class arrayexception {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      try {
         System.out.print("Enter the size of the array: ");
         int size = Integer.parseInt(sc.nextLine()); 
         int[] arr = new int[size];

         System.out.println("Enter " + size + " elements:");
         for (int i = 0; i < size; i++) {
            arr[i] = Integer.parseInt(sc.nextLine());
         }

         System.out.print("Enter index to retrieve element: ");
         int index = Integer.parseInt(sc.nextLine());

         System.out.println("Element at index " + index + ": " + arr[index]); 
      } catch (NumberFormatException e) {
         System.out.println("Invalid input! Please enter only numbers.");
      } catch (ArrayIndexOutOfBoundsException e) {
         System.out.println("Index out of bounds! Please enter a valid index.");
      } finally {
         System.out.println("Execution completed.");
         sc.close();
      }
   }
}

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FirstNonRepeating {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter a string: ");
      String text = sc.nextLine();
      sc.close();
      Map<Character, Integer> freq = new HashMap<>();

      for (int i = 0; i < text.length(); i++) {
         Character ch = text.charAt(i);
         freq.put(ch, freq.getOrDefault(ch, 0) + 1);
      }

      for (int i = 0; i < text.length(); i++) {
         Character ch = text.charAt(i);
         if (freq.get(ch) == 1) {
            System.out.println("First non-repeating character: " + ch);
            break;
         }
      }
   }
}

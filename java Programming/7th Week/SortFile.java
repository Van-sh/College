import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortFile {
   public static void main(String[] args) {
   File file = new File("./sort.txt");

      try {
         List<String> lines = new ArrayList<String>();
         BufferedReader reader = new BufferedReader(new FileReader(file));
         String line;
         while ((line = reader.readLine()) != null) {
            lines.add(line);
         }
         reader.close();

         Collections.sort(lines);

         BufferedWriter writer = new BufferedWriter(new FileWriter(file));
         for (String l : lines) {
            writer.write(l);
            writer.newLine();
         }
         writer.close();

         System.out.println("Contents of the file have been sorted successfully");
      } catch (Exception e) {
         System.out.println("Failed to sort due to the error: " + e.getMessage());
      }
   }
}

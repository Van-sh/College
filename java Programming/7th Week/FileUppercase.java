import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class FileUppercase {
   public static void main(String[] args) {
      File file = new File("./uppercase.txt");

      try {
         BufferedReader reader = new BufferedReader(new FileReader(file));
         StringBuilder sb = new StringBuilder();
         String line;

         while ((line = reader.readLine()) != null) {
            sb.append(line.toUpperCase()).append(System.lineSeparator());
         }
         reader.close();

         BufferedWriter writer = new BufferedWriter(new FileWriter(file));
         writer.write(sb.toString());
         writer.close();

         System.out.println("File content converted to uppercase.");
      } catch (Exception e) {

         System.out.println("Failed to convert file content due to exception " + e.getMessage());
      }
   }
}

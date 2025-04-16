import java.io.*;

public class FileHandling {
   public static void main(String[] args) throws IOException {
      File file = new File("./basic.txt");

      FileWriter fw = new FileWriter(file);
      fw.write("This is a basic file write operation.");
      fw.close();
      System.out.println("Data written to basic.txt");

      FileReader fr = new FileReader(file);
      int ch;
      System.out.println("Reading content from basic.txt:");
      while ((ch = fr.read()) != -1) {
         System.out.print((char) ch);
      }
      fr.close();
   }
}
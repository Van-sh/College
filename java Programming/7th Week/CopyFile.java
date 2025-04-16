import java.io.*;

public class CopyFile {
   public static void main(String[] args) throws IOException {
      File inputFile = new File("./input.txt");

      File outputFile = new File("./output.txt");

      FileReader reader = new FileReader(inputFile);
      FileWriter writer = new FileWriter(outputFile);

      int ch;
      while ((ch = reader.read()) != -1) {
         writer.write(ch);
      }

      reader.close();
      writer.close();

      System.out.println("Content copied from input.txt to output.txt");
   }
}
import java.io.*;
import java.net.*;

public class TCPClient {
   public static void main(String[] args) throws Exception {
      Socket s = new Socket("localhost", 1234);

      PrintWriter pw = new PrintWriter(s.getOutputStream(), true);
      pw.println("Send acknowledgement and status");

      BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
      String response = br.readLine();

      System.out.println("Server Response: " + response);

      s.close();
   }
}
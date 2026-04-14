import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
   public static void main(String[] args) throws Exception {
      ServerSocket ss = new ServerSocket(1234);
      System.out.println("Server waiting...");

      Socket s = ss.accept();

      BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
      String msg = br.readLine();

      System.out.println("Client Request: " + msg);

      PrintWriter pw = new PrintWriter(s.getOutputStream(), true);
      pw.println("Hello Client, your request processed successfully!");

      ss.close();
   }
}

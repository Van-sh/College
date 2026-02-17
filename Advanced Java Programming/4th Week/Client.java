import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
   private static final String HOST = "localhost";
   private static final int PORT = 12345;

   public static void main(String[] args) {
      try (Socket socket = new Socket(HOST, PORT);
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader in = new BufferedReader(
                  new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

         System.out.print("Enter text to send: ");
         String msg = userIn.readLine();
         out.println(msg);

         String reply = in.readLine();
         System.out.println("Server replied: " + reply);

      } catch (IOException e) {
         System.err.println("Client error: " + e.getMessage());
      }
   }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
   private static final int PORT = 12345;

   public static void main(String[] args) {
      System.out.println("EchoServer listening on port " + PORT);

      try (ServerSocket serverSocket = new ServerSocket(PORT)) {

         while (true) {
            try (Socket client = serverSocket.accept();
                  BufferedReader in = new BufferedReader(
                        new InputStreamReader(client.getInputStream()));
                  PrintWriter out = new PrintWriter(client.getOutputStream(), true)) {

               System.out.println("Client connected from " + client.getRemoteSocketAddress());

               String line;
               while ((line = in.readLine()) != null) {
                  System.out.println("Received: " + line);
                  out.println(line.toUpperCase());
               }
               System.out.println("Client disconnected.");
            }
         }
      } catch (IOException e) {
         System.err.println("Server error: " + e.getMessage());
      }
   }
}
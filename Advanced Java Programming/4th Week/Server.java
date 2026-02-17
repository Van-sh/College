import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
   public static void main(String[] args) {
      try {
         ServerSocket serverSocket = new ServerSocket(8080);
         System.out.println("Server started...");
         System.out.println("Waiting for client...");
         Socket socket = serverSocket.accept();
         System.out.println("Client connected.");
         BufferedReader inputFromClient = new BufferedReader(
               new InputStreamReader(socket.getInputStream()));
         PrintWriter outputToClient = new PrintWriter(
               socket.getOutputStream(), true);
         BufferedReader keyboard = new BufferedReader(
               new InputStreamReader(System.in));
         String message;
         while (true) {
            message = inputFromClient.readLine();
            if (message.equalsIgnoreCase("exit")) {
               System.out.println("Client disconnected.");
               break;
            }
            System.out.println("Client: " + message);
            System.out.print("Server: ");
            String reply = keyboard.readLine();
            outputToClient.println(reply);
            if (reply.equalsIgnoreCase("exit")) {
               break;
            }
         }
         socket.close();
         serverSocket.close();
         System.out.println("Connection closed.");
      } catch (Exception e) {
         System.out.println("Error: " + e.getMessage());
      }
   }
}

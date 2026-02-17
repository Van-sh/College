import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
   public static void main(String[] args) {
      try {
         Socket socket = new Socket("localhost", 8080);
         System.out.println("Connected to Server.");
         BufferedReader inputFromServer = new BufferedReader(
               new InputStreamReader(socket.getInputStream()));
         PrintWriter outputToServer = new PrintWriter(
               socket.getOutputStream(), true);
         BufferedReader keyboard = new BufferedReader(
               new InputStreamReader(System.in));
         String message;
         while (true) {
            System.out.print("Client: ");
            message = keyboard.readLine();
            outputToServer.println(message);
            if (message.equalsIgnoreCase("exit")) {
               break;
            }
            String reply = inputFromServer.readLine();
            if (reply.equalsIgnoreCase("exit")) {
               System.out.println("Server disconnected.");
               break;
            }
            System.out.println("Server: " + reply);
         }
         socket.close();
         System.out.println("Connection closed.");
      } catch (Exception e) {
         System.out.println("Error: " + e.getMessage());
      }
   }
}
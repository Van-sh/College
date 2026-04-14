import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPServer {
   public static void main(String[] args) throws Exception {
      DatagramSocket ds = new DatagramSocket(1234);
      byte[] buffer = new byte[1024];

      DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
      ds.receive(dp);

      String msg = new String(dp.getData(), 0, dp.getLength());
      System.out.println("Client Request: " + msg);

      String response = "Welcome, your message received at server!";
      DatagramPacket dp2 = new DatagramPacket(
            response.getBytes(),
            response.length(),
            dp.getAddress(),
            dp.getPort());
      ds.send(dp2);
      ds.close();
   }
}

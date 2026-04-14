import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient {
   public static void main(String[] args) throws Exception {
      DatagramSocket ds = new DatagramSocket();

      String msg = "Requesting server time and greeting";
      InetAddress ip = InetAddress.getByName("localhost");

      DatagramPacket dp = new DatagramPacket(msg.getBytes(), msg.length(), ip, 1234);
      ds.send(dp);

      byte[] buffer = new byte[1024];
      DatagramPacket dp2 = new DatagramPacket(buffer, buffer.length);

      ds.receive(dp2);
      String response = new String(dp2.getData(), 0, dp2.getLength());

      System.out.println("Server Response: " + response);
      ds.close();
   }
}
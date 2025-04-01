import java.applet.Applet;
import java.awt.*;

public class counter extends Applet implements Runnable {
   private int counter = 0;
   private Thread thread;

   @Override
   public void init() {
      thread = new Thread(this);
      thread.start();
   }

   @Override
   public void paint(Graphics g) {
      g.setFont(new Font("Arial", Font.BOLD, 30));
      g.setColor(Color.BLACK);
      g.drawString("Counter: " + counter, getWidth() / 2 - 60, getHeight() / 2);
   }

   @Override
   public void run() {
      while (true) {
         counter++;
         repaint();
         try {
            Thread.sleep(1000);
         } catch (InterruptedException e) {
            e.printStackTrace();
         }
      }
   }
}

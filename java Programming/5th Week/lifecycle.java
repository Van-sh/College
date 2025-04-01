import java.applet.Applet;
import java.awt.*;

public class lifecycle extends Applet {
   @Override
   public void init() {
      System.out.println("Applet Initialized");
   }

   @Override
   public void start() {
      System.out.println("Applet Started");
   }

   @Override
   public void paint(Graphics g) {
      g.drawString("Applet Lifecycle Demo", 50, 50);
   }

   @Override
   public void stop() {
      System.out.println("Applet Stopped");
   }

   @Override
   public void destroy() {
      System.out.println("Applet Destroyed");
   }
}

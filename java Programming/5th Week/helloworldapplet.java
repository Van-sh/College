import java.applet.Applet;
import java.awt.*;

public class helloworldapplet extends Applet {

   @Override
   public void init() {
      setBackground(Color.BLACK);
   }
   
   @Override
   public void paint(Graphics g) {
      g.setColor(Color.BLUE);
      g.drawString("Hello World", 50, 50);
      showStatus("Vansh Shandilya");
   }
}

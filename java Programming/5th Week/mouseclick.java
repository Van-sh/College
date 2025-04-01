import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class mouseclick extends Applet {
   private String name = "Vansh Shandilya";
   private boolean nameVisible = false;

   @Override
   public void init() {
      addMouseListener(new MouseAdapter() {
         @Override
         public void mousePressed(MouseEvent e) {
            nameVisible = true;
            repaint();
         }

         @Override
         public void mouseReleased(MouseEvent e) {
            nameVisible = false;
            repaint();
         }
      });
   }

   @Override
   public void paint(Graphics g) {
      super.paint(g);
      if (nameVisible) {
         g.setColor(Color.BLACK);
         g.drawString(name, getWidth() / 2 - g.getFontMetrics().stringWidth(name) / 2, getHeight() / 2);
      }
   }
}

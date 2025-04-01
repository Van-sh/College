import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class mousedrag extends Applet {
   @Override
   public void init() {
      setBackground(Color.WHITE);
      addMouseMotionListener(new MouseAdapter() {
         @Override
         public void mouseDragged(MouseEvent e) {
            setBackground(Color.CYAN);
         }
      });

      addMouseListener(new MouseAdapter() {
         @Override
         public void mouseReleased(MouseEvent e) {
            setBackground(Color.WHITE);
         }
      });
   }
}

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/*
<applet code="ShapeApplet.class" width="500" height="300">
</aplet>
*/
public class ShapeApplet extends Applet {
   public void paint(Graphics g) {
      // Rectangle
      g.setColor(Color.RED);
      g.drawRect(50, 50, 100, 60);
      // Oval
      g.setColor(Color.BLUE);
      g.drawOval(200, 50, 100, 60);
      // Line
      g.setColor(Color.BLACK);
      g.drawLine(50, 150, 200, 150);
      // Circle (Oval with equal width & height)
      g.setColor(Color.GREEN);
      g.drawOval(300, 120, 80, 80);
   }
}
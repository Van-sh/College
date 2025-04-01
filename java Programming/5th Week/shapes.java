import java.applet.Applet;
import java.awt.*;

public class shapes extends Applet {
   @Override
   public void paint(Graphics g) {
      Graphics2D g2 = (Graphics2D) g;
      g2.setStroke(new BasicStroke(3));

      g2.setColor(Color.BLACK);
      g2.drawLine(20, 20, 120, 20);

      g2.setColor(new Color(0, 0, 139));
      g2.drawRect(20, 40, 100, 50);

      g2.setColor(new Color(34, 139, 34));
      g2.drawRoundRect(20, 100, 100, 50, 20, 20);

      g2.setColor(new Color(255, 140, 0));
      g2.fillRect(150, 40, 100, 50);

      g2.setColor(new Color(139, 0, 139));
      g2.fillRoundRect(150, 100, 100, 50, 20, 20);

      g2.setColor(new Color(0, 0, 205));
      g2.drawOval(300, 40, 50, 50);

      g2.setColor(new Color(178, 34, 34));
      g2.drawOval(300, 100, 80, 50);

      g2.setColor(new Color(139, 69, 19));
      g2.drawArc(420, 40, 80, 50, 0, 180);

      g2.setColor(new Color(105, 105, 105));
      g2.fillArc(420, 100, 80, 50, 0, 180);

      g2.setColor(Color.BLACK);
      int[] xPoints = { 550, 600, 650, 600, 550 };
      int[] yPoints = { 100, 40, 100, 150, 125 };
      g2.drawPolygon(xPoints, yPoints, xPoints.length);
   }
}

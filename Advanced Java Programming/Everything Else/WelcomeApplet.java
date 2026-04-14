import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

/*
<applet code="WelcomeApplet.class" width="400" height="200">
</applet>
*/
public class WelcomeApplet extends Applet {
   public void init() {
      setBackground(Color.LIGHT_GRAY);
   }

   public void paint(Graphics g) {
      Font f1 = new Font("Arial", Font.BOLD, 24);
      g.setFont(f1);
      g.setColor(Color.BLUE);
      g.drawString("Hello", 160, 80);
      Font f2 = new Font("Arial", Font.PLAIN, 16);
      g.setFont(f2);
      g.setColor(Color.BLACK);
      g.drawString("Welcome to Applet Programming", 80, 120);
   }
}
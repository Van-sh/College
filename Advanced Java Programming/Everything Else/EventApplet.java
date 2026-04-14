import java.applet.*;
import java.awt.event.*;

public class EventApplet extends Applet implements ActionListener {
   Button button;

   public void init() {
      button = new Button("Click Me");
      add(button);
      button.addActionListener(this);
   }

   public void actionPerformed(ActionEvent e) {
      getGraphics().drawString("Button Clicked!", 20, 100);
   }
}

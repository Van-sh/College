import java.applet.Applet;
import java.awt.*;
import java.util.Calendar;

public class analogclock extends Applet implements Runnable {
    private Thread thread;

    @Override
    public void init() {
        setSize(300, 300);
        thread = new Thread(this);
        thread.start();
    }

    @Override
    public void paint(Graphics g) {
        int centerX = getWidth() / 2;
        int centerY = getHeight() / 2;
        int radius = 100;

        g.setColor(Color.WHITE);
        g.fillOval(centerX - radius, centerY - radius, 2 * radius, 2 * radius);
        g.setColor(Color.BLACK);
        g.drawOval(centerX - radius, centerY - radius, 2 * radius, 2 * radius);

        Calendar calendar = Calendar.getInstance();
        int hour = calendar.get(Calendar.HOUR);
        int minute = calendar.get(Calendar.MINUTE);
        int second = calendar.get(Calendar.SECOND);

        double secondAngle = Math.toRadians(second * 6 - 90);
        double minuteAngle = Math.toRadians(minute * 6 - 90);
        double hourAngle = Math.toRadians(hour * 30 + minute * 0.5 - 90);

        drawHand(g, centerX, centerY, secondAngle, radius - 10, Color.RED);
        drawHand(g, centerX, centerY, minuteAngle, radius - 20, Color.BLUE);
        drawHand(g, centerX, centerY, hourAngle, radius - 40, Color.BLACK);
    }

    private void drawHand(Graphics g, int x, int y, double angle, int length, Color color) {
        int xEnd = x + (int) (length * Math.cos(angle));
        int yEnd = y + (int) (length * Math.sin(angle));
        g.setColor(color);
        g.drawLine(x, y, xEnd, yEnd);
    }

    @Override
    public void run() {
        while (true) {
            repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

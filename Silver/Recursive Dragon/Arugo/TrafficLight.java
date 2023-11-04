import javax.swing.*;
import java.awt.*;

public class TrafficLight extends JFrame {

    public TrafficLight() {
        setTitle("Traffic Light");
        setSize(200, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        add(new TrafficLightPanel());

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new TrafficLight();
        });
    }
}

class TrafficLightPanel extends JPanel {

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int width = getWidth();
        int height = getHeight();

        // Drawing the background
        g.setColor(Color.lightGray);
        g.fillRect(0, 0, width, height);

        int lightDiameter = 60;
        int margin = 20;

        // Draw the box around the traffic light
        g.setColor(Color.black);
        g.drawRect((width - lightDiameter) / 2 - 5, margin - 5, lightDiameter + 10, 3 * lightDiameter + 10);

        // Red light
        g.setColor(Color.red);
        g.fillOval((width - lightDiameter) / 2, margin, lightDiameter, lightDiameter);

        // Yellow light
        g.setColor(Color.yellow);
        g.fillOval((width - lightDiameter) / 2, 2 * margin + lightDiameter, lightDiameter, lightDiameter);

        // Green light
        g.setColor(Color.green);
        g.fillOval((width - lightDiameter) / 2, 3 * margin + 2 * lightDiameter, lightDiameter, lightDiameter);
    }
}
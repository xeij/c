import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyGUI {
    private static JPanel canvas;
    private static int canvasWidth, canvasHeight;
    private static Point mousePos;

    public static void main(String[] args) {
        // create a new window
        JFrame frame = new JFrame("Draw Shapes");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1280, 720);

        // create a panel to draw on
        canvas = new JPanel() {
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                canvasWidth = getWidth();
                canvasHeight = getHeight();
                drawShape(g);
            }
        };
        canvas.setBackground(Color.WHITE);
        frame.add(canvas);

        // update mouse position every 10 milliseconds
        Timer mouseTimer = new Timer(1, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mousePos = MouseInfo.getPointerInfo().getLocation();
                SwingUtilities.convertPointFromScreen(mousePos, canvas);
            }
        });
        mouseTimer.start();

        // start drawing triangles every half second
        Timer drawingTimer = new Timer(25, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                canvas.repaint();
            }
        });
        drawingTimer.start();

        // show the window
        frame.setVisible(true);
    }

    private static void drawShape(Graphics g) {
        if (mousePos != null) {
            // draw a transparent triangle with random colors and vertices
            int x1 = mousePos.x;
            int y1 = mousePos.y;
            int x2 = x1 + (int)(Math.random() * 500) - 250;
            int y2 = y1 + (int)(Math.random() * 500) - 250;
            int x3 = x1 + (int)(Math.random() * 500) - 250;
            int y3 = y1 + (int)(Math.random() * 500) - 250;
            Color color1 = new Color((int)(Math.random() * 256), (int)(Math.random() * 256), (int)(Math.random() * 256), 128);
            Color color2 = new Color((int)(Math.random() * 256), (int)(Math.random() * 256), (int)(Math.random() * 256), 128);
            GradientPaint gradient = new GradientPaint(x1, y1, color1, x2, y2, color2);
            Graphics2D g2d = (Graphics2D) g.create();
            g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.5f));
            g2d.setPaint(gradient);
            Polygon p = new Polygon();
            p.addPoint(x1, y1);
            p.addPoint(x2, y2);
            p.addPoint(x3, y3);
            g2d.fill(p);
            g2d.dispose();
        }
    }
}

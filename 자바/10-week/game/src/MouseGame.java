import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MouseGame extends JFrame {
    private JLabel la = new JLabel("c");

    public MouseGame() {
        setTitle("클릭 연습 용 응용프로그램");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.addMouseListener(new MyMouseAdapter());

        c.setLayout(null);
        la.setSize(50, 20);
        la.setLocation(100, 100);
        c.add(la);

        setSize(500, 500);
        setVisible(true);
    }

    class MyMouseAdapter extends MouseAdapter {
        public void mousePressed(MouseEvent e) {
            int labelX = la.getX();
            int labelY = la.getY();
            int labelWidth = la.getWidth();
            int labelHeight = la.getHeight();

            // Check if the click is within the bounds of the label
            if (e.getX() >= labelX && e.getX() <= labelX + labelWidth &&
                    e.getY() >= labelY && e.getY() <= labelY + labelHeight) {
                int x = (int) (Math.random() * (getWidth() - labelWidth));
                int y = (int) (Math.random() * (getHeight() - labelHeight));
                la.setLocation(x, y);
            }
        }
    }

    public static void main(String[] args) {
        new MouseGame();
    }
}

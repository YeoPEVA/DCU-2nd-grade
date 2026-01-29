import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MouseGame extends JFrame {
    private JLabel la = new JLabel("c");
    public MouseGame(){
        setTitle("클릭 연습 용 응용프로그램");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.addMouseListener(new MyMouseAdapter());

        c.setLayout(null);
        la.setSize(50,20);
        la.setLocation(100,100);
        c.add(la);

        setSize(500,500);
        setVisible(true);
    }

    class MyMouseAdapter extends MouseAdapter{
        public void mousePressed(MouseEvent e){
            int x_t = e.getX;
            int x_y = e.getY;

            int x = (int)(Math.random()*450);;
            int y = (int)(Math.random()*450);
            la.setLocation(x,y);
        }
    }

    public static void main(String [] args){
        new MouseGame();
    }
}

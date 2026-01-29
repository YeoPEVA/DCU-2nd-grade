import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

public class GamblingGame extends JFrame{
    JLabel first,second,third, sameText;
    GamblingGame(){
        setTitle("Open Challenge 10");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);


        setLayout(null);
        addKeyListener(new MyKeyAdapter());

        first = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
        second = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
        third = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
        sameText = new JLabel("시작합니다.",SwingConstants.CENTER);

        first.setBackground(Color.PINK);
        first.setSize(100,50);
        first.setLocation(40,80);
        first.setFont(new Font("Arial",Font.PLAIN,30));
        first.setOpaque(true);

        second.setBackground(Color.PINK);
        second.setSize(100,50);
        second.setLocation(180,80);
        second.setFont(new Font("Arial",Font.PLAIN,30));
        second.setOpaque(true);

        third.setBackground(Color.PINK);
        third.setSize(100,50);
        third.setLocation(320,80);
        third.setFont(new Font("Arial",Font.PLAIN,30));
        third.setOpaque(true);

        sameText.setSize(300,50);
        sameText.setLocation(80,150);


        add(first);
        add(second);
        add(third);
        add(sameText);

        setVisible(true);
        requestFocus();
    }
    public static void main(String[] args) {
        new GamblingGame();
    }

    class MyKeyAdapter extends KeyAdapter{
        public void keyPressed(KeyEvent e) {
            if(e.getKeyChar() == '\n') {
                first.setText((int)(Math.random()*5)+"");
                second.setText((int)(Math.random()*5)+"");
                third.setText((int)(Math.random()*5)+"");
                if(first.getText().equals(second.getText())) {
                    if(second.getText().equals(third.getText()))
                        sameText.setText("축하합니다.");
                    else
                        sameText.setText("아쉽군요");
                }
                else
                    sameText.setText("아쉽군요");


            }
        }
    }

}
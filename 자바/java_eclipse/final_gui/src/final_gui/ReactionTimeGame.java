package final_gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class ReactionTimeGame extends JPanel {
    private JButton startButton;
    private JButton clickButton;
    private JLabel instructionsLabel;
    private JLabel resultLabel;
    private long startTime;
    private Timer timer;
    private Random random;

    public ReactionTimeGame() {
        random = new Random();
        startButton = new JButton("Start");
        clickButton = new JButton("Click Me!");
        clickButton.setEnabled(false);
        instructionsLabel = new JLabel("Press 'Start' to begin the game", SwingConstants.CENTER);
        resultLabel = new JLabel("", SwingConstants.CENTER);

        setLayout(new BorderLayout());
        add(instructionsLabel, BorderLayout.NORTH);
        add(clickButton, BorderLayout.CENTER);
        add(startButton, BorderLayout.SOUTH);
        add(resultLabel, BorderLayout.EAST);

        startButton.addActionListener(new StartButtonListener());
        clickButton.addActionListener(new ClickButtonListener());
    }

    private class StartButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            startButton.setEnabled(false);
            instructionsLabel.setText("Wait for the button to change color...");

            int delay = random.nextInt(3000) + 2000; // 2 to 5 seconds
            timer = new Timer(delay, new TimerListener());
            timer.setRepeats(false);
            timer.start();
        }
    }

    private class TimerListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            clickButton.setEnabled(true);
            clickButton.setBackground(Color.RED);
            instructionsLabel.setText("Click the button now!");
            startTime = System.currentTimeMillis();
        }
    }

    private class ClickButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            long reactionTime = System.currentTimeMillis() - startTime;
            clickButton.setEnabled(false);
            clickButton.setBackground(null);
            instructionsLabel.setText("Press 'Start' to play again");
            resultLabel.setText("Your reaction time: " + reactionTime + " ms");
            startButton.setEnabled(true);
        }
    }
}

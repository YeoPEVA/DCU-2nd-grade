import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame {
    private JTextField display;
    private JPanel buttonPanel;
    private StringBuilder currentInput;
    private double result;
    private String operator;

    public Calculator() {
        setTitle("Calculator");
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        display = new JTextField();
        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setFont(new Font("Arial", Font.PLAIN, 24));

        buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10));

        currentInput = new StringBuilder();
        operator = "";
        result = 0;

        String[] buttons = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        setLayout(new BorderLayout());
        add(display, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);

        setVisible(true);
    }

    private class ButtonClickListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            if (command.charAt(0) >= '0' && command.charAt(0) <= '9') {
                currentInput.append(command);
                display.setText(currentInput.toString());
            } else if (command.equals("C")) {
                currentInput.setLength(0);
                operator = "";
                result = 0;
                display.setText("");
            } else if (command.equals("=")) {
                if (operator.isEmpty()) return;
                double currentValue = Double.parseDouble(currentInput.toString());
                calculate(currentValue);
                display.setText(String.valueOf(result));
                currentInput.setLength(0);
                operator = "";
            } else {
                if (currentInput.length() == 0) return;
                double currentValue = Double.parseDouble(currentInput.toString());
                if (operator.isEmpty()) {
                    result = currentValue;
                } else {
                    calculate(currentValue);
                }
                operator = command;
                currentInput.setLength(0);
                display.setText(String.valueOf(result));
            }
        }

        private void calculate(double currentValue) {
            switch (operator) {
                case "+" -> result += currentValue;
                case "-" -> result -= currentValue;
                case "*" -> result *= currentValue;
                case "/" -> result /= currentValue;
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Calculator::new);
    }
}

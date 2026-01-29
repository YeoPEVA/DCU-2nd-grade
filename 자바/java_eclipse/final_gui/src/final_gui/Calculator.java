package final_gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JPanel {
    private JTextField display;
    private JPanel buttonPanel;
    private StringBuilder currentInput;
    private double result;
    private String operator;

    public Calculator() {
        // UI 설정 부분
        display = new JTextField();
        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setFont(new Font("Arial", Font.PLAIN, 24));

        buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10)); // 버튼 배치를 위한 그리드 레이아웃 설정

        currentInput = new StringBuilder();
        operator = "";
        result = 0;

        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", "C", "=", "+"
        };

        // 각 버튼에 대한 설정 및 이벤트 리스너 추가
        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 24));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        // 레이아웃 설정
        setLayout(new BorderLayout());
        add(display, BorderLayout.NORTH);
        add(buttonPanel, BorderLayout.CENTER);
    }

    // 버튼 클릭 이벤트 처리를 위한 리스너 정의
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
                if (!operator.isEmpty()) {
                    double currentValue = Double.parseDouble(currentInput.toString());
                    calculate(currentValue);
                    display.setText(String.valueOf(result));
                    currentInput.setLength(0);
                    operator = "";
                }
            } else {
                if (!currentInput.isEmpty()) {
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
        }

        // 계산 로직
        private void calculate(double currentValue) {
            switch (operator) {
                case "+" -> result += currentValue;
                case "-" -> result -= currentValue;
                case "*" -> result *= currentValue;
                case "/" -> result /= currentValue;
            }
        }
    }
}

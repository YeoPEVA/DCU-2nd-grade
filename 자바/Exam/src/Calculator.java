import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/**
 * 4번문제 계산기
 * 사용자의 입력을 받아 기본적인 산술 연산을 수행합니다.
 */
public class Calculator extends Exam {

    private JFrame frame;  // GUI 프레임
    private JTextField display;  // 결과를 표시할 텍스트 필드

    private String currentNumber;  // 현재 입력된 숫자를 저장
    private String lastOperator;  // 마지막에 사용된 연산자를 저장
    private double result;  // 계산된 결과를 저장

    /**
     * 계산기 생성자.
     * GUI를 구성하고, 계산기의 초기 상태를 설정합니다.
     */
    public Calculator() {
        frame = new JFrame("4번문제 계산기");  // 새로운 JFrame 생성
        frame.setSize(300, 400);  // 프레임 크기 설정
        JPanel panel = new JPanel();  // 패널 생성
        panel.setLayout(new BorderLayout());  // 패널 레이아웃 설정
        setLocationRelativeTo(null);  // 프레임 위치 설정
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 프레임 닫기 동작 시, 프레임을 메모리에서 제거합니다.
        display = new JTextField();  // 텍스트 필드 생성
        display.setEditable(false);  // 텍스트 필드를 수정 불가능하게 설정
        panel.add(display, BorderLayout.NORTH);  // 패널에 텍스트 필드 추가

        // 버튼 패널 생성 및 레이아웃 설정
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4));

        // 버튼 라벨 배열
        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+"
        };

        // 버튼 생성, 이벤트 핸들러 연결, 패널에 추가
        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        // 버튼 패널을 메인 패널에 추가
        panel.add(buttonPanel, BorderLayout.CENTER);

        // 메인 패널을 프레임에 추가
        frame.add(panel);
        frame.setVisible(true);  // 프레임을 보이게 설정

        // 초기값 설정
        currentNumber = "";
        lastOperator = "";
        result = 0.0;
    }

    /**
     * 사용자의 버튼 클릭 이벤트를 처리하는 내부 클래스입니다.
     */
    private class ButtonClickListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String buttonLabel = ((JButton) e.getSource()).getText();

            if (buttonLabel.matches("[0-9.]")) {// 숫자와 '.' 버튼을 처리
                currentNumber += buttonLabel;
                display.setText(currentNumber);
            } else if (buttonLabel.matches("[+-/*]")) { // 연산자 버튼을 처리
                performOperation(buttonLabel);
            } else if (buttonLabel.equals("=")) {// '=' 버튼을 처리
                calculateResult();
            } else { // 그 외, 즉, 초기화해야 하는 경우
                clearCalculator();
            }
        }
    }

    /**
     * 주어진 연산자를 사용해 현재까지의 결과와 현재 숫자를 계산합니다.
     *
     * @param operator 적용할 연산자
     */
    private void performOperation(String operator) {
        if (!currentNumber.isEmpty()) {
            if (!lastOperator.isEmpty()) {
                calculateResult();
            }
            result = Double.parseDouble(currentNumber);
            lastOperator = operator;
            currentNumber = "";
        }
    }

    /**
     * 마지막 연산자를 사용해 현재까지의 결과와 현재 숫자를 계산하고,
     * 결과를 디스플레이에 표시합니다.
     */
    private void calculateResult() {
        if (!currentNumber.isEmpty() && !lastOperator.isEmpty()) {
            double number = Double.parseDouble(currentNumber);
            switch (lastOperator) {
                case "+":
                    result += number;
                    break;
                case "-":
                    result -= number;
                    break;
                case "*":
                    result *= number;
                    break;
                case "/":
                    result /= number;
                    break;
            }
            currentNumber = "";
            lastOperator = "";
            display.setText(String.valueOf(result));
        }
    }

    /**
     * 계산기의 상태를 초기화합니다.
     */
    private void clearCalculator() {
        currentNumber = "";
        lastOperator = "";
        result = 0.0;
        display.setText("");
    }
}

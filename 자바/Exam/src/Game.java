import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.time.Instant;

/**
 * 숫자 클릭 게임을 나타내는 클래스입니다.
 */
public class Game extends Exam {

    private JFrame frame;  // 게임을 위한 프레임을 생성합니다.
    private JLabel[] num = new JLabel[21]; // 0부터 20까지의 숫자 라벨을 위한 배열을 생성합니다.
    private int nowIndex;  // 현재 클릭해야 할 숫자의 인덱스를 나타내는 변수입니다.
    private Instant startTime;  // 게임 시작 시간을 저장합니다.

    /**
     * Game 클래스의 생성자입니다. 숫자를 클릭하는 게임 환경을 설정합니다.
     */
    public Game() {
        frame = new JFrame("3번문제 게임");  // 프레임 생성
        frame.setSize(800, 600);  // 프레임의 크기 설정
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 프레임 닫기 동작 시, 프레임을 메모리에서 제거합니다.
        JPanel panel = new JPanel();  // 패널 생성
        panel.setLayout(null);  // 패널의 레이아웃 관리자 제거

        // 0부터 20까지의 숫자에 대한 라벨 생성
        for (int i = 0; i < 21; i++) {
            JLabel temp = new JLabel(Integer.toString(i));  // 숫자 라벨 생성
            temp.setSize(20, 20);  // 라벨 크기 설정

            // 라벨에 마우스 클릭 리스너 추가
            temp.addMouseListener(new MouseAdapter() {
                public void mouseClicked(MouseEvent e) {
                    JLabel clickedLabel = (JLabel) e.getSource();  // 클릭된 라벨 가져오기
                    int clickedNum = Integer.parseInt(clickedLabel.getText());  // 라벨의 텍스트를 숫자로 변환

                    // 클릭된 숫자가 현재 클릭해야 하는 숫자인 경우
                    if (clickedNum == nowIndex) {
                        clickedLabel.setVisible(false);  // 클릭된 라벨 숨기기
                        nowIndex++;  // 다음 클릭해야 할 숫자로 인덱스 업데이트

                        // 게임 시작 시간 기록
                        if (nowIndex == 1) {
                            startTime = Instant.now();  // 현재 시간을 시작 시간으로 설정
                        }
                        // 마지막 숫자를 클릭했을 때 경과 시간 계산 및 화면에 표시
                        else if (nowIndex == 21) {
                            Instant endTime = Instant.now();  // 게임 종료 시간
                            long elapsedSeconds = java.time.Duration.between(startTime, endTime).getSeconds();  // 경과 시간 계산
                            JOptionPane.showMessageDialog(frame, "경과 시간: " + elapsedSeconds + " 초");  // 경과 시간을 팝업으로 표시
                            setting();  // 게임을 재설정
                        }
                    }
                }
            });

            num[i] = temp;  // 라벨 배열에 저장
            panel.add(temp);  // 패널에 라벨 추가

            // 라벨의 위치를 랜덤하게 설정
            int x = (int) (Math.random() * 500);
            int y = (int) (Math.random() * 300);
            temp.setLocation(x, y);  // 라벨 위치 설정
            temp.setVisible(true);  // 라벨을 보이게 설정
        }

        frame.add(panel);  // 프레임에 패널 추가
        frame.setVisible(true);  // 프레임을 보이게 설정
    }

    /**
     * 게임을 재설정하는 메서드입니다. 숫자 라벨의 위치를 랜덤하게 바꾸고, 모든 라벨을 보이게 설정합니다.
     */
    public void setting() {
        nowIndex = 0;  // 현재 클릭해야 할 숫자의 인덱스를 0으로 재설정
        // 각 숫자 라벨에 대해
        for (int i = 0; i < num.length; i++) {
            int x = (int) (Math.random() * 300);  // x 좌표를 랜덤하게 설정
            int y = (int) (Math.random() * 300);  // y 좌표를 랜덤하게 설정

            num[i].setLocation(x, y);  // 라벨의 위치를 랜덤한 좌표로 설정
            num[i].setVisible(true);  // 라벨을 보이게 설정
        }
    }
}
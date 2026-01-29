

import javax.swing.*;
import java.awt.*;

public class Introduce extends Exam {
    private JFrame frame;
    public Introduce() {
        frame = new JFrame("1번문제 자기소개"); // 새로운 JFrame 생성
        frame.setSize(800, 600);  // 프레임 크기 설정
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 프레임 닫기 동작 시, 프레임을 메모리에서 제거합니다.
        JPanel panel = new JPanel();  // 패널 생성
        panel.setLayout(new GridLayout(8,2));
        frame.add(panel);  // 프레임에 패널 추가
        frame.setVisible(true);  // 프레임을 보이게 설정
        panel.add(new JLabel("성명"));
        panel.add(new JLabel("우현우"));
        panel.add(new JLabel("학번"));
        panel.add(new JLabel("22114096"));
        panel.add(new JLabel("학과"));
        panel.add(new JLabel("컴퓨터공학전공"));
        panel.add(new JLabel("장래희망"));
        panel.add(new JLabel("디지털포렌식 수사관"));
        panel.add(new JLabel("여름방학 계획"));
        panel.add(new JLabel("차세대 보안리더 프로그램 Best of The Best 교육 이수"));
        panel.add(new JLabel("다음학기 계획"));
        panel.add(new JLabel("Best of The Best 교육 수료"));
        panel.add(new JLabel("좌우명"));
        panel.add(new JLabel("남한테 피해주지 말자"));
        panel.add(new JLabel("내 인생의 멘토"));
        panel.add(new JLabel("사이버보안전공 16학번 박현재 선배님"));

        setSize(800, 600);
    }
}

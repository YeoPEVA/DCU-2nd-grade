

import javax.swing.*;
import java.awt.*;

public class WhatisJava extends Exam{
    private JFrame frame;
    public WhatisJava(){

        frame = new JFrame("5번문제 자바란?"); // 새로운 JFrame 생성
        frame.setSize(800, 600);  // 프레임 크기 설정
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 프레임 닫기 동작 시, 프레임을 메모리에서 제거합니다.
        JPanel panel = new JPanel();  // 패널 생성
        panel.setLayout(new GridLayout(8,2));
        frame.add(panel);  // 프레임에 패널 추가


        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setText("Java는 썬마이크로시스템즈사의 제임스 고슬링과 그의 팀이 개발한 컴퓨터 프로그래밍 언어입니다.\n\n"
                + "1995년 5월, 미국 샌프란시스코에서 열린 '썬 월드95'에서 처음 발표되었습니다.\n\n"
                + "자바의 전신은 '오크(Oak)'라는 프로그래밍 언어로, 냉장고나 밥솥 등의 가전제품에 쓰이는 컴퓨터 칩을 제어할 프로그램을 개발하기 위해 만들었습니다.\n\n"
                + "하지만 중간에 계획이 무산되고, HTML의 정적인 단점을 오크 언어로 극복할 수 있다고 판단하여 오크를 웹에 적용시켰습니다.\n\n"
                + "이후 오크의 장점을 최대로 살린 웹브라우저, 웹러너가 첫 데모에서 성공적인 반응을 얻게 되자 썬은 자바 개발에 매진하고, \n썬 월드 95를 통해 자바를 대중적인 언어로 만들었습니다.\n\n"
                + "자바라는 이름의 기원은 개발자인 'James Gosling', 'Arthur Van Hoff', 'Andy Bechtolsheim'의 이름 첫 글자를 조합했다는 설과\n 개발자들이 자주 마시던 인도네시아산 커피 이름에서 따왔다는 설이 있습니다.\n\n"
                + "Java는 간단하고 객체 지향적인 프로그래밍 언어입니다. \n\n"
                + "웹 애플리케이션, 모바일 애플리케이션, 데스크톱 애플리케이션, 게임 등 다양한 곳에서 사용되며, \n"
                + "특히 안드로이드 앱 개발에 널리 사용됩니다. \n\n"
                + "Java는 가비지 컬렉터를 통해 메모리를 자동을 관리합니다.\n\n"
                + "Java는 멀티쓰레드를 지원합니다. 자바의 멀티쓰레드는 시스템과 관계없이 구현이 가능하며, Java API를 통해 쉽게 구현할 수 있습니다.\n\n"
                + "또한 Java는 높은 이식성을 가지고 있어 서로 다른 실행 환경의 시스템 간에 프로그램을 옮겨 실행할 수 있습니다.\n\n"
                + "Java는 '한 번 작성하면 어디에서나 실행할 수 있다(Write Once, Run Anywhere)'는 특징을 가지고 있습니다.\n\n"
                + "Java는 실행을 위해 자바 가상 머신(JVM)을 거쳐야하므로, 다른 언어에 비해 실행속도가 느립니다.\n\n"
                + "Java는 JVM에서 동작하기 때문에 특정 운영체제에 종속되지 않습니다.\n\n"
                + "Java는 예외 처리가 잘 되어있지만, 개발자가 하나씩 어떻게 처리할 것인지 지정해주어야 합니다.\n\n"
        );
        frame.add(textArea);
        JScrollPane scrollPane = new JScrollPane(textArea);
        frame.add(scrollPane);
        frame.setVisible(true);  // 프레임을 보이게 설정


    }
}

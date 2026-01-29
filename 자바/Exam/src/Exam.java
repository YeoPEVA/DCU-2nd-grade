

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * 자바프로그래밍 기말고사 22114096 우현우
 * 이 클래스는 JFrame을 상속하며, 사용자에게 메뉴를 제공하고 선택에 따라 다양한 기능을 실행합니다.
 */
public class Exam extends JFrame {

    /**
     * Exam 클래스의 생성자입니다.
     * 프레임의 기본 설정을 수행하고 메뉴를 생성합니다.
     */
    public Exam() {
        setTitle("22114096 우현우"); // 프로그램제목 설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 윈도우창 종료 시 프로세스를 깔끔하게 닫기
        createMenu(); //메뉴 생성, 프레임에 삽입
        setSize(800, 600); // 프레임 사이즈
        setVisible(true); // 프레임 출력
        setLocationRelativeTo(null);
    }


    /**
     * 메뉴를 생성하고 프레임에 추가하는 메소드입니다.
     * 각 메뉴 아이템에는 메뉴 액션 리스너가 연결됩니다.
     */
    private void createMenu() {
        JMenuBar menuBar = new JMenuBar();
        MenuActionListener menuListener = new MenuActionListener();

        JMenu one = new JMenu("1번문제");
        JMenuItem oneItem = new JMenuItem("자기소개");
        oneItem.addActionListener(menuListener);
        one.add(oneItem);

        JMenu two = new JMenu("2번 문제");
        JMenuItem twoItem = new JMenuItem("메모장");
        twoItem.addActionListener(menuListener);
        two.add(twoItem);

        JMenu three = new JMenu("3번 문제");
        JMenuItem gameStartItem = new JMenuItem("게임");
        gameStartItem.addActionListener(menuListener);
        three.add(gameStartItem);

        JMenu four = new JMenu("4번 문제");
        JMenuItem calculatorItem = new JMenuItem("계산기");
        calculatorItem.addActionListener(menuListener);
        four.add(calculatorItem);

        JMenu five = new JMenu("5번 문제");
        JMenuItem javaDefinitionItem = new JMenuItem("자바란?");
        javaDefinitionItem.addActionListener(menuListener);
        five.add(javaDefinitionItem);
        //메뉴바에 추가
        menuBar.add(one);
        menuBar.add(two);
        menuBar.add(three);
        menuBar.add(four);
        menuBar.add(five);
        setJMenuBar(menuBar);
    }



    /**
     * 메뉴 아이템 클릭 시 실행되는 액션 리스너입니다.
     * 클릭된 메뉴 아이템의 텍스트에 따라 해당 애플리케이션을 실행합니다.
     */
    private class MenuActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            switch (command) {
                case "자기소개":
                    setVisible(false);
                    new Introduce();
                    break;
                case "메모장":
                    new MemoPad();
                    break;
                case "게임":
                    setVisible(false);
                    new Game();
                    break;
                case "계산기":
                    setVisible(false);
                    new Calculator();
                    break;
                case "자바란?":
                    setVisible(false);
                    new WhatisJava();
                    break;
            }
        }
    }

}
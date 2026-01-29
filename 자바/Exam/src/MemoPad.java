
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.Border;
/**
 * 2번문제 메모장
 * 새로운 파일을 생성하거나, 기존 파일을 열거나 저장하고, 텍스트를 검색하거나 교체하는 기능이 있습니다.
 */
public class MemoPad {

    private JFrame frame; // 애플리케이션의 메인 창이나 프레임입니다.
    private JTextArea textArea; // 사용자가 텍스트를 작성하고 편집할 수 있는 메인 텍스트 영역입니다.
    private JTextArea outputArea; // 검색 및 교체 작업의 결과가 표시되는 출력 영역입니다.
    private JTextField searchField; // 사용자가 검색할 텍스트를 입력하는 텍스트 필드입니다.
    private JTextField replaceField; // 사용자가 교체할 텍스트를 입력하는 텍스트 필드입니다.
    private JButton findButton; // 검색 작업을 시작하는 버튼입니다.
    private JButton replaceButton; // 교체 작업을 시작하는 버튼입니다.
    private JMenuBar menuBar; // 애플리케이션의 메뉴 바입니다.
    private JPanel textPanel; // 메인 텍스트 영역을 포함하는 패널입니다.
    private JPanel buttonPanel; // 버튼 및 텍스트 필드를 포함하는 패널입니다.

    private File currentFile = null; // 현재 편집 중인 파일입니다.
    private String defaultContent = ""; // 새 파일의 기본 내용입니다.
    private int flag = 0;
    private int pos = 0; // 검색한 텍스트가 발견된 위치입니다.
    private int fromIndex = 0; // 검색이 시작되는 인덱스입니다.

    /**
     * MemoPad 클래스의 생성자입니다.
     * 프레임과 그 구성 요소를 설정하기 위해 초기화 메서드를 호출합니다.
     */

    public MemoPad() {

        initialize();

    }
    /**
     * 이 메서드는 프레임과 그 구성 요소를 초기화합니다.
     */
    private void initialize() {
        setupFrame();
        setupTextArea();
        setupMenu();
        setupButtons();
    }
    /**
     * 이 메서드는 애플리케이션의 메인 프레임 또는 창을 설정합니다.
     */

    private void setupFrame() {
        // 새 JFrame를 만들고 그 속성을 설정합니다
        frame = new JFrame("2번문제 메모장");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // 프레임 닫기 동작 시, 프레임을 메모리에서 제거합니다.
        frame.setSize(600, 810);// 메인 프레임의 크기를 설정합니다
        frame.setVisible(true);// 메인 프레임을 화면에 표시합니다
    }
    /**
     * 이 메서드는 사용자가 텍스트를 작성하고 편집할 수 있는 메인 텍스트 영역을 설정합니다.
     */
    private void setupTextArea() {
        // 새 JTextArea를 만들고 그 속성을 설정합니다
        textArea = new JTextArea(defaultContent, 40, 50);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setToolTipText("Enter text here");

        // 텍스트 영역에 경계선을 추가합니다
        Border lineBorder = BorderFactory.createLineBorder(Color.black, 3);
        Border emptyBorder = BorderFactory.createEmptyBorder(7, 7, 7, 7);
        textArea.setBorder(BorderFactory.createCompoundBorder(lineBorder, emptyBorder));

        // 텍스트 영역을 포함하는 패널을 만들고 프레임에 추가합니다
        textPanel = new JPanel();
        textPanel.add(new JScrollPane(textArea));
        frame.getContentPane().add(textPanel, BorderLayout.NORTH);
    }

    /**
     * 이 메서드는 애플리케이션의 메뉴 바를 설정합니다.
     */
    private void setupMenu() {
        // 새 JMenuBar를 만들고 그 속성을 설정합니다
        menuBar = new JMenuBar();

        // 메뉴를 만들고 메뉴 바에 추가합니다
        JMenu fileMenu = createMenu("File", new String[]{"New", "Open", "Save", "Save As", "Close"});
        JMenu editMenu = createMenu("Edit", new String[]{"Find", "Replace"});

        // 메뉴 바에 메뉴를 추가하고 메인 프레임에 메뉴 바를 추가합니다
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        frame.setJMenuBar(menuBar);
    }


    /**
     * 이 메서드는 제목과 메뉴 아이템이 주어지면 JMenu를 생성합니다.
     * @param title 메뉴의 제목입니다.
     * @param items 메뉴에 포함될 메뉴 아이템들의 이름입니다.
     * @return 생성된 JMenu를 반환합니다.
     */
    private JMenu createMenu(String title, String[] items) {
        JMenu menu = new JMenu(title); // 새 JMenu를 만듭니다
        for (String item : items) { // 각 메뉴 아이템을 만들고 메뉴에 추가합니다
            JMenuItem menuItem = new JMenuItem(item);
            menuItem.addActionListener(menuListener);
            menu.add(menuItem);
        }
        return menu; // 완성된 메뉴를 반환합니다
    }

    /**
     * 이 메서드는 버튼 및 텍스트 필드를 설정합니다.
     */
    private void setupButtons() {
        // 새로운 JPanel을 생성합니다.
        buttonPanel = new JPanel();
        // buttonPanel을 프레임의 아래쪽(SOUTH)에 배치합니다.
        frame.getContentPane().add(buttonPanel, BorderLayout.SOUTH);

        // 텍스트 필드를 생성하고 설정합니다.
        searchField = createTextField("Search text here");  // "Search text here"라는 툴팁을 가진 검색 필드를 생성합니다.
        replaceField = createTextField("Enter replacement text here"); // "Enter replacement text here"라는 툴팁을 가진 치환 텍스트 필드를 생성합니다.

        // 버튼을 생성합니다.
        findButton = createButton("Find");  // "Find" 라는 텍스트를 가진 버튼을 생성합니다.
        replaceButton = createButton("Replace");  // "Replace" 라는 텍스트를 가진 버튼을 생성합니다.

        // 결과를 표시할 출력 영역을 설정합니다.
        outputArea = new JTextArea("", 10, 40);
        outputArea.setEditable(false);  // 결과 텍스트 영역은 편집 불가능하도록 설정합니다.
        outputArea.setLineWrap(true);  // 줄바꿈을 설정합니다.
        outputArea.setToolTipText("Display find results here");  // 툴팁을 설정합니다.
        JScrollPane scrollPane = new JScrollPane(outputArea);  // 스크롤 가능한 패널에 결과 텍스트 영역을 넣습니다.

        // 버튼 패널에 위에서 생성한 컴포넌트들을 추가합니다.
        buttonPanel.add(searchField);
        buttonPanel.add(findButton);
        buttonPanel.add(replaceField);
        buttonPanel.add(replaceButton);
        buttonPanel.add(scrollPane);

        // 초기에는 컴포넌트들을 숨깁니다.
        toggleComponents(false);
    }

    /**
     * 텍스트 필드를 생성하는 메소드입니다.
     * @param tooltip 텍스트 필드에 표시될 툴팁입니다.
     * @return 생성된 JTextField를 반환합니다.
     */
    private JTextField createTextField(String tooltip) {
        JTextField textField = new JTextField(20); // 새로운 텍스트 필드를 생성합니다.
        textField.setToolTipText(tooltip); // 툴팁을 설정합니다.
        return textField;  // 텍스트 필드를 반환합니다.
    }

    /**
     * 버튼을 생성하는 메소드입니다.
     * @param text 버튼에 표시될 텍스트입니다.
     * @return 생성된 JButton을 반환합니다.
     */
    private JButton createButton(String text) {
        JButton button = new JButton(text); // 새로운 버튼을 생성합니다.
        button.addActionListener(buttonListener); // 액션 리스너를 추가합니다.
        return button;  // 버튼을 반환합니다.
    }

    // 메뉴의 동작을 처리하는 액션 리스너입니다.
    private ActionListener menuListener = new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();  // 액션 이벤트에서 명령어를 가져옵니다.

            switch (command) {
                case "New":
                    newFile();  // "New"라는 명령어가 들어오면 새 파일을 생성하는 메소드를 실행합니다.
                    break;
                case "Open":
                    openFile();  // "Open"라는 명령어가 들어오면 파일을 열어주는 메소드를 실행합니다.
                    break;
                case "Save":
                    saveFile();  // "Save"라는 명령어가 들어오면 파일을 저장하는 메소드를 실행합니다.
                    break;
                case "Save As":
                    saveAsFile();  // "Save As"라는 명령어가 들어오면 새 이름으로 파일을 저장하는 메소드를 실행합니다.
                    break;
                case "Close":
                    close();  // "Close"라는 명령어가 들어오면 프로그램을 종료하는 메소드를 실행합니다.
                    break;
                case "Find":
                    findText();  // "Find"라는 명령어가 들어오면 텍스트를 찾는 메소드를 실행합니다.
                    break;
                case "Replace":
                    replaceText();  // "Replace"라는 명령어가 들어오면 텍스트를 교체하는 메소드를 실행합니다.
                    break;
            }
        }
    };
    // 버튼의 동작을 처리하는 액션 리스너입니다.
    private ActionListener buttonListener = new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();  // 액션 이벤트에서 명령어를 가져옵니다.

            switch (command) {
                case "Find":
                    findText();  // "Find"라는 명령어가 들어오면 텍스트를 찾는 메소드를 실행합니다.
                    break;
                case "Replace":
                    replaceText();  // "Replace"라는 명령어가 들어오면 텍스트를 교체하는 메소드를 실행합니다.
                    break;
            }
        }
    };

    /**
     * 새 파일을 생성합니다.
     * 이 메소드는 현재 파일 경로를 null로 설정하고, 텍스트 출력 영역을 비웁니다.
     */
    private void newFile() {
        currentFile = null;  // 현재 파일 경로를 null로 설정
        outputArea.setText("");  // 출력 영역의 텍스트를 비움
    }

    /**
     * 사용자가 선택한 파일을 열고 해당 내용을 텍스트 출력 영역에 보여줍니다.
     * 파일을 선택하지 않거나 읽는 중 오류가 발생하면 오류 메시지를 출력합니다.
     */
    private void openFile() {
        JFileChooser fileChooser = new JFileChooser();  // 파일 선택 창 생성
        // 사용자가 파일 선택을 확인하면
        if (fileChooser.showOpenDialog(frame) == JFileChooser.APPROVE_OPTION) {
            currentFile = fileChooser.getSelectedFile();  // 사용자가 선택한 파일 설정
            try {
                FileReader reader = new FileReader(currentFile);  // 파일 읽기
                BufferedReader bufferedReader = new BufferedReader(reader);  // 버퍼 리더를 사용하여 한 번에 한 줄씩 읽기
                outputArea.read(bufferedReader, null);  // 출력 영역에 텍스트 출력
                bufferedReader.close();  // 버퍼 리더 닫기
                outputArea.requestFocus();  // 출력 영역에 포커스 설정
            } catch (IOException ex) {
                // 오류 발생 시 오류 메시지 출력
                JOptionPane.showMessageDialog(null, "An error occurred: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    /**
     * 현재 파일을 저장합니다.
     * 현재 파일이 설정되지 않았으면 '다른 이름으로 저장' 기능을 실행합니다.
     * 파일을 저장하는 동안 오류가 발생하면 오류 메시지를 출력합니다.
     */
    private void saveFile() {
        if (currentFile == null) { // 현재 파일이 설정되지 않았으면 '다른 이름으로 저장' 메소드 호출
            saveAsFile();
        } else {
            try {
                FileWriter writer = new FileWriter(currentFile);  // 파일 쓰기
                BufferedWriter bufferedWriter = new BufferedWriter(writer);  // 버퍼 기반 쓰기
                outputArea.write(bufferedWriter);  // 출력 영역의 텍스트를 파일에 쓰기
                bufferedWriter.close();  // 버퍼 닫기
                outputArea.requestFocus();  // 출력 영역에 포커스 설정
            } catch (IOException ex) {
                // 오류 발생 시 오류 메시지 출력
                JOptionPane.showMessageDialog(null, "An error occurred: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    /**
     * 사용자가 선택한 이름으로 파일을 저장합니다.
     * 파일 선택 창에서 취소 버튼을 클릭하면 이 메소드는 아무 것도 하지 않습니다.
     */
    private void saveAsFile() {
        JFileChooser fileChooser = new JFileChooser();  // 파일 선택 창 생성
        // 사용자가 파일 선택을 확인하면
        if (fileChooser.showSaveDialog(frame) == JFileChooser.APPROVE_OPTION) {
            currentFile = fileChooser.getSelectedFile();  // 사용자가 선택한 파일 설정
            saveFile();  // 파일 저장 메소드 호출
        }
    }

    /**
     * 프로그램을 종료합니다.
     * System.exit(0) 호출로 프로그램을 정상 종료합니다.
     */
    private void close() {
        System.exit(0); // 프로그램 종료
    }
    /**
     * 텍스트 찾기 기능을 실행합니다.
     * 사용자가 입력한 단어를 텍스트 출력 영역에서 찾아 위치를 출력합니다.
     * 단어를 찾지 못하면 단어가 모두 찾아졌음을 알립니다.
     */
    private void findText() {
        String find = searchField.getText();  // 검색할 문자열을 가져옴
        String text = outputArea.getText();  // 출력 영역의 텍스트를 가져옴

        pos = text.indexOf(find, fromIndex);  // 특정 문자열이 시작되는 첫 번째 위치를 반환


        if (pos == -1) { // 찾는 단어가 없을 경우
            pos = 0;  // 위치 초기화
            fromIndex = 0;  // 인덱스 초기화
            pos = text.indexOf(find, fromIndex);  // 처음부터 다시 찾기

            outputArea.append("단어를 모두 찾았습니다. 처음부터 단어를 찾습니다.\n" + find + " 단어의 위치 :: " + pos );  // 찾는 단어가 없을 때 메시지 출력
            outputArea.append("\n");
            fromIndex = pos + find.length();  // 다음 검색을 위해 fromIndex 업데이트
        } else {
            fromIndex = pos + find.length();  // 다음 검색을 위해 fromIndex 업데이트
            outputArea.append(find + " 단어의 위치 :: " + pos );  // 찾는 단어의 위치를 출력
            outputArea.append("\n");
        }
    }
    /**
     * 텍스트 치환 기능을 실행합니다.
     * 사용자가 입력한 단어를 텍스트 출력 영역에서 찾아, 사용자가 지정한 텍스트로 교체합니다.
     * 단어를 찾지 못하면 단어가 모두 치환되었음을 알립니다.
     */
    private void replaceText() {
        String find = searchField.getText();  // 검색할 문자열을 가져옴
        String replace = replaceField.getText();  // 치환할 문자열을 가져옴

        String text = outputArea.getText();  // 출력 영역의 텍스트를 가져옴

        pos = text.indexOf(find, fromIndex);  // 특정 문자열이 시작되는 첫 번째 위치를 반환


        if (pos == -1) { // 찾는 단어가 없을 경우
            pos = 0; // 위치 초기화
            fromIndex = 0;  // 인덱스 초기화
            outputArea.append("마지막 위치까지 단어를 모두 바꾸었습니다. \n아직 남아있다면 바꾸기 버튼을 다시 누르시고, 처음부터 다시 검색하여 바꿉니다.\n");
            outputArea.append("\n");
        } else {
            fromIndex = pos + find.length();  // 다음 검색을 위해 fromIndex 업데이트
            outputArea.replaceRange(replace, pos, pos+find.length());  // 찾은 단어를 사용자가 지정한 문자열로 치환
            outputArea.append(find + " 단어의 위치 :: " + pos );  // 치환된 단어의 위치를 출력
            outputArea.append("\n");
        }
    }
    /**
     * 지정된 표시 상태에 따라 컴포넌트의 표시 여부를 전환합니다.
     * @param isVisible 컴포넌트를 표시할지 여부를 지정하는 boolean 값입니다.
     */
    private void toggleComponents(boolean isVisible) {
        searchField.setVisible(isVisible);  // 검색 필드의 표시 상태 설정
        findButton.setVisible(isVisible);  // 찾기 버튼의 표시 상태 설정
        replaceField.setVisible(isVisible);  // 치환 필드의 표시 상태 설정
        replaceButton.setVisible(isVisible);  // 치환 버튼의 표시 상태 설정
        outputArea.setVisible(isVisible);  // 출력 영역의 표시 상태 설정
    }
}

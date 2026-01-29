import java.io.*;
import java.util.Scanner;
import java.util.Vector;
import java.util.Random;

public class test4 {
    public static void main(String[] args){
        // words.txt 파일 읽고
        // 사용자 모르게 영어 단어 하나 선택
        // 몇 개의 글자를 숨겨서 화면에 출력 -> 2개의 글자만

        Vector<String> wordVector = new Vector<String>();
        Scanner scannerInput = new Scanner(System.in);
        int count = 0;
        int answerWordSize = 0;
        int answer = 0;
        String answerWord = "";
        String showWord = "";
        String userIn;
        char[] answerArray = new char[2];

        try {
            Scanner scanner = new Scanner(new FileReader("/Users/yeopeva-mac/Desktop/DCU(대학교)/2-1 활동 내용/java/9-week/test/words.txt"));
            while (scanner.hasNext()) {
                String word = scanner.nextLine();
                wordVector.add(word);
            }
            scanner.close();
        }catch (Exception e){
            System.out.println(e);
        }
        answerWordSize = wordVector.size();

        System.out.println("지금부터 행맨 게임을 시작합니다.");

        while(true){
            if(count == 0) {
                Random random = new Random();
                answerWord = wordVector.elementAt(random.nextInt(answerWordSize - 1));
                // System.out.println(answerWord);

                // 글자 숨기기
                showWord = answerWord;

                // 글자 2개 이하인 경우
                if (showWord.length() == 2) {
                    char []chars = showWord.toCharArray();
                    answerArray[0] = chars[0];
                    answerArray[1] = chars[1];
                    showWord = "--";
                } else if (showWord.length() == 1) {
                    char []chars = showWord.toCharArray();
                    showWord = "-";
                    answerArray[0] = chars[0];
                    answer += 1;
                } else {
                    char []chars = showWord.toCharArray();

                    answerArray[0] = chars[1];
                    answerArray[1] = chars[showWord.length()-1];

                    chars[1] = '-';
                    chars[showWord.length()-1] = '-';

                    showWord = String.valueOf(chars);
                }
            }

            System.out.println(showWord);
            System.out.print(">>");
            userIn = scannerInput.next();

            char userInAnswer = userIn.charAt(0);
            // System.out.println(answerArray[0]);
            // System.out.println(answerArray[1]);

            // 코드 체크
            if(userInAnswer == answerArray[0]){
                if(showWord.length() <= 2){
                    char []chars = showWord.toCharArray();
                    chars[0] = answerArray[0];
                    showWord = String.valueOf(chars);;
                }else{
                    char []chars = showWord.toCharArray();
                    chars[1] = answerArray[0];
                    showWord = String.valueOf(chars);
                }
                answer += 1;
            } else if (userInAnswer == answerArray[1]) {
                if(showWord.length() == 2){
                    char []chars = showWord.toCharArray();
                    chars[1] = answerArray[1];
                    showWord = String.valueOf(chars);
                }else{
                    char [] chars = showWord.toCharArray();
                    chars[showWord.length()-1] = answerArray[1];
                    showWord = String.valueOf(chars);
                }
                answer += 1;
            }
            count += 1;

            // 5번 실패 혹은 정답인 경우
            if(count == 4 || answer == 2){
                count = 0;
                System.out.println(answerWord);
                System.out.print("Next(y/n)?");
                userIn = scannerInput.next();

                if(userIn.equals("n")){
                    scannerInput.close();
                    break;
                }
            }
        }
        scannerInput.close();
    }

}

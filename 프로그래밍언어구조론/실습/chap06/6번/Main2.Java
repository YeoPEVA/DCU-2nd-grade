import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        System.out.println("2024-11-26, 학번 : 20118669, 이창엽");
        Scanner scanner = new Scanner(System.in);
        System.out.print("점수를 입력하세요 (0-100): ");
        int score = scanner.nextInt();
        char grade;

        if(score > 100 || score < 0){
            System.out.println("점수 범위를 벗어났습니다.");
        }else{
            switch (score / 10) {
                case 10:
                case 9:
                    grade = 'A';
                    break;
                case 8:
                    grade = 'B';
                    break;
                case 7:
                    grade = 'C';
                    break;
                case 6:
                    grade = 'D';
                    break;
                default:
                    grade = 'F';
            }
            System.out.println("학점: " + grade);
        }
    }
}

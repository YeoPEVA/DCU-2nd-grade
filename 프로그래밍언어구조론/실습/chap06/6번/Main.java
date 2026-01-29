import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("2024-11-26, 학번 : 20118669, 이창엽");
        Scanner scanner = new Scanner(System.in);
        System.out.print("점수를 입력하세요 (0-100): ");
        int score = scanner.nextInt();
        char grade;

        if(score > 100 || score < 0){
            System.out.println("점수 범위를 벗어났습니다.");
        }else{
            if (score >= 90 && score <= 100)
            grade = 'A';
            else if (score >= 80)
                grade = 'B';
            else if (score >= 70)
                grade = 'C';
            else if (score >= 60)
                grade = 'D';
            else
                grade = 'F';
            System.out.println("학점: " + grade);
        }
    }
}

package chap02;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args){
        // 입력을 위한 스캐너 객체 생성  
        Scanner sc = new Scanner(System.in);

        // 출력문 
        System.out.println("2024-09-24, 학번:20117669, 이름:이창엽");
        
        // 변수 선언 
        int n;
        
        // 출력문 - 정수 입력 안내 
        System.out.println("정수 n을 입력하세요>> ");

        // 입력문 
        n = sc.nextInt();

        // 변수 선언
        int sum = 0;

        // 반복문 
        for (int i = 1; i <=n; i++)
            sum += i;

        // 출력문 - 결과 값 출력 
        System.out.println("1부터" + n + "까지 합 = " + sum);
    }
}
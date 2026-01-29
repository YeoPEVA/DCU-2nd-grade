import java.util.Scanner;
import java.util.StringTokenizer;

public class test2{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String input;

        while(true){
            input = scanner.nextLine();

            if(input.equals("그만")){
                System.out.println("종료합니다...");
                break;
            }

            StringTokenizer a = new StringTokenizer(input);

            System.out.println("어절 개수는 " + a.countTokens());
        }


        scanner.close();
    }
}

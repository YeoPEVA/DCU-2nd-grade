import java.util.Scanner;
import java.util.StringTokenizer;

public class test3{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String input;

        while(true){
            input = scanner.nextLine();

            if(input.equals("그만")){
                System.out.println("종료합니다...");
                break;
            }

            String []data = input.split(" ");

            System.out.println("어절 개수는 " + data.length);
        }


        scanner.close();
    }
}

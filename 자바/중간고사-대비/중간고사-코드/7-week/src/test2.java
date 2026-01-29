import java.util.*;

public class test2{
    public static void print(Vector<Integer> v){
        int result = 0;

        for (int i = 0; i < v.size(); i++){
            System.out.print(v.get(i) + " ");
            result += v.get(i);
        }
        System.out.println();

        result = result / v.size();

        System.out.println("현재 평균 "+ result);

    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int userInput;

        Vector<Integer> v = new Vector();

        while(true){
            System.out.print("강수량 입력 (0 입력시 종료)>> ");
            userInput = scanner.nextInt();
            if(userInput == 0) break;
            v.add(userInput);
            print(v);
        }
        scanner.close();
    }
}

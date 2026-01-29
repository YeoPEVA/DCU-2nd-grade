import java.util.*;

public class test1{
    public static void printBig(Vector<Integer> v){
        int result = 0;

        for (int i = 0; i < v.size(); i++){
            if(v.get(i) > result){
                result = v.get(i);
            }
        }

        System.out.println("가장 큰 수는 "+ result);
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int userInput;

        Vector<Integer> v = new Vector();
        System.out.print("정수(-1이 입력될 때까지)>> ");

        while(true){
            userInput = scanner.nextInt();
            if(userInput == -1) break;
            v.add(userInput);
        }

        printBig(v);

        scanner.close();
    }
}

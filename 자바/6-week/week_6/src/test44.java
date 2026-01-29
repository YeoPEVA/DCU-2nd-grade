import java.util.Scanner;

public class test44 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = "";
        input = scanner.nextLine();
        int inputLen = input.length();

        for(int j = 0; j < inputLen; j++) {
            String first = input.substring(0, 1);
            String last = input.substring(1);
            input = last + first;
            System.out.println(input);
        }
    }
}

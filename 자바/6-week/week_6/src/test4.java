import java.util.Scanner;

public class test4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = "";
        input = scanner.nextLine();
        char[] chars = input.toCharArray();

        for(int j = 0; j < chars.length; j++) {
            char temp = chars[chars.length - 1];
            chars[chars.length - 1] = chars[0];

            for (int i = 0; i < chars.length - 1; i++) {
                chars[i] = chars[i + 1];
            }
            chars[chars.length - 2] = temp;
            System.out.println(chars);
        }
    }
}

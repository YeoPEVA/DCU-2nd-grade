import java.util.Scanner;
import java.util.InputMismatchException;

public class exam6_test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = 0, m = 0;
        boolean isGoodInput = false;

        while(!isGoodInput) {
            try {
                n = scanner.nextInt();
                m = scanner.nextInt();
                isGoodInput = true;
            } catch (InputMismatchException e) {
                System.out.println("-1");
                scanner.nextLine();
            }
        }
        System.out.print(n * m);
        scanner.close();
    }

}

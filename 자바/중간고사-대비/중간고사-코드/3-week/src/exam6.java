import java.util.Scanner;
import java.util.InputMismatchException;

public class exam6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int m;

        while(true) {
            try {
                n = scanner.nextInt();
                m = scanner.nextInt();
            }
            catch(InputMismatchException e){
                System.out.println("-1");
                scanner.nextLine();
                continue;
            }

            if(n <= 0 || m <= 0 ){
                System.out.println("-1");
            }else{
                System.out.print(n*m);
                break;
            }
        }
        scanner.close();
    }
}

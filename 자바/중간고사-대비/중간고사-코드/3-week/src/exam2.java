import java.util.Scanner;

public class exam2 {
    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);
        int x1;
        int count = 0;

        // x1, y1
        while(true){
            x1 = scanner.nextInt();

            if(x1 <= 18 && x1 >= 1){
                break;
            }else{
                System.out.println("-1");
            }
        }

        for(int i=0; i < x1; i++){
            for(int j=0; j < x1-count; j++){
                System.out.print("*");
            }
            count += 1;
            if(count != x1){
                System.out.print("\n");
            }
        }

        scanner.close();
    }
}

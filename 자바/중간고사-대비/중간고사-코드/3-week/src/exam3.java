import java.util.Scanner;

public class exam3 {
    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);
        String x1;
        char c;

        int count = 0;
        int count2 = 0;
        // 97 ~ 122

        while(true){
            x1 = scanner.next();
            c = x1.charAt(0);

            if((int) c <= 122 && (int) c >= 97){
                break;
            }else{
                System.out.println("-1");
            }
        }


        for(int i=96; i < c; i++){
            for(int j=96; j < c - count; j++){
                System.out.print((char) (97 + count2));
                count2 += 1;
            }
            if(i  == c-1){
                break;
            }
            System.out.print("\n");
            count2 = 0;
            count += 1;
        }
        scanner.close();
    }
}

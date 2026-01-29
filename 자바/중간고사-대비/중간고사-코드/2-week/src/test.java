import java.util.Scanner;

public class test {
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int tmp = 0;

        tmp = a+b;

        if(tmp > c){
            tmp = a + c;
            if(tmp > b){
                tmp = b + c;
                if(tmp > a){
                    System.out.println("True");
                }else{
                    System.out.println("False");
                }
            }else{
                System.out.println("False");
            }
        }else{
            System.out.println("False");
        }

        scanner.close();
    }

}

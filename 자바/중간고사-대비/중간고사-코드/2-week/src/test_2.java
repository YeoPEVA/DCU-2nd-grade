import java.util.Scanner;

public class test_2 {
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        float a = scanner.nextFloat();
        String b = scanner.next();
        float c = scanner.nextFloat();

        if(b.equals("+")){
            System.out.printf(a + " + " + c + " = " + (a+c));
        }else if(b.equals("-")){
            System.out.printf(a + " - " + c + " = "  + (a-c));
        }else if(b.equals("*")){
            System.out.printf(a + " * " + c + " = " + (a*c));
        }else if(b.equals("/")){
            if(c == 0.0){
                System.out.printf("False");
            }else{
                System.out.printf(a + " / " + c + " = " + (a/c));
            }
        }

        scanner.close();
    }
}

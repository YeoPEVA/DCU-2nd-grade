import java.util.Scanner;

public class test_3 {
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int coin = 0;

        if(a >= 50000){
            coin = a / 50000;
            a = a % 50000;
            if(coin > 1){
                System.out.println(coin + " 50,000won bill(s)");
            }else {
                System.out.println(coin + " 50,000won bill");
            }
        }

        if(a >= 10000){
            coin = a / 10000;
            a = a % 10000;

            if(coin > 1){
                System.out.println(coin + " 10,000won bill(s)");
            }else {
                System.out.println(coin + " 10,000won bill");
            }
        }

        if(a >= 1000){
            coin = a / 1000;
            a = a % 1000;

            if(coin > 1){
                System.out.println(coin + " 1,000won bill(s)");
            }else {
                System.out.println(coin + " 1,000won bill");
            }
        }

        if(a >= 500){
            coin = a / 500;
            a = a % 500;

            if(coin > 1){
                System.out.println(coin + " 500won coin(s)");
            }else {
                System.out.println(coin + " 500won coin");
            }
        }

        if(a >= 100){
            coin = a / 100;
            a = a % 100;

            if(coin > 1){
                System.out.println(coin + " 100won coin(s)");
            }else {
                System.out.println(coin + " 100won coin");
            }
        }

        if(a >= 50){
            coin = a / 50;
            a = a % 50;

            if(coin > 1){
                System.out.println(coin + " 50won coin(s)");
            }else {
                System.out.println(coin + " 50won coin");
            }
        }

        if(a >= 10){
            coin = a / 10;
            a = a % 10;

            if(coin > 1){
                System.out.println(coin + " 10won coin(s)");
            }else {
                System.out.println(coin + " 10won coin");
            }
        }

        if(a != 0){
            if(a < 10){
                coin = a / 1;
                a = a % 1;

                if(coin > 1){
                    System.out.print(coin + " 1won coin(s)");
                }else {
                    System.out.print(coin + " 1won coin");
                }
            }
        }

        scanner.close();
    }
}

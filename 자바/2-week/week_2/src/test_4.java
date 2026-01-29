import java.util.Scanner;

public class test_4 {
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        // x1, y1
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();

        // x2, y2
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();

        // x1이 100과 같거나 커야하며, x1이 200과 같거나 작은 경우
        // y1이 100과 같거나 커야하며, y1이 200과 같거나 작은 경우
        if ((x1>=100 & x1<=200) && (y1>=100 && y1<=200)) {
            System.out.println("True");
            // x2이 100과 같거나 커야하며, x1이 200과 같거나 작은 경우
            // y1이 100과 같거나 커야하며, y2이 200과 같거나 작은 경우
        }else if((x2>=100 && x2<200) && (y2>=100 && y2<=200)) {
            System.out.println("True");
            // x1이 100과 같거나 작아야하며, x2이 200과 같거나 커야함
            // y1이 100과 같거나 작야아하며, y2이 200과 같거나 커야함
        }else if(x1<=100 && x2>=200 && y1<=100 && y2>=200) {
            System.out.println("True");
        }else{
            System.out.println("False");
        }

        scanner.close();
    }
}

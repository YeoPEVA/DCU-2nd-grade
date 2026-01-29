import java.util.Scanner;

public class chapter2 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int x1=s.nextInt();
        int y1=s.nextInt();
        int x2=s.nextInt();
        int y2=s.nextInt();

        //
        if ((x1>=100 & x1<=200) && (y1>=100 && y1<=200)) {
            System.out.println("True");
        }else if((x2>=100 && x2<200) && (y2>=100 && y2<=200)) {
            System.out.println("True");
        }else if(x1<=100 && x2>=200 && y1<=100 && y2>=200) {
            System.out.println("True");
        }
        else
            System.out.println("False");
        s.close();
    }
}

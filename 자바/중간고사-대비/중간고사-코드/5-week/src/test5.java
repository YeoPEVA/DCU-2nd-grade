import java.util.Scanner;

public class test5 {
    public static void main (String args[]) {

        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        int y=  scanner.nextInt();
        String calcType = scanner.next();
        int result = 0;

        if(calcType.equals("+")){
            Add a = new Add();
            a.setValue(x,y);
            result = a.calculate();
            System.out.println(result);
        } else if (calcType.equals("*")) {
            Mul m = new Mul();
            m.setValue(x,y);
            result = m.calculate();
            System.out.println(result);
        } else if(calcType.equals("-")){
            Sub s = new Sub();
            s.setValue(x,y);
            result = s.calculate();
            System.out.println(result);
        } else if(calcType.equals("/")){
            if(y == 0){
                System.out.println("계산할 수 없습니다.");
            }else {
                Div d = new Div();
                d.setValue(x, y);
                result = d.calculate();
                System.out.println(result);
            }
        } else{
          System.out.println("잘못된 연산자입니다.");
        }


        // Add code here...
        scanner.close();
    }
}
abstract class Calc { // 추상 클래스
    public abstract void setValue(int a, int b);
    public abstract int calculate();

    // Add code here...
}
class Add extends Calc {
    int a;
    int b;
    public void setValue(int a, int b){
        this.a = a;
        this.b = b;
    }
    public int calculate(){
        return a + b;
    }

}
class Mul extends Calc {
    int a;
    int b;
    public void setValue(int a, int b){
        this.a = a;
        this.b = b;
    }
    public int calculate(){
        return a * b;
    }
}
class Sub extends Calc {
    int a;
    int b;
    public void setValue(int a, int b){
        this.a = a;
        this.b = b;
    }
    public int calculate(){
        return a - b;
    }
}
class Div extends Calc {
    int a;
    int b;
    public void setValue(int a, int b){
        this.a = a;
        this.b = b;
    }
    public int calculate(){
        return a / b;
    }
}

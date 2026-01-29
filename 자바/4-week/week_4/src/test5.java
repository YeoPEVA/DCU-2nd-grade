import java.util.Scanner;

public class test5{
    public static void main(String [] arg){
        Scanner scanner = new Scanner(System.in);

        int a,b;
        int result;
        String calculateType;

        a = scanner.nextInt();
        b = scanner.nextInt();
        calculateType = scanner.next();

        if(calculateType.equals("+")) {
            Add calcu_add;
            calcu_add = new Add();
            calcu_add.setValue(a,b);
            result = calcu_add.calculate();
            System.out.println(result);

        }else if(calculateType.equals("-")){
            Sub calcu_sub;
            calcu_sub = new Sub();
            calcu_sub.setValue(a,b);
            result = calcu_sub.calculate();
            System.out.println(result);

        }else if(calculateType.equals("*")){
            Mul calcu_mul;
            calcu_mul = new Mul();
            calcu_mul.setValue(a,b);
            result = calcu_mul.calculate();
            System.out.println(result);

        }else if(calculateType.equals("/")){
            if(b == 0) {
                System.out.println("0으로 나눌 수 없습니다.");

            }else{
                Div calcu_div;
                calcu_div = new Div();
                calcu_div.setValue(a,b);
                result = calcu_div.calculate();
                System.out.println(result);
            }
        }else{
            System.out.println("해당하는 연산이 없습니다.");
        }
    }
}

class Add{
    int a, b;
    void setValue(int a, int b) {
        this.a = a;
        this.b = b;
    }
    int calculate() {
        return this.a + this.b;
    }
}

class Sub{
    int a, b;
    void setValue(int a, int b) {
        this.a = a;
        this.b = b;
    }
    int calculate() {
        return this.a - this.b;
    }
}

class Mul{
    int a, b;
    void setValue(int a, int b) {
        this.a = a;
        this.b = b;
    }
    int calculate() {
        return this.a * this.b;
    }
}

class Div{
    int a, b;
    void setValue(int a, int b) {
        this.a = a;
        this.b = b;
    }
    int calculate() {
        return this.a / this.b;
    }
}

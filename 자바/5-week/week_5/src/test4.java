import java.util.Scanner;

public class test4 {
    public static void main(String[] args) {
        StackApp.run();
    }
}
interface Stack {
    int length(); // 현재 스택에 저장된 개수 리턴
    int capacity(); // 스택의 전체 저장 가능한 개수 리턴
    String pop(); // 스택의 톱(top)에 저장된 실수 리턴
    boolean push(String val); // 스택의 톱(top)에 실수 저장
}
class StringStack implements Stack {
    int top;
    int size;
    int count;

    String [] stackInput;

    public StringStack(int size){
        this.size = size;
        this.top = -1;
        this.count = 0;
        stackInput = new String[size];
    }

    @Override
    public int length()
    {
        return this.count;
    }

    @Override
    public int capacity()
    {
        return this.size - this.count;
    }

    @Override
    public String pop()
    {
        String val = stackInput[top];
        stackInput[top--] = "";
        return val;
    }

    @Override
    public boolean push(String val)
    {
        if(this.capacity() == 0 ){
            return false;
        }else{
            // System.out.println(this.capacity());
            stackInput[++top] = val;
            count++;
            return true;
        }
    }
}
class StackApp {
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        StringStack s = new StringStack(size);

        while (true){
            String user_input = scanner.next();
            if(user_input.equals("그만")){
                break;
            }
            if(!s.push(user_input)){
                System.out.println("스택이 꽉 차서 푸시 불가!");
            }
        }

        System.out.print("스택에 저장된 모든 문자열 팝 : ");

        for (int i =0; i < size; i ++){
            System.out.print(s.pop() + " ");
        }
        scanner.close();
    }
}

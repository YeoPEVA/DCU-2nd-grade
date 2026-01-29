package chap05.part1;
public class Hello{
    public static int sum(int i, int j){
        return i + j;
    }

    public static void main(String[] args){
        int i;
        int j;
        char a;
        String b;
        final int TEN = 10;

        i = 1;
        j = sum(i, TEN);
        a = '?';
        b = "Hello";

        java.lang.System.out.println("2024-11-05, 학번:20117669, 이름:이창엽");
        java.lang.System.out.println(a);
        System.out.println(b);
        System.out.println(TEN);
        System.out.println(j);
    }
}
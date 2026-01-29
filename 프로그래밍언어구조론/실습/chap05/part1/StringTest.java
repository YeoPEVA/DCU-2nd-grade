package chap05.part1;
public class StringTest{
    public static void main(String[] args){
        java.lang.System.out.println("2024-11-05, 학번:20117669, 이름:이창엽");
        String str1 = "아! 대한민국 ";
        String str2 = new String("Korea");

        System.out.println(str1 + str2);
        int a= 1000;
        int b= 2000;

        System.out.println(str1+a+b+"리 금수강산");
        System.out.println(str1+(a+b)+"리 금수강산");
    }
}
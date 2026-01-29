import java.util.Scanner;

public class test4{
    public static void main(String [] arg) {
        DicApp.run();
    }
}
class Dictionary {
    private static String [] kor = {"사랑", "아기", "돈", "미래", "희망" };
    private static String [] eng = {"love", "baby", "money", "future", "hope"};
    public static String kor2Eng(String word) {
        for(int i = 0; i < Dictionary.kor.length; i++){
            if(kor[i].equals(word)){
                return eng[i];
            }
        }
        return word;
    }
}
class DicApp{
    public static void run() {
        System.out.println("한영 단어 검색 프로그램입니다.");
        Scanner scanner = new Scanner(System.in);
        String input;
        String result;

        while(true) {
            input = scanner.nextLine();
            result = Dictionary.kor2Eng(input);

            if(input.equals("그만")){
                break;
            }
            if (input.equals(result)) {
                System.out.println(result + " : " + "저의 사전에 없습니다.");
            } else {
                System.out.println(input + " : " + result);
            }
        }
        scanner.close();
    }
}

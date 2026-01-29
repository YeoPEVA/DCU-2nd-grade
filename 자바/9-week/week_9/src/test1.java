import java.io.*;
import java.nio.charset.StandardCharsets;

public class test1 {
    public static void main(String[] args){
        InputStreamReader in = null;
        FileInputStream fin = null;

        try{
            fin = new FileInputStream("/Users/yeopeva-mac/Desktop/DCU(대학교)/2-1 활동 내용/java/9-week/test/hangul.txt");
            in = new InputStreamReader(fin, StandardCharsets.UTF_8);

            int c;

            System.out.println("인코딩 문자 집합은 " +in.getEncoding());
            while ((c=in.read()) != -1){
                System.out.print((char)c);
            }
            in.close();
            fin.close();
        }catch (IOException e){
            System.out.println(e);
            System.out.println("입출력 오류");
        }
    }
}

import java.io.*;
import java.util.Scanner;

public class test2 {
    public static void main(String[] args){
        FileReader fin = null;
        int c;

        try{
            fin = new FileReader("/Users/yeopeva-mac/Desktop/DCU(대학교)/2-1 활동 내용/java/9-week/test/test2.txt");
            BufferedOutputStream out = new  BufferedOutputStream(System.out, 5);

            while((c = fin.read()) != -1){
                out.write(c);
            }

            // 파일 데이터 모두 출력된 상태
            new Scanner(System.in).nextLine();
            out.flush();
            fin.close();
            out.close();
        }catch (IOException e){
            // System.out.println(e);
            e.printStackTrace();
        }
    }
}

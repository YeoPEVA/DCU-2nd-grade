import java.util.Scanner;

public class test2 {
    public static void main(String [] arg) {
        int x, y, w, h;
        Scanner scanner = new Scanner(System.in);
        Rectangle t = new Rectangle(1, 1, 10, 10);
        x = scanner.nextInt();
        y = scanner.nextInt();
        w = scanner.nextInt();
        h = scanner.nextInt();
        Rectangle r = new Rectangle(x, y, w, h);
        x = scanner.nextInt();
        y = scanner.nextInt();
        w = scanner.nextInt();
        h = scanner.nextInt();
        Rectangle s = new Rectangle(x, y, w, h);
        r.show();
        System.out.println("s의 면적은 " + s.square());
        if(t.contains(r)) System.out.println("t는 r을 포함합니다.");
        if(t.contains(s)) System.out.println("t는 s를 포함합니다.");
    }
}
class Rectangle {
    int rectangleX;
    int rectangleY;
    int rectangleW;
    int rectangleh;

    public boolean contains(Rectangle r) {
        // 2개 사각형 비교 / 현재 사각형이 주어진 사각형을 포함하는지를 판단
        // 현재 사각형의 왼쪽 변의 x 좌표가 주어진 사각형의 왼쪽 변의 x 좌표보다 작은지를 확인합니다. / 현재 사각형의 상단 변의 y 좌표가 주어진 사각형의 상단 변의 y 좌표보다 작은지를 확인합니다.
        if((this.rectangleX <r.rectangleX) && (this.rectangleY<r.rectangleY)
                // 현재 사각형의 오른쪽 변의 x 좌표가 주어진 사각형의 오른쪽 변의 x 좌표보다 큰지를 확인합니다. / 현재 사각형의 하단 변의 y 좌표가 주어진 사각형의 하단 변의 y 좌표보다 큰지를 확인합니다.
                && (this.rectangleX+this.rectangleW)>(r.rectangleX+r.rectangleW) && (this.rectangleY+this.rectangleh)>(r.rectangleY+r.rectangleh))
            return true;
        else
            return false;
    }

    public void show(){
        System.out.println("(" + this.rectangleX + "," + this.rectangleY + ")에서 크기가 " + rectangleW + "x" + rectangleh + "인 사각형");
    }
    public int square(){
        return this.rectangleW * this.rectangleh;
    }

    public Rectangle(int x, int y, int w, int h){
        this.rectangleX = x;
        this.rectangleY = y;
        this.rectangleW = w;
        this.rectangleh = h;
    }

}

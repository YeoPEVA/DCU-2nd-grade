import java.util.Scanner;
import java.util.Vector;

abstract class Shape{
    public abstract void draw();
}

class Line extends Shape {
    public void draw() {
        System.out.println("Line");
    }
}
class Rect extends Shape {
    public void draw() {
        System.out.println("Rect");
    }
}
class Circle extends Shape {
    public void draw() {
        System.out.println("Circle");
    }
}

public class Main{
    static class GraphicEditor {
        Scanner scanner = new Scanner(System.in);
        Vector<Shape> v = new Vector<Shape>();

        public void insert(int shape) {
            Shape s;

            switch (shape) {
                case 1:
                    s = new Line();
                    v.add(s);
                    break;
                case 2:
                    s = new Rect();
                    v.add(s);
                    break;
                case 3:
                    s = new Circle();
                    v.add(s);
                    break;
                default:
                    break;
            }
        }

        public void delete(int target) {
            if (target <= 0 || target >= v.size() + 1) {
                System.out.println("삭제할 수 없습니다.");
                return;
            }
            v.remove(target - 1);
        }

        public void print() {
            for (int i = 0; i < v.size(); i++) {
                Shape s = v.get(i);
                s.draw();
            }
        }

        public void run() {
            while (true) {
                System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
                int n;
                try {
                    n = scanner.nextInt();
                }catch (Exception e){
                    scanner.nextLine();
                    continue;
                    // n = scanner.nextInt();
                }

                switch (n) {
                    case 1:
                        System.out.print("Line(1), Rect(2), Circle(3)>>");
                        int shape = scanner.nextInt();
                        insert(shape);
                        break;
                    case 2:
                        System.out.print("삭제할 도형의 위치>>");
                        int target = scanner.nextInt();
                        delete(target);
                        break;
                    case 3:
                        print();
                        break;
                    case 4:
                        System.out.print("프로그램종료");
                        scanner.close();
                        return;
                    default:
                        break;
                }
            }
        }
    }

    public static void main(String [] args) {
        GraphicEditor ge = new GraphicEditor();
        ge.run();
    }
}





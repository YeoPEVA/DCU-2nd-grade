import java.util.Scanner;

public class test2
{
    public static void main(String[] args) {
        Km2Mile toMile = new Km2Mile(1.6);
        toMile.run();
    }
}
abstract class Converter {
    abstract protected double convert(double src);
    abstract protected String getDestString();
    protected double ratio;
    public void run() {
        Scanner scanner = new Scanner(System.in);
        double val = scanner.nextDouble();
        double res = convert(val);
        System.out.println("변환 결과: " + res + getDestString() + "입니다.");
        scanner.close();
    }
}

class Km2Mile extends Converter{
    double src;
    Km2Mile(double src){
        this.src = src;
    }

    @Override
    protected double convert(double src) {
        ratio = src * 0.625;
        return ratio;
    }

    @Override
    protected String getDestString() {
        return "Mile";
    }

    @Override
    public void run() {
        super.run();
    }
}

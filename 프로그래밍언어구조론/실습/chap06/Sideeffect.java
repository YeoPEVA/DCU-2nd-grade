public class Sideeffect {
    
    static int x = 10;

    public static int func(){
        x = 20;
        return 30;
    }

    public static void main(String[] args){
        System.out.println("2024-11-19, 학번 : 20117669, 이창엽");
        System.out.println("x + func() = " + (x + func()));
        System.out.println("func() + x ="+ (func() + x));
    }
}

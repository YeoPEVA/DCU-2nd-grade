public class exam4 {
    public static void main(String[] arg) {

        for (int i = 1; i <= 99; i++) {
            if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9 || (i >=30 && i <= 39) || (i>=60 && i<=69) || (i>=90 && i<=99)) {
                System.out.print(i + " jjak");

                if(i == 33 || i == 36 || i == 39 || i == 63 || i == 66 || i == 69 || i == 93 || i == 96 || i == 99){
                    System.out.print("jjak");
                }
                if(i > 98){
                    break;
                }
                System.out.print("\n");
            }
        }
    }
}

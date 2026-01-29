import java.util.Scanner;

public class exam5 {
    public static void main(String[] arg) {
        Scanner scanner = new Scanner(System.in);
        String userInput;
        String course[] = {"Java","C++","HTML5","ComputerStructure","Android"};

        int count = 0;
        int isStringHere = 0;
        int score[] = {95, 88, 76, 62, 55};

        while(true) {
            userInput = scanner.next();

            for (String course_t : course) {
                if (course_t.equals(userInput)) {
                    System.out.println(course_t + " : " + score[count]);
                    isStringHere = 1;
                    break;
                }
                count += 1;
            }
            count = 0;

            if(userInput.equals("-1")){
                scanner.close();
                break;
            }

            if (isStringHere != 1) {
                System.out.println("N/A");
            }

            isStringHere = 0;

        }

    }
}

import java.util.Scanner;

public class test5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input;
        String command;

        input = scanner.nextLine();
        StringBuffer inputBuffer = new StringBuffer(input);

        while(true){
            System.out.print("명령: ");
            command = scanner.next();

            if(command.equals("그만")){
                System.out.println("종료합니다.");
                break;
            }

            String tokens[] = command.split("!");

            if(tokens.length != 2){
                System.out.println("잘못된 명령입니다!");
            }else{
                if(tokens[0].length() == 0 || tokens[1].length() == 0){
                    System.out.println("잘못된 명령입니다!");
                    continue;
                }

                int index = inputBuffer.indexOf(tokens[0]);

                if(index == -1){
                    System.out.println("찾을 수 없습니다!");
                    continue;
                }

                inputBuffer.replace(index, index+tokens[0].length(), tokens[1]);
                System.out.println(inputBuffer.toString());
            }

        }

        scanner.close();
    }
}


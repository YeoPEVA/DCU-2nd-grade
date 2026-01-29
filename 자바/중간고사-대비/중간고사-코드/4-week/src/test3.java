import java.util.Scanner;

public class test3{
    public static void main(String [] arg) {
        PhoneBook phonebook = new PhoneBook();
        phonebook.run();
    }
}
class Phone {
    String phoneName;
    String phoneNumber;

    Phone(String phoneName, String phoneNumber){
        this.phoneName = phoneName;
        this.phoneNumber = phoneNumber;
    }
}


class PhoneBook {
    Phone[] phones;

    Scanner scanner = new Scanner(System.in);

    PhoneBook() {
        int phonePerson = 0;

        while(true){
            phonePerson = scanner.nextInt();
            scanner.nextLine();

            if(phonePerson > 0){
                break;
            }
        }

        phones = new Phone[phonePerson];


        for(int i = 0; i < phones.length; i++){
            String name = scanner.next();
            String number = scanner.next();
            phones[i] = new Phone(name, number);
        }

        System.out.println("저장되었습니다...");
        scanner.nextLine();
    }

    void run() {
        String searchInput;
        boolean searchInputFind = false;
        // Search
        while(true){
            searchInput = scanner.nextLine();
            if(searchInput.equals("그만")){
                break;
            }

            for(int i = 0; i < phones.length; i++){
                if(searchInput.equals(phones[i].phoneName)) {
                    System.out.println(phones[i].phoneName + "의 번호는 " + phones[i].phoneNumber + " 입니다.");
                    searchInputFind = true;
                    break;
                }
            }

            if(!searchInputFind){
                System.out.println(searchInput + " 이 " + "없습니다.");
            }
        }
    }
}

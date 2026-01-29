import java.util.*;

public class test3{
    public static void main(String[] args) {
        ain(args);
    }

    public static void ain(String[] args){
        Scanner scanner = new Scanner(System.in);
        HashMap<String, CustomerManager> h1 = new HashMap<String, CustomerManager>();

        String userName;
        int userPoint;

        Vector<Integer> v = new Vector();

        while(true){
            userName = scanner.next();

            if(userName.equals("그만")) break;
            userPoint = scanner.nextInt();

            CustomerManager customer = h1.get(userName);
            if(customer == null) {
                h1.put(userName, new CustomerManager(userPoint));
            }
            else{
                customer.userPoint += userPoint;
            }

            for (String key: h1.keySet()){
                CustomerManager value = h1.get(key);
                System.out.print("(" + key + ", " + value.userPoint + ")");
            }
            System.out.println();

        }
        scanner.close();
    }
}
class CustomerManager{
    int userPoint;

    public CustomerManager(int userPoint){
        this.userPoint = userPoint;
    }
}

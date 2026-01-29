public class Main {
    public static void main(String[] args){
        System.out.println("2024-11-12, 학번:20117669, 이름:이창엽");

        int i, a[] = new int[5];
        int b[] = new int[5];

        for(i=0; i<5; i++){
            a[i] = (i+1) * 10;
            System.out.print(a[i] + " ");
        }
        
        b = a;
        System.out.print("\n배열 b : ");
        for(i=0; i<5; i++){
            System.out.print(b[i] + " ");
        }
        // int i, a[] = {10,20,30,40,50};
        // for(i=0; i<5; i++)
        // System.out.print(a[i] + " ");
    }
    
}

public class test1 {
    public static void main(String [] arg) {
        TV myTV = new TV("LG", 2017, 32);
        myTV.show();
    }
}
class TV{
    String nameTV;
    int yearTV;
    int inchTV;

    public void show(){
        System.out.println(nameTV + "에서 " + "만든 " + yearTV + "년형 " + inchTV + "인치 " + "TV");
        // LG에서 만든 2017년형 32인치 TV
    }
    public TV(String name, int year, int inch){
        this.nameTV = name;
        this.yearTV = year;
        this.inchTV = inch;
    }

}

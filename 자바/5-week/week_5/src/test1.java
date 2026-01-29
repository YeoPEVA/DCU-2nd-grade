public class test1 {
    public static void main(String[] args) {
        IPTV iptv = new IPTV("192.1.1.2", 32, 2048);
        iptv.printProperty();
    }
}
class TV {
    private int size;
    public TV(int size) {
        this.size = size;
    }
    protected int getSize() {
        return size;
    }
}
class ColorTV extends TV{
    private int tvColor;
    public ColorTV(int tvColor, int size){
        super(size);
        this.tvColor = tvColor;
    }

    protected int getColor(){
        return tvColor;
    }
}
class IPTV extends ColorTV{
    private String tvIp;
    public IPTV(String tvIp, int tvInch, int tvColor){
        super(tvColor, tvInch);
        this.tvIp = tvIp;
    }
    void printProperty(){
        System.out.println("나의 IPTV는 " + tvIp + " 주소의 " +  getSize() + "인치 " + getColor() + "컬러");
    }
}

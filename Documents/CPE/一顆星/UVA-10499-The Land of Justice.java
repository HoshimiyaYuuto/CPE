//球體表面積公式:4*PI*(r^2)，等分數n>2時會多出n*PI*(r^2)的表面積，故直接n/(4.0)*100%即為所求
//注意要用long
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        while(s.hasNextLong()){
            long n=s.nextLong();
            if(n<0) break;
            final double cost=4.0;
            long pro=(long) (n/cost*100);
            if(n==0 || n==1) pro=0;
            System.out.println(pro+"%");
        }
    }
}

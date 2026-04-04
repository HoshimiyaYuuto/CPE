//Kn(有n個node的完全圖)邊數為C(n,2)=n(n-1)/2, 每個MST需要(n-1)條邊，故所求為n/2 (此題有強調邊不能重複用且測資必為偶數)
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int Case=1;
        while(s.hasNextInt()){
            int n=s.nextInt();
            if(n==0) return;
            System.out.println("Case "+Case+": "+n/2);
            Case++;
        }
    }
}

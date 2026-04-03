//依題目規則將車牌前英文字母轉成數值，去跟後面數值比較差距，100內為nice，因車牌格式固定故好操作
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int N=s.nextInt();
        if(N==0) return;
        while(N-->0){
            String str=s.next();
            int cnt=0, num1=0, num2=0;
            for(char c:str.toCharArray()){  //!注意!:字元代號遍歷字串方法在java內要用str.toCharArray()
                if(cnt<3) {                 //前三碼為英文，後四碼為數字，以減號隔開(可直接忽略他)
                    num1=num1 * 26 + (c - 'A');
                }
                else if(cnt>3){
                    num2=num2*10+(c-'0');
                }
                cnt++;
            }
            if(Math.abs(num1-num2)<=100) System.out.println("nice");
            else System.out.println("not nice");
        }
    }
}
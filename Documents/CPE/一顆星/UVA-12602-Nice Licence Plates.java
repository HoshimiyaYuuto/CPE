import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int N=s.nextInt();
        if(N==0) return;
        while(N-->0){
            String str=s.next();
            int cnt=0, num1=0, num2=0;
            for(char c:str.toCharArray()){
                if(cnt<3) {
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
//找出每行測資的任兩元素能形成的最大GCD
//測資格式很髒要注意
import java.util.*;
public class Main {
    static int GCD(int a, int b){
        while (a%b!=0){
            int tmp=a;
            a=b;
            b=tmp%b;
        }
        return b;
    }
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        if(!s.hasNextInt()) return;
        int N= s.nextInt(); //測資數
        s.nextLine();
        while(N-->0){
            String line=s.nextLine();   //因為每行數字數量不固定，先用字串接收再分解
            String[] num=line.trim().split("\\s+"); //直接分割一行中用空格隔開的資料並存進字串陣列
            ArrayList<Integer> al=new ArrayList<Integer>();
            int maxGCD=0;
            for(String str:num) {
                al.add(Integer.parseInt(str));  //型別由字串轉成整數後存進ArrayList內
            }
            for(int i=0;i<al.size()-1;i++){
                for(int j=i+1;j<al.size();j++){
                    int curGCD=GCD(al.get(i), al.get(j));   //找GCD
                    if(curGCD>maxGCD) maxGCD=curGCD;        //更新最大GCD
                }
            }
            System.out.println(maxGCD);
        }
    }
}
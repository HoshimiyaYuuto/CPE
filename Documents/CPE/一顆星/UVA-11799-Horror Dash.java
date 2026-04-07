//對於每個數字集合，輸出最大值
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        if(!s.hasNextInt()) return;
        int T=s.nextInt();
        for(int t=1;t<=T;t++){
            int N=s.nextInt(), max=0;
            int[] nums=new int[N];
            for(int i=0;i<N;i++){
                nums[i]=s.nextInt();
                if(nums[i]>max) max=nums[i];
            }
            System.out.println("Case "+t+": "+max);
        }
    }
}
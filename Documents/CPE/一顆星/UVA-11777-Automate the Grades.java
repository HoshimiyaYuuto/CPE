//就照規則算總成績，前四項直接納入總成績，後三項捨去最低分除以二加進總成績，算完後輸出成績等第
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        if(!s.hasNextInt()) return;
        int T=s.nextInt();
        for(int t=1;t<=T;t++){
            int[] scores=new int[7];
            int total=0, min=4, ctScore=0;
            for(int i=0;i<7;i++){
                scores[i]=s.nextInt();
                if(i<4) total+=scores[i];
                else{
                    if(scores[i]<scores[min]) min=i;
                }
            }
            for(int i=4;i<7;i++){
                if(i!=min) ctScore+=scores[i];
            }
            total+=(ctScore/2);
            System.out.print("Case "+t+": ");
            if(total>=90) System.out.println("A");
            else if (total>=80) System.out.println("B");
            else if (total>=70) System.out.println("C");
            else if (total>=60) System.out.println("D");
            else System.out.println("F");
        }
    }
}
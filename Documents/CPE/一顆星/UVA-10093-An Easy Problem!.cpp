/*
數論通靈題，我信了他叫An Easy Problem! :(
觀察:題目要求確保R能被(N-1)整除，其中N為進制，R為一串以N進制組成的數字
要確保上述性質，需用到數論中的技巧:每個位數值的總和要能被(N-1)整除

!補充:若要求為確保R能被(N+1)整除，則奇數位之和與偶數位之和的差要能被(N+1)整除
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        long long l=0;  //使用long long避免overflow，用來算各個位數值的總和
        int maxv=1;     //找R的所有位數之中的最大值，而maxv+1為最小可能進制，最小進制從2進制開始，故初始化1
        for(char &c : str){ 
            int v=0;
            if(c>='0' && c<='9') v=c-'0';           //處理數字
            else if(c>='A' && c<='Z') v=c-'A'+10;   //處理大寫字母
            else if(c>='a' && c<='z') v=c-'a'+36;   //處理小寫字母
            l+=v;
            if(v>maxv) maxv=v;
        }
        bool find=false;
        for(int i=maxv+1;i<=62;i++){
            if(l%(i-1)==0){             //判斷各個位數值的總和能否被(N-1)整除，即判斷R能否被(N-1)整除
                cout << i << endl;      //輸出最小可能進制
                find=true;
                break;
            }
        }
        if(!find) cout << "such number is impossible!" << endl; //沒找到符合的進制就輸出
    }
}
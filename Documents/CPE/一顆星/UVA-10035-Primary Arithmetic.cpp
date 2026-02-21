//因為題目測資最大就十位數字，可以直接用long long解決，但若很大則需考慮使用string或vector解決
#include <iostream>
using namespace std;

int main(){
    long long n1, n2;
    while(cin >> n1 >> n2 && (n1 || n2)){   //!注意!:n1和n2都為0時才終止迴圈，其中一個是0還是要繼續跑
        int sum=0;      //進位次數
        bool car=false; //判斷有沒有進位
        while(n1 || n2){    //終止條件為n1和n2都變成0時
            int tmp1=n1%10, tmp2=n2%10;
            if(tmp1+tmp2+car>=10){  //處理加法，判斷有沒有進位
                sum++;
                car=true;
            }
            else car=false;
            n1/=10;     //處理下一個位數
            n2/=10;   
        }
        if(sum>=2) cout << sum << " carry operations."; //!注意!:進位大於2要加s
        else if(sum==1) cout << sum << " carry operation.";
        else cout << "No carry operation.";
        cout << endl;
    }
}
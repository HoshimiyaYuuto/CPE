//把每個位數加起來算出新的數，重複做直到該數只剩一位數
/*
ZJ上有神人提出只要考慮餘除9的值即可，思考如下:
數論中有:在K進制中，若要檢驗N是否為K-1的倍數只需將每個位數算總和判斷其是否為K-1的倍數
應用該定理於此題:十進制數字每位數只可能是0~9，其中正整數做完最後不可能會得到0
而每位數都能拆成Ki*1後面帶有非負整數個0，其中不管帶有幾個0，該位數餘除9必為K
算出這些Ki的總和仍為十進制之數，可以適用相同規則
故餘除9得到的值若非0即為所求，而若為0表示其是9的倍數，所求為9
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    //法1(字串迴圈法)
    string n;
    while(cin >> n && n!="0"){
        while(n.size()!=1){     //若還不是一位數就繼續做
            long long sum=0;
            for(char &c : n){   
                sum+=c-'0';     //算每個位數的總和
            }
            n=to_string(sum);   //再轉回字串繼續做
        }
        cout << n << endl;
    }
    
    //法2(神人數論法)
    /*
    long long n;
    while(cin >> n && n){
        n%=9;
        if(n) cout << n;
        else cout << '9';
        cout << endl;
    }
    */
}
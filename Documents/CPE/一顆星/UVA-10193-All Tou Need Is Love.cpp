//此題描述兩bit string S和L，要將S連續減掉L直到判斷能否運算出S==L
//目標找出對於S1和S2兩bit string，至少存在一種L，使得分別運算後能否得出S1==L和S2==L
//核心概念即為確認S1和S2是否互質(L必須至少有兩位元，即最小公倍數至少要為2)
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

//算GCD
long long GCD(long long a, long long b){
    while(a%b!=0){
        a%=b;
        swap(a,b);
    }
    return b; 
}

int main(){
    int N;  //測資數
    if(!(cin >> N)) return 0;
    cin.ignore();   //cin.ignore()去掉getline前的換行符號
    for(int i=1;i<=N;i++){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        cout << "Pair #" << i ;
        if(s1[0]=='0' || s2[0]=='0' || s1.size()<=1 || s2.size()<=1){   //排除不合法的S(雖然題目說測資會給合法的)
            cout << ": Love is not all you need!" << endl;
            continue;
        }
        //因為測資是給bit string，故先轉換成十進制方便處理
        bitset<30> b1(s1), b2(s2);
        long long d1=b1.to_ullong(), d2=b2.to_ullong(); //bitsetName.to_ullong()可將二進制轉成十進制
        //cerr << "d1:" << d1 << ' ' << "d2:" << d2 << endl;
        long long gcd=GCD(d1,d2);   //計算GCD
        if(gcd>=2) cout << ": All you need is love!";   //依據是否互質輸出結果
        else cout << ": Love is not all you need!";
        cout << endl;
    }
}
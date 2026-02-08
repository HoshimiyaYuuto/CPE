//此題要判斷一正整數是否為9的倍數，且要求出其之判斷層數
//判斷9的倍數->所有位數和為9的倍數，經過此檢驗方法一次即為一層
#include <iostream>
#include <string>
using namespace std;
//把所有位數相加，此函數被呼叫一次即為一層
void judge(string &num, int &cnt){
    long long tmp=0;    //預防overflow，不過題目說最大位數為1000，用int亦可(經過一層計算N會壓縮很多)
    for(char &c : num){
        tmp += (c-'0');
    }
    //cerr << "tmp:" << tmp << " ";
    num=to_string(tmp);
    //cerr << "num:" << num << " ";
    cnt++;
}

int main(){
    string N;   //測資input可能很大，用string先存
    while(getline(cin, N) && N!="0"){
        cout << N << ' ';
        int cnt=0;  //計算層數
        if(N == "9") cnt++;     //注意題目測資要求N==9時也算一層
        while(N.size()>1){  //重複呼叫位數相加直到N只剩一位數
            judge(N, cnt);
            //cerr << "N:" << N << endl;
        }
        
        int output=stoi(N); 
        if(output==9) cout << "is a multiple of 9 and has 9-degree " << cnt << '.';     //檢測是否為9的倍數
        else cout << "is not a multiple of 9.";
        cout << endl;
    }
}
//此題對對稱矩陣的定義很反常，不過可以存成一維陣列去檢查迴文
//且要留意所有entries皆不可為負數 <-被這坑到了
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int T;  //測資數
    if(!(cin >> T)) return 0;
    for(int i=1;i<=T;i++){
        int N;  //N*N的矩陣
        long long arr[10000];   //用long long存避免數值overflow
        bool sym=true;  //檢查對稱性
        string tmp;     //測資保持N = 數值，不能直接用cin
        cin.ignore();   //getline前面都有cin，要用cin.ignore去掉換行字元
        getline(cin, tmp);
        tmp.erase(0, 4);    //清掉"N = "的部分
        N=stoi(tmp);        //string to int
        //cerr << N;
        int size=pow(N,2);  //size=N*N
        for(int i=0;i<size;i++){
            cin >> arr[i];
        }
        for(int i=0;i<(size/2)+1;i++){
            if(arr[i]!=arr[size-1-i] || arr[i]<0 || arr[size-1-i]<0){   //排除非迴文與負數值
                sym=false;
                break;
            }
        }
        cout << "Test #" << i;
        if(sym) cout << ": Symmetric." << endl;
        else cout << ": Non-symmetric." << endl;
    }
}
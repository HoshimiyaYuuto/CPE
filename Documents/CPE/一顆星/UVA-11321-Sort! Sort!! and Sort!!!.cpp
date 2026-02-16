//難點在於看懂排序規則，看懂很好實作
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M;  //由於M必須給比較規則使用，故設成全域

//排序規則
bool cmp1(int a, int b){
    if(a%M==b%M){           //若兩數餘除M之值相等
        if((a+b)%2==1) return a%2==1;   //一奇一偶則奇數要在偶數前面
        else{
            if(a%2==1) return a>b;  //兩奇數則較大者在前
            else return a<b;    //兩偶數則較小者在前
        }
    } 
    else return a%M<b%M;    //餘除M之值由小到大
}

int main(){
    int N;
    while(cin >> N >> M && N!=0){
        cout << N << ' ' << M << endl;
        vector<int> v(N);   //將輸入元素存入vector中以便排序
        for(size_t i=0; i<v.size();i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp1); //排序
        for(size_t i=0;i<v.size();i++){
            cout << v[i] << endl;
        }
    }
    cout << "0 0";
}
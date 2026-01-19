#include <iostream>
#include <cmath>
using namespace std;

int fuc(int k){
    if(k==1) return 1;
    int cnt=0;
    while(k!=1){                        //規則
        cnt++;
        if(k%2==1) k=3*k+1;
        else k/=2;
    }
    return ++cnt;                       //1也要算成長度的一部份
}
int main(){
    int i, j;
    while(cin>>i>>j) {
        int len=0, tmp;
        cout << i << ' ' << j << ' ';   //先輸出原本i, j
        if(i>j) swap(i,j);              //小的換去i，大的換去j
        for(int k=i;k<=j;k++){
            //cerr << k << endl;        (除錯用)
            tmp=fuc(k);                 //找當下k的長度
            if(tmp>len) len=tmp;        //tmp存到比較大的就更新len
        }
        cout << len << endl;            //輸出最大長度
    }
}
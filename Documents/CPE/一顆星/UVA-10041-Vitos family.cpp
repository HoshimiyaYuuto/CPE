//此題即須在一個序列中找到一數使得其與所有序列中的數差值之和最小
//該數即為中位數
//若序列有偶數個數字亦無妨，選定的中位數只要在其兩中位數區間內結果皆為最小解
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int T;  //測資數
    if(!(cin >> T)) return 0;
    while(T--){
        int r, mid;
        long long dis=0;
        cin >> r;   //序列中各數字

        vector<int> v(r);
        for(size_t i=0;i<v.size();i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());   //排序以找中位數
        mid=v[(r-1)/2]; //我是找較小中位數，若寫v[r/2](較大中位數)亦可
        for(size_t i=0;i<v.size();i++){ //計算差值之和
            dis+=abs(mid-v[i]);
        }
        cout << dis << endl;
    }
}
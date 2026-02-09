//題目要求將N分別視為十進制和十六進制去轉成二進制，並分別算出其bit string中1的總數
//學習bitset的使用方法
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main(){
    int T;  //測資數
    if(!(cin >> T)) return 0;
    while(T--){
        int N, b1, b2, tmp=0;
        cin >> N;
        //處理X1:十進制轉成二進制
        bitset<16> X1(N);   //bitset<轉換二進制後的位數> bitsetName(數值(可放十進制整數(int, long long)或二進制字串))
        b1=X1.count();      //!技巧!:使用bitsetName.count()可直接計算出bit string中1的總數
        //處理X2:先十六進制轉成十進制
        for(int i=0;N>0;i++){
            tmp+=(N%10)*pow(16,i);  
            N/=10;
        }
        //cerr << "hex:" << tmp << ' '; 
        //處理X2:再十進制轉成二進制
        bitset<16> X2(tmp); 
        b2=X2.count();      //補充技巧:若要算bit string中0的總數-> 可用bitsetName.size() - bitsetName.count()求出
        cout << b1 << ' ' << b2 << endl;
    }
}
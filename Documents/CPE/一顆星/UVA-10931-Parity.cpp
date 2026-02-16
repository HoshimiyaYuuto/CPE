//題目即要輸出轉成二進制的bit string和1的總數
//原本想說能用bitset輕鬆搞定，但bitset的size必須是常數，故改用bool type的vector
#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned long long I;
    while(cin >> I && I!=0){
        vector<bool> v;
        cout << "The parity of ";
        int cnt=0;  
        while(I){
            if(I%2) cnt++;      //計算1的出現次數
            v.push_back(I%2);   //十進制轉二進制
            I/=2;
        }
        //注意此處i不能用size_t(long long unsigned int)，因為不管怎樣減都是正數，0繼續減會underflow成其能儲存的最大正數
        for(int i=v.size()-1;i>=0;i--){ 
            cout << v[i];
        }
        cout << " is " << cnt << " (mod 2)." << endl;
    } 
}
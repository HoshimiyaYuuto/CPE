//此題要判斷正整數是否為11的倍數->奇數位與偶數位的差值要是11的倍數
#include <iostream>
#include <string>
using namespace std;

int main(){
    string N;   //測資input可能很大，用string先存
    while(getline(cin, N) && N!="0"){
        cout << N << ' ';
        int odd=0, even=0, dif;
        for(size_t i=0;i<N.size();i++){ //分別算出奇數位和偶數位的和
            if(i%2==0) even+=N[i]-'0';
            else odd+=N[i]-'0';
        }
        dif=abs(even-odd);  //算出奇數位與偶數位的差值
        if(dif%11==0) cout << "is a multiple of 11.";   //檢測是否為11的倍數
        else cout << "is not a multiple of 11.";
        cout << endl;
    }
}
#include <iostream>
using namespace std;

//求GCD(最大公因數)，此處使用遞迴，亦可用迴圈實作
//此實作方式為輾轉相除法，complexity為O(log(min(a,b)))，非常有效率
long long GCD(int i, int j){
    int r=i%j;
    if(r==0) return j;
    return GCD(j, r);
}
int main(){
    int N;
    while(cin >> N && N!=0){    //while迴圈內為G的計算邏輯
        long long G=0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                G+=GCD(i, j);
            }
        }
        cout << G << endl;
    }
}
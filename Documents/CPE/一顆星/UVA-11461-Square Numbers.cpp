/*共有4種可能情況(T:是完全平方數, F:不是完全平方數)
1.a:T, b:T => 開更號取ceiling後，a平方是原區間第1個完全平方數，b平方是最後一個完全平方數，b-a須加回1
2.a:F, b:T => 同上
3.a:T, b:F => 開更號取ceiling後，a平方是原區間第1個完全平方數，b平方是原區間後第1個完全平方數，b-a不須加回1
4.a:F, b:F => 同上
*/
#include <iostream>
#include <cmath>
using namespace std;
//判斷區間終點是否為完全平方數
bool checkInt(double b) {
    if(b-(int)b==0) return true;    //若是，b當下應為整數
    return false;
}

int main() {
    double a, b;
    while(cin >> a >> b) {
        if(a==0 && b==0) break;
        a = sqrt((double)a);    //先開更號
        b = sqrt((double)b);
        bool cor=checkInt(b);   //判斷區間終點是否為完全平方數
        if(cor) {                                   
            cout << ceil(b)-ceil(a)+1 << endl;
        } 
        else {
            cout << ceil(b)-ceil(a) << endl;
        }    
    }
}
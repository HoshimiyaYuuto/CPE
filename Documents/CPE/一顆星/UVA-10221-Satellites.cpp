//這題也太狗，考數學和通靈不是考程式能力
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
    const int er=6440;  //地球半徑
    int s;  //離地表距離
    double a;   //角度
    string str; //判斷是度還是角分
    while(cin >> s >> a >> str){
        double ad=0, cd=0;
        s+=er;  //算總距離
        if(str=="min") a/=60;   //1度=60角分
        if(a>180) a=360-a;      //要算劣弧長(這題根本沒說，要自己通靈)
        a = (a/360) * 2 * acos(-1.0);   //度度轉弳度
        ad=abs(s*a);    //算弧長，ad=r*theta
        a/=2;
        cd=abs(2*s*sin(a)); //  算弦長
        cout << fixed << setprecision(6) << ad << ' ' << cd << endl;    //小數點後6位
    }
}
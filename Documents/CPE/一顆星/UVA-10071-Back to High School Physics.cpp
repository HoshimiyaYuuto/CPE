//ZJ上敘述錯誤，原題給定v,t，要求算出從靜止開始等加速移動的粒子經過2t後的S(位移)為多少，其中該粒子經過時間t後速度為v
//利用v-t圖的積分(音為等加速度運動，結果即為三角形公式)，(1/2)*(2t)*(2v)=2*v*t
#include <iostream>
using namespace std;

int main(){
    int v, t;
    while(cin >> v >> t){
        cout << 2*v*t << endl;
    }
}
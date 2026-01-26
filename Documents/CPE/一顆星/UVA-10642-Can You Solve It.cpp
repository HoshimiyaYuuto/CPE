/*
此題規則特別，我的解題思路如下:
先用三角形數公式分別對起終點算出包含該點那階的最大編號值(同階的點x座標值+y座標值相同)
接著扣掉它們個別的y座標值，可以得到他們點的實際編號(依規則可看出同階的點y愈大編號愈小)
最後終點編號-起點編號即為所求
*/
#include <iostream>
using namespace std;

struct cor {
    int x;
    int y;
};

int cnt_all(int x, int y){
    long long sum=x+y;
    return (sum+1)*(sum+2)/2;
}


int main(){
    int n;  //測資數
    if(!(cin >> n)) return 0;
    for(int i=1;i<=n;i++){
        cor ini, des;
        cin >> ini.x >> ini.y >> des.x >> des.y;    //起終點座標
        long long start=cnt_all(ini.x, ini.y), end=cnt_all(des.x, des.y);   //先對起終點分別算出其在的那階的最大編號
        start-=ini.y;   //算出起點編號
        end-=des.y;     //算出終點編號
        cout << "Case " << i << ": " << end-start << endl;  //相減即為所求
    }
}
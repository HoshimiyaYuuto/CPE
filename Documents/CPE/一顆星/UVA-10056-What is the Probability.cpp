//給定玩家數N,每回合玩家勝率p,玩家編號i，遊戲皆由玩家1輪向玩家N，若仍未分出勝負責繼續重複輪，要求出指定編號的玩家的總勝率
//利用無窮等比級數公式a/(1-r)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int S;  //測資數
    if(!(cin >> S)) return 0;
    while(S--){
        int N, i;   
        double p, a, r;
        cin >> N >> p >> i;
        a=pow(1-p,i-1)*p;   //a為前i-1輪玩家都失敗且第i輪玩家成功
        r=pow(1-p, N);      //經歷一個回合再輪到該指定玩家，故r為N輪玩家都失敗的機率
        cout << fixed << setprecision(4) << a/(1-r) << endl;    //要取小數點後四位
    }
}
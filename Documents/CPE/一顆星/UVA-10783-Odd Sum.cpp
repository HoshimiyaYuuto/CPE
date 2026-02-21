//給定一閉區間，求該區間內所有奇數的和
//因為沒有嚴格的時間限制，就用最簡單的方法了
#include <iostream>
using namespace std;

int main(){
    int T, a, b;
    if(!(cin >> T)) return 0;
    for(int c=1;c<=T;c++){  
        cin >> a >> b;
        long long sum=0;
        for(int i=a;i<=b;i++){  //遍歷區間數字，抓出奇數加進sum
            if(i%2) sum+=i;
        }
        cout << "Case " << c << ": " << sum << endl;
    }
}
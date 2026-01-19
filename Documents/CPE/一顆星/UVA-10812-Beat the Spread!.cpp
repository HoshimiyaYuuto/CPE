// x+y=s, x-y=d，設x是分數大的，y是分數小的
#include <iostream>
using namespace std;

int main() {
    int n, s, d;
    if(!(cin >> n)) return 0;
    while(n--){
        double x, y;
        cin >> s >> d;
        if(s<d) {                           //sum不可能比difference小
            cout << "impossible" << endl;
            continue;
        }

        x=(s+d)/2.0;                        //解聯立
        y=(s-d)/2.0;
        if(x!=(int)x || y!=(int)y) {        //分數一定得是非負整數，不能是帶有小數點的數
            cout << "impossible" << endl;
            continue;
        }
        else cout << x << ' ' << y << endl;
    }
}
//!!等待VJ復活才能提交:(
//題目給定數字0~9和大寫字母A~Z個別字元的印出費用，以及要印出的十進制query，判斷轉成哪個進制的印出費用總和最便宜
//此題judge系統輸出格式很刁鑽
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int c;  //case數
    if(!(cin >> c)) return 0;
    for(int i=1;i<=c;i++){
        if(c>1) cout << endl;   //此題最後不能多空行，要小心
        cout << "Case "<< i << ":" << endl;
        int qNum;   //query數
        vector<int> co(36);  //存各個字元的cost     
        for(size_t j=0;j<co.size();j++){
            cin >> co[j];
        }
        cin >> qNum;
        unsigned long long q;   //query
        for(int j=0;j<qNum;j++){
            long long min=999999999;    //記錄最小cost
            vector<int> cb; //記錄有最小cost的進制
            cin >> q;
            for(int b=2;b<=36;b++){
                unsigned long long tmp=q;
                long long cost=0;
                while(tmp){
                    cost+=co[tmp%b];    //計算各個字元的cost總和
                    tmp/=b;
                }
                //cerr << "current b:" << b << " cost:" << cost << " min:" << min << endl;
                if(min>cost){   //若有更小的cost，先清掉之前的所有最小cost進制紀錄，並更新最小cost與其進制
                    cb.clear();
                    min=cost;
                    cb.push_back(b);    
                }    
                else if(min==cost) cb.push_back(b); //若同為最小cost的進制就存起來
            }
            cout << "Cheapest base(s) for number " << q << ":";
            for(size_t k=0;k<cb.size();k++){
                cout << ' ' << cb[k];   //輸出所有最小cost的進制
            } 
            cout << endl;
        }               
    }
}
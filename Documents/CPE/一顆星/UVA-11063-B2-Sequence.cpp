//檢測給定的數列是否符合1<=b1<b2<...<bN && bi+bj(i<=j)不重複
//此題邊界情況很多，要注意
#include <iostream>
#include <vector>
#include <set> 
#include <algorithm>
using namespace std;

int main(){
    int N, c=1;
    while(cin >> N){
        if(c>1) cout << endl << endl;   //題目奇怪的輸出要求
        vector<int> v(N);   //存數列
        set<int> s;         //存bi+bj，因要去重所以採用set
        bool halt=false;    //判斷是否違反邊界情況要終止迴圈
        //cerr << s.size() << endl;
        for(size_t i=0;i<v.size();i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());   //先排序
        if(v[0]<1) halt=true;       //排除b1<0
        for(size_t i=0;i<v.size();i++){ //!注意!:i可以等於j
            for(size_t j=i;j<v.size();j++){
                if(v[i]==v[j] && i!=j){ //排除bi==bj && i!=j
                    halt=true;
                    break;
                }
                s.insert(v[i]+v[j]);    //丟進set內用insert
            }
            if(halt) break;
        }
        /*
        cerr << s.size() << ' ' << halt << endl;    
        for(auto const &num : s){   //輸出set內元素用冒號迴圈去遍歷
            cerr << num << ' ';
        }
        */
       //set最後的size應為C(N, 2)+N = (N(N-1)/2)+N = N(N+1)/2
        cout << "Case #" << c++;    
        if(s.size()==N*(N+1)/2 && !halt) cout << ": It is a B2-Sequence.";
        else cout << ": It is not a B2-Sequence.";
    }
}
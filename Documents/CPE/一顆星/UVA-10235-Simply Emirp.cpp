//此題要判斷數字和其前後反轉分別是否為質數
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//判斷質數
bool isPr(long long num){
    for(long long i=2;i<num/2;i++){
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    long long num;
    while(cin >> num){
        bool em=false, pr=isPr(num);
        cout << num << " is ";
        if(pr){
            vector<int> v;
            long long numtmp=num, tmp=0;
            while(numtmp){                      //先存進vector
                v.push_back(numtmp%10);
                numtmp/=10;
            }
            for(size_t i=0;i<v.size();i++){     //做前後反轉
                tmp+=v[v.size()-1-i]*pow(10,i);
            }
            //cerr << tmp << endl;
            if(isPr(tmp) && num!=tmp) em=true;  //emirp的必要條件:要是質數且反轉後與原數不同
        }
        if(pr){
            if(em) cout << "emirp.";
            else cout << "prime.";
        }
        else cout << "not prime.";
        cout << endl;
    }
}
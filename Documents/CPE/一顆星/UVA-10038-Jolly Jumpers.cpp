#include <iostream>
#include <vector>
using namespace std;

int main(){
    int len;    //單行有的數字量
    while(cin >> len){
        vector<int> v1, v2(len);    //v1存數字, v2存相鄰絕對差值是否出現過
        bool jolly=true;    //檢查是否為jolly
        int tmp;
        for(int i=0;i<len;i++){
            cin >> tmp;
            v1.push_back(tmp);
        }
        for(size_t i=0;i<len-1;i++){
            size_t num=abs(v1[i+1]-v1[i]);  
            if(num>=len) continue;      //注意若超過v2的size會越界存取，須排除
            v2[num]=true;
        }
        for(size_t i=1;i<len;i++){
            if(!v2[i]) jolly=false;     //在1~len-1中只要有沒出現過的就代表非jolly
        }
        if(jolly) cout << "Jolly";
        else cout << "Not jolly";
        cout << endl;
    }
}
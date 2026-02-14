//找出字串中各個字元的出現次數
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//排序規則，由次數小到大輸出，若次數相同則ASCII值較大先輸出
bool cmp(pair<int ,int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first > b.first;
}
int main(){
    string str;  
    while(getline(cin, str)){
        map<int, int> m;    
        for(char &c : str){ //記錄出現次數
            m[(int)c]+=1;
        }

        vector<pair<int, int>> v(m.begin(), m.end());   //把map轉成vector以做排序
        sort(v.begin() ,v.end(), cmp);      //排序
        for(auto const &[key, value] : v){  //輸出
            cout << key << ' ' << value << endl;
        }
        cout << endl;
    }
}
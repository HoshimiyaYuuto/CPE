//跟STL相關，遍歷容器內的元素->for(const auto &作用變數名 : 容器名)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){     //排序原則，注意:map的key是.first, value是.second，若學會lambda能用其代替
    if(a.second != b.second) return a.second > b.second;    //次數不同，次數較大的在前面
    return a.first < b.first;   //次數相同，字元較小的在前面
}

int main(){
    int n;
    string tmp;
    map<char, int> m;
    if(!(cin >> n)) return 0;   //輸入行數
    cin.ignore();   //cin不會吃掉換行符號，要補cin.ignore()避免getline有問題
    while(n--){
        getline(cin, tmp);
        for(char &c : tmp){     //對於所有在tmp內的字元c(!!記得要加 & !!)
            c=toupper(c);       //轉大寫(注意: C++:c=toupper(c) (for char) / Python:c=c.upper() (for string))
            if(isalpha(c)) m[c]++;  //是字母就更新map
        }    
    }
    vector<pair<char, int>> v(m.begin(), m.end());  //把map塞進vector->用vector<pair<type 1, type 2>> vectorName(mapName.begin(), mapName.end());
    sort(v.begin(), v.end(), cmp); //排序
    for(const auto  &[al, num] : v){     //遍歷跟map有關的key,val->for(const auto) &[key, val] : mapName) (mapName亦可替換成塞了map的vectorName)
        cout << al << ' ' << num << endl; 
    }
}
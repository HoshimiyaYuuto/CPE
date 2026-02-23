//在同一行測資中給定國家名和一個人名(同名為同一人)，依字母順序輸出每個國家的人數
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    map<string, vector<string>> m;
    if(!(cin >> n)) return 0;
    while(n--){
        string coun, name;
        bool find=false;
        cin >> coun;    //先用cin讀國家名，接著cin.ignore去掉空行，再用getline讀人名
        cin.ignore();
        getline(cin, name);
        for(auto const &c:m[coun]){ //遍歷國家對應的人名列表中有沒有出現過該名字
            if(c==name) find=true;
        }
        if(!find) m[coun].push_back(name);  //沒出現過就加進該國家的人名列表中
    }
    for(auto const &[key, val]:m){
        cout << key << ' ' << val.size() << endl;   //人名列表的長度即為該國家的總人數
    }
}
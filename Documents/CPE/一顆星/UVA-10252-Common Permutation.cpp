//找兩個字串中的共同字母，並依字母順序輸出
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string w1, w2;
    while(getline(cin, w1)){
        getline(cin, w2);
        map<char, int> m;
        vector<char> v;
        for(char &c : w1){  //先把字串1的字母和其次數存進map
            m[c]++;
        }
        for(char &c : w2){  //遍歷字串2的字母，若在map內且次數大於0就存進vector內，並將該字母在map中的次數減1
            if(m.find(c)!=m.end() && m.find(c)->second>0){  //mapName.find(key)回傳值是迭代器(指向該[key, value]對的位址)，若沒找到會回傳mapName.end()
                v.push_back(c);                             //若mapName.find(key)有成功，mapName.find(key)->first為key，mapName.find(key)->second為value
                m[c]--;
            }
        }
        sort(v.begin(), v.end());   //由於兩字串皆為小寫字母組成，可用ASCII碼排序
        for(char &c : v){
            cout << c;
        }
        cout << endl;
    }
}
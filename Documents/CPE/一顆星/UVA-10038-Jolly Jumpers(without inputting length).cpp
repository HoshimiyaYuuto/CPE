//stringstream型別可以方便將一組數字組成的字串轉成數字存進vector或其他容器
//因為沒看到input格式寫出來的
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        stringstream ss(str);   //把一組數字的字串存成stringstream的型別
        int tmp;
        vector<int> v1;     //v1存數字
        bool jolly=true;    //檢查是否為jolly

        while(ss >> tmp){       //>>或<<可以形成資料流向會比較好記，stringstream會讀取原字串直到空格(不包含空格)，且會自動轉成target的type，非常方便
            v1.push_back(tmp);
        }
        vector<bool> v2((int)v1.size());    //v2存相鄰絕對差值是否出現過
        //cerr << v1.size() << "yes" << endl;
        //for(auto &c : v1){
            //cerr << c << ' ';
        //}
        for(size_t i=0;i<v1.size()-1;i++){
            size_t num=abs(v1[i+1]-v1[i]);
            if(num>=v2.size()) continue;    //注意若超過v2的size會越界存取，須排除
            v2[num]=true;
            //cerr << num << ' ';   //當初檢查哪邊越界存取用的
        }
        //for(const auto &c : v2){  
            //cerr << c << ' ';
        //};
        for(size_t i=1;i<v2.size();i++){    
            if(!v2[i]) jolly=false;         //在1~len-1中只要有沒出現過的就代表非jolly
        }
        if(jolly) cout << "Jolly";
        else cout << "Not jolly";
        cout << endl;
        ss.str(""); //用完stringstream記得要用.str("")和.clear()清空，存下組資料才不會受到未知的影響
        ss.clear();
    }   
}
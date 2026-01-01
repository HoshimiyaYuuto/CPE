//弱方法:用struct+vector+sort處理，時間複雜度O(n log n)(排序提高複雜度)
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//樹的資料
struct tree {
    string tName;
    int times;
};

//sort 用比較規則(true:a在b前面，false則反之)
bool cmp(tree &a, tree &b) {
    if(a.tName < b.tName) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(2);  //因為要處理掉多的換行
    while(n--) {
        vector<tree> nameV;
        int cnt=0;
        tree temp;
        string name;
        while(getline(cin, name)) {     //讀取每行樹名稱，若為空(換行,EOF)則終止迴圈
            if(name.empty()) break;
            bool find=false;            //看是否存在於vector nameV中 
            cnt++;                      //計算讀取樹的數量
            for(size_t i=0; i<nameV.size(); i++) {
                if(name == nameV[i].tName) {
                    nameV[i].times++;   //有找到:次數++
                    find=true;
                    break;
                }
            }
            if(!find) {                 //沒找到:存進vector nameV中
                temp.tName=name;
                temp.times=1;
                nameV.push_back(temp);
            }
        }
        sort(nameV.begin(), nameV.end(), cmp);  //排序
        for(size_t i=0; i<nameV.size(); i++) {  //輸出
            cout << nameV[i].tName << ' ';
            cout << fixed << setprecision(4) << ((double)nameV[i].times/cnt)*100 << endl;
        }
        cout << endl;
    }
}
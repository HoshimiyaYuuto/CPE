//強方法:用map處理，時間複雜度O(n log m) m:樹的種類數 -> 快於n log n
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);   //加速C++的I/O
    cin.tie(NULL);

    int n;
    if(!(cin >> n)) return 0;
    cin.ignore(2);                      //因為要處理掉多的換行

    while(n--) {
        map<string, int> treeMap;       //map<key型別, value型別>類似python中的dict，適合用在此題
        int cnt=0;                      //計算輸入樹的數量
        string name;
        while(getline(cin, name) && !name.empty()) {
            treeMap[name]++;            //map比python中dict更強大，map變數[key型別之變數]可直接處理兩情況: 1.map的key中沒name->直接加進map且次數預設0，且因++所以變成1 2.map的key中有name->次數++
            cnt++;   
        }    
        for(auto const& [name, count] : treeMap) {  //檢查所有在treeMap中的[name, count]組合(auto const& [key, value] : map變數)
            cout << name << ' '
                 << fixed << setprecision(4) << ((double)count/cnt)*100 << endl;
        }
        cout << endl;
    }
}
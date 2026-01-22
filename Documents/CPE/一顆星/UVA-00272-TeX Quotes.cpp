//把上雙引號換成``，下雙引號換成''
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int cnt=0;
    while(getline(cin, str)) {
        for(char &c : str){                     //遍歷字串
            if(c == '"') {
                if((++cnt)%2==1) cout << "``";  //把上雙引號換成``
                else cout << "''";              //把下雙引號換成''
            }
            else cout << c;                     //其他正常輸出
        }
        cout << endl;
    }
}   
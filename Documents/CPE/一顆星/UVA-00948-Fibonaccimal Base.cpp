//把數字轉成費波納契表示法
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;  //測資數
    if(!(cin >> N)) return 0;
    while(N--){
        int num, tmp=2, i=1;
        cin >> num;
        cout << num << " = ";

        vector<int> fib={1,2};  
        while(tmp<num){             //建費波納契數表
            tmp=fib[i]+fib[i-1];
            //cerr << tmp << endl;
            fib.push_back(tmp);
            i++;
        }
        while(fib[i]>num) i--;      //找不大於輸入數字之最大費波納契數
        //cerr << fib[i] << endl;

        while(i>=0){                //轉成費波納契表示法
            //cerr << num <<"t\n";
            if(fib[i]>num) {
                cout << '0';
            }
            else{
                cout << '1';
                num-=fib[i];
                //cerr << num << endl;
            }
            i--;
        }
        cout << " (fib)" << endl;
    }
}
//此題的n是m的某次方要輸出期不斷除以m之值直到1，若為其他情況則為Boring!
//注意測資給定之n和m之值很大，需要用到long long避免overflow
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, m;
    while(cin >> n >> m){
        vector<int> v;
        bool bor=!n || !m;  //檢測Boring!，題目說n,m為非負整數，故只要其中一個為0則為Boring!
        while(n>=1 && !bor){    
            v.push_back(n); //將整個過程的值存進vector內
            if(n%m!=0 && n!=1){ //檢測是否符合規則，注意n==1時的狀況不能觸發boring
                bor=true;
                break;
            }
            n/=m;
        }
        if(bor) cout << "Boring!";
        else{ 
            for(size_t i=0;i<v.size();i++) {    
                cout << v[i] << ' ';
            }    
        }
        cout  << endl;
    }
}
//題目給定第一日的入住旅行團人數S，要求第D日查房之時旅行團為多少人
//旅行團入住時間彼此不重疊，每次入住的旅行團人數都會比前一次旅行團多一人
#include <iostream>
using namespace std;

int main(){
    long long S, D;
    while(cin >> S >> D){
        long long sum=0;
        while(sum<D) sum+=(S++);    //不斷累加旅行團人數直到D日
        cout << S-1 << endl;        //因為達到D時S又被多++一次，要再扣回來
    }
}
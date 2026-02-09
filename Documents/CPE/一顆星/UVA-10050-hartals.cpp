//此題目的意思是要找給定P個數字，它們的值在N內卡位的總數，要排除特定性質的數字
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;  //測資數
    if(!(cin >> T)) return 0;
    while(T--){
        int N, P; //天數, 政黨數
        cin >> N;
        vector<bool> vec(N);   //bool type的vector內所有值會初始化成false

        cin >> P;
        while(P--){
            int h;  //參數，它們的倍數會卡位
            cin >> h;
            for(size_t i=h-1; i<vec.size();i+=h){
                vec[i]=true;    //卡位到就改成true
            }
        }

        int cnt=0;
        for(size_t i=0;i<vec.size();i++){
            if(((i+1)%7 != 0) && ((i+1)%7 != 6) && vec[i]){ //排除週五和週六
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
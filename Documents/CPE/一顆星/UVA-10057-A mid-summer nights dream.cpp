//這題除了要知道A*=arg min(sum(|Xi-A|))的A*要是中位數外還要通靈題目對於每個輸出是在問什麼(如果是看ZJ敘述的話，如果看原文則只需要知道前面所述之性質)
//留意偶數元素數列有兩個中位數，在此兩數之閉區間內所有數皆符合A*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);   //存數列
        long long A, dif=0, p;  
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());    //排序
        A=v[(n-1)/2];       //找最小中位數(The minimum value of A)
        for(size_t i=0;i<v.size();i++){ 
            if(v[i]>=A && v[i]<=v[n/2]) dif++;  //找在數列中又在中位數閉區間內的數字總數量(How many of the given numbers Xi can be A to make sum sum(|Xi-A|) minimum.)
        }
        p=v[n/2]-A+1;       //找A的可能性數量，即在中位數閉區間內的所有數數量(How many possible integer values of A are there?)
        cout << A << ' ' << dif << ' ' << p << endl;
    }
}
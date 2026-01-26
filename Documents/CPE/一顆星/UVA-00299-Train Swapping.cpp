//題目有規定是兩相鄰車廂的最小交換次數，即為Bubble Sort的概念
#include <iostream>
using namespace std;

int main(){
    int N;  //測資數
    if(!(cin >> N)) return 0;
    while(N--){
        int L, cnt=0;   //元素個數, 交換次數
        int arr[50];
        cin >> L;
        for(int i=0;i<L;i++){
            cin >> arr[i];
        }
        for(int i=0;i<L-1;i++){             //Bubble Sort
            for(int j=0;j<L-i-1;j++){
                if(arr[j]>arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
    }
}
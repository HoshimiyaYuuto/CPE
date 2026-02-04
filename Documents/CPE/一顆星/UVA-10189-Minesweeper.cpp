//使用二維vector: vector<vector <type>> vectorName(rowNum, vector<type>(colNum))
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n, round=1;  //此題n是row, m是column, round表當下回合
    while(cin >> n >> m && n!=0){
        vector<vector<char>> map(n, vector<char>(m));   //存input
        vector<vector<char>> output(n, vector<char>(m, '0'));   //存output，一開始先初始化為0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='*') {    //特別挑出地雷位置
                    output[i][j]='*';   
                    for(int k=-1;k<=1;k++){     //計算地雷四面八方的數字
                        for(int l=-1;l<=1;l++){
                            if(i+k>=n || j+l>=m || i+k<0 || j+l<0) continue;    //檢查邊界
                            if(output[i+k][j+l]=='*') continue; //檢查是否為地雷
                            else output[i+k][j+l]++;    //符合規定就++
                        }
                    }
                }    
            }
        }
        cout << "Field #" << round << ':' << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << output[i][j];
            }
            cout << endl;
        }
        round++;
    }
}
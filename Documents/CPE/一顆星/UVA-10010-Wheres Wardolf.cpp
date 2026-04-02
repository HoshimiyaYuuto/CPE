#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int ca;
    if(!(cin >> ca)) return 0;
    const int dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
    while(ca--){
        int m, n;
        cin >> m >> n;
        vector<vector<char>> ch(m, vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char tmp;
                cin >> tmp;
                ch[i][j]=tolower(tmp);
            }
        }

        int words;
        cin >> words;
        while(words--){
            string str;
            int ansR, ansC, find=-1;
            cin >>  str;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(ch[i][j]==tolower(str[0])){
                        int curR=i, curC=j;
                        for(int k=0;k<8;k++){  
                            for(size_t l=1;l<str.size();l++){
                                curR+=dx[k];
                                curC+=dy[k];
                                if(curR<0 || curR>m-1 || curC<0 || curC>n-1 || ch[curR][curC]!=tolower(str[l])){
                                    find=0;
                                    break;
                                }
                                else find=1;
                            }
                            if(find==1){
                                ansR=i;
                                ansC=j;
                                break;
                            } 
                        }
                        
                    }
                    if(find==1) break;
                }
                if(find==1) break;
            }
            cout << ansR << ' ' << ansC << endl;
        } 
    }
}
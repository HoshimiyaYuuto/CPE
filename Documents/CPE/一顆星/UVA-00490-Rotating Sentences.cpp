//注意此題非常吃輸出格式，將文章轉90度
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int i,max=0;
    char str[101][101]={'\0'};  //最大限制100*100，用來存整篇文章，先初始化為空
    for(i=0;i<101;i++){
        cin.getline(str[i],100);
        if(strlen(str[i]) == 0) break;  //讀到全空行就停止讀取
        else if(max<strlen(str[i])) max=strlen(str[i]); //計算單行最大字元數，避免輸出太多' '被判定成OLE
        //cerr << i <<endl;
    }

    for(int j=0;j<max;j++){
        for(int k=i-1;k>=0;k--){
            if(!(str[k][j])) cout << ' ';   //!重要!:沒任何字符要輸出空白(因為每行長度參差不齊)
            else cout << str[k][j];
        }
        cout << endl;
    }
}

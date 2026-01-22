#include <iostream>
#include <string>
using namespace std;

//東變原頂，頂變原西，西變原底，底變原東
void east(int d[]){                             
    int tmp=d[2];
    d[2]=d[0];
    d[0]=d[3];
    d[3]=d[1];
    d[1]=tmp;
}

//西變原頂，頂變原東，東變原底，底變原西
void west(int d[]){
    int tmp=d[3];
    d[3]=d[0];
    d[0]=d[2];
    d[2]=d[1];
    d[1]=tmp;
}

//南變原頂，頂變原北，北變原底，底變原南
void south(int d[]){
    int tmp=d[4];
    d[4]=d[0];
    d[0]=d[5];
    d[5]=d[1];
    d[1]=tmp;
}

//北變原頂，頂變原南，南變原底，底變原北
void north(int d[]){
    int tmp=d[5];
    d[5]=d[0];
    d[0]=d[4];
    d[4]=d[1];
    d[1]=tmp;
}

int main(){
    int n;
    while(cin >> n && n!=0){
        int die[6]={1,6,4,3,5,2};               //索引0~5依序為:頂,底,東,西,南,北
        string str;                             //指令
        while(n--){
            cin >> str;
            if(str == "east") east(die);
            else if(str == "west") west(die);
            else if(str == "south") south (die);
            else north(die);
        }
        cout << die[0] << endl;                 //輸出頂
    }
}